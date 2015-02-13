/* 
 * File:   main.c
 * Author: ivo
 *
 * Created on January 27, 2015, 3:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataManagement.h"
#include "utilizador.h"
#include "tipo_utilizador.h"
#include "cliente.h"
#include "unidade.h"
#include "ingrediente.h"
#include "produto_final.h"
#include "linha_produto_final.h"
#include "encomenda.h"
#include "linha_encomenda.h"
#include "producao.h"
#include "classes.h"

#include <time.h>

/*
 * 
 */
int main(int argc, char** argv) {

    //---------------------------------------------------------------------------------------------------------//

    unsigned short contadorTipoUtilizadores = 0, contadorUtilizadores = 0, contadorClientes = 0, contadorUnidades = 0, contadorIngredientes = 0, contadorProdutosFinais = 0, contadorLinhasProdutoFinal = 0, contadorEncomenda = 0, contadorLinhasEncomenda = 0, contadorProducao = 0;
    char NomeFicheiro[SHORT_STRING];

    //---------------------------------------------------------------------------------------------------------//
    //Tipo de Utilizadores

    const unsigned short MAX_TIPO_UTILIZADORES = 10;

    FieldAux estructAuxTipoUtilizadores[] = {
        {.fieldName = "id_tipo_utilizador", .alias = "Numero Tipo Utilizador", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "descricao", .alias = "Descricao", .sizeBytes = SHORT_STRING, .type = STRING}
    };

    TipoUtilizador tipoUtilizadores[MAX_TIPO_UTILIZADORES];
    const unsigned int tamAuxTipoUtilizador = (sizeof (estructAuxTipoUtilizadores) / sizeof (estructAuxTipoUtilizadores[0]));
    const unsigned int tamTipoTipoUtilizador = sizeof (TipoUtilizador);

    Class tipoUtilizadorClass = {.name = "Tipo Utilizador", .fileName = "tipoUtilizadores.txt", .primaryKeyField = ID_TIPO_UTILIZADOR, .StructTypeSize = tamTipoTipoUtilizador, .data = &tipoUtilizadores, .auxStruct = &estructAuxTipoUtilizadores, .elements = &contadorTipoUtilizadores, .fieldsNumber = tamAuxTipoUtilizador, .aliasField = DESCRICAO_TIPO_UTILIZADOR};

    strcpy(NomeFicheiro, "tipoUtilizadores.txt");
    readFile(NomeFicheiro, &tipoUtilizadorClass, MAX_TIPO_UTILIZADORES);

    //---------------------------------------------------------------------------------------------------------//
    //Utilizadores

    const unsigned short MAX_UTILIZADORES = 10;

    FieldAux estructAuxUtilizadores[] = {
        {.fieldName = "id_utilizador", .alias = "Numero Utilizador", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_tipo_utilizador", .alias = "Tipo de Utilizador", .sizeBytes = SHORT_SIZE, .type = SHORT, .required = true, .unique = false, .foreignKey = true, .parentPrimaryKey = ID_TIPO_UTILIZADOR, .parentClass = &tipoUtilizadorClass},
        {.fieldName = "username", .alias = "Username", . sizeBytes = SHORT_STRING, .type = STRING, .required = true},
        {.fieldName = "password", .alias = "Password", . sizeBytes = SHORT_STRING, .type = STRING, .required = true}
    };

    Utilizador utilizadores[MAX_UTILIZADORES];
    const unsigned int tamAuxUtilizador = (sizeof (estructAuxUtilizadores) / sizeof (estructAuxUtilizadores[0]));
    const unsigned int tamTipoUtilizador = sizeof (Utilizador);

    Class utilizadorClass = {.name = "Utilizador", .fileName = "utilizadores.txt", .StructTypeSize = tamTipoUtilizador, .data = &utilizadores, .auxStruct = &estructAuxUtilizadores, .elements = &contadorUtilizadores, .fieldsNumber = tamAuxUtilizador, .aliasField = USERNAME};

    strcpy(NomeFicheiro, "utilizadores.txt");
    readFile(NomeFicheiro, &utilizadorClass, MAX_UTILIZADORES);

    //---------------------------------------------------------------------------------------------------------//
    //Clientes

    const unsigned short MAX_CLIENTES = 10;

    FieldAux estructAuxClientes[] = {
        {.fieldName = "id_cliente", .alias = "Numero de Cliente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "nome", .alias = "Nome", . sizeBytes = MEDIUM_STRING, .type = STRING, .required = true},
        {.fieldName = "id_utilizador", .alias = "Numero de Utilizador", .sizeBytes = SHORT_SIZE, .type = SHORT, .required = true, .unique = true, .foreignKey = true, .parentPrimaryKey = ID_UTILIZADOR, .parentClass = &utilizadorClass}
    };

    Cliente clientes[MAX_CLIENTES];
    const unsigned int tamAuxCliente = (sizeof (estructAuxClientes) / sizeof (estructAuxClientes[0]));
    const unsigned int tamTipoCliente = sizeof (Cliente);

    Class clienteClass = {.name = "cliente", .StructTypeSize = tamTipoCliente, .data = &clientes, .auxStruct = &estructAuxClientes, .elements = &contadorClientes, .fieldsNumber = tamAuxCliente, .aliasField = NOME};

    strcpy(NomeFicheiro, "cliente.txt");
    readFile(NomeFicheiro, &clienteClass, MAX_CLIENTES);

    //---------------------------------------------------------------------------------------------------------//
    //Unidades

    const unsigned MAX_UNIDADES = 10;

    FieldAux estructAuxUnidades[] = {
        {.fieldName = "id_unidade", .alias = "Numero de Unidade", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "designacao_unidade", .alias = "Unidade", .sizeBytes = SHORT_STRING, .type = STRING, .unique = true, .required = true}
    };

    Unidade unidades[MAX_UNIDADES];
    const unsigned int tamAuxUnidade = (sizeof (estructAuxUnidades) / sizeof (estructAuxUnidades[0]));
    const unsigned int tamTipoUnidade = sizeof (Unidade);

    Class unidadeClass = {.name = "Unidade", .fileName = "unidade.txt", .StructTypeSize = tamTipoUnidade, .data = &unidades, .auxStruct = &estructAuxUnidades, .elements = &contadorUnidades, .fieldsNumber = tamAuxUnidade, .aliasField = DESCRICAO_UNIDADE};

    strcpy(NomeFicheiro, "unidade.txt");
    readFile(NomeFicheiro, &unidadeClass, MAX_UNIDADES);

    //---------------------------------------------------------------------------------------------------------//
    //Ingredientes

    const unsigned MAX_INGREDIENTES = 20;

    FieldAux estructAuxIngredientes[] = {
        {.fieldName = "id_ingrediente", .alias = "Numero de Ingrediente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "designacao_ingrediente", .alias = "Ingrediente", .sizeBytes = SHORT_STRING, .type = STRING, .unique = true, .required = true}
    };

    Ingrediente ingredientes[MAX_INGREDIENTES];
    const unsigned int tamAuxIngrediente = (sizeof (estructAuxIngredientes) / sizeof (estructAuxIngredientes[0]));
    const unsigned int tamTipoIngrediente = sizeof (Ingrediente);

    Class ingredienteClass = {.name = "Ingrediente", .fileName = "ingrediente.txt", .StructTypeSize = tamTipoIngrediente, .data = &ingredientes, .auxStruct = &estructAuxIngredientes, .elements = &contadorIngredientes, .fieldsNumber = tamAuxIngrediente, .aliasField = DESCRICAO_INGREDIENTE};

    strcpy(NomeFicheiro, "ingrediente.txt");
    readFile(NomeFicheiro, &ingredienteClass, MAX_INGREDIENTES);

    //---------------------------------------------------------------------------------------------------------//
    //ProdutoFinal

    const unsigned MAX_PRODUTO_FINAL = 10;

    FieldAux estructAuxProdutoFinal[] = {
        {.fieldName = "id_produto_final", .alias = "Numero de Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "designacao_produto_final", .alias = "Produto Final", .sizeBytes = MEDIUM_STRING, .type = STRING, .unique = true, .required = true}
    };

    ProdutoFinal produtosFinais[MAX_PRODUTO_FINAL];
    const unsigned int tamAuxProdutoFinal = (sizeof (estructAuxProdutoFinal) / sizeof (estructAuxProdutoFinal[0]));
    const unsigned int tamTipoProdutoFinal = sizeof (ProdutoFinal);

    Class produtoFinalClass = {.name = "Produto Final", .fileName = "produtoFinal.txt", .StructTypeSize = tamTipoProdutoFinal, .data = &produtosFinais, .auxStruct = &estructAuxProdutoFinal, .elements = &contadorProdutosFinais, .fieldsNumber = tamAuxProdutoFinal, .aliasField = DESCRICAO_PRODUTO_FINAL};

    strcpy(NomeFicheiro, "produtoFinal.txt");
    readFile(NomeFicheiro, &produtoFinalClass, MAX_PRODUTO_FINAL);

    //---------------------------------------------------------------------------------------------------------//
    //Linha do Produto Final

    const unsigned MAX_LINHA_PRODUTO_FINAL = 10;

    FieldAux estructAuxLinhaProdutoFinal[] = {
        {.fieldName = "id_linha_produto_final", .alias = "Numero da Linha do Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_produto_final", .alias = "Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .foreignKey = true, .parentClass = &produtoFinalClass, .parentPrimaryKey = ID_PRODUTO_FINAL},
        {.fieldName = "id_ingrediente", .alias = "Ingrediente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &ingredienteClass, .parentPrimaryKey = ID_INGREDIENTE},
        {.fieldName = "id_unidade", .alias = "Unidade", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &unidadeClass, .parentPrimaryKey = ID_UNIDADE},
        {.fieldName = "quantidade", .alias = "Quantidade", .sizeBytes = FLOAT_SIZE, .type = FLOAT, .unique = false, .required = true, .autoIncrement = false},

    };

    LinhaProdutoFinal linhasProdutoFinal[MAX_LINHA_PRODUTO_FINAL];
    const unsigned int tamAuxLinhaProdutoFinal = (sizeof (estructAuxLinhaProdutoFinal) / sizeof (estructAuxLinhaProdutoFinal[0]));
    const unsigned int tamTipoLinhaProdutoFinal = sizeof (ProdutoFinal);

    Class linhaProdutoFinalClass = {.name = "Linha Produto Final", .fileName = "linhaProdutoFinal.txt", .StructTypeSize = tamTipoLinhaProdutoFinal, .data = &linhasProdutoFinal, .auxStruct = &estructAuxLinhaProdutoFinal, .elements = &contadorLinhasProdutoFinal, .fieldsNumber = tamAuxLinhaProdutoFinal, .aliasField = ID_INGREDIENTE_LINHA_PRODUTO_FINAL};

    strcpy(NomeFicheiro, "linhaProdutoFinal.txt");
    readFile(NomeFicheiro, &linhaProdutoFinalClass, MAX_LINHA_PRODUTO_FINAL);

    //---------------------------------------------------------------------------------------------------------//
    //Datas
    FieldAux extructAuxDate[] = {
        {.fieldName = "day", .alias = "Dia", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true},
        {.fieldName = "mouth", .alias = "Mes", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true},
        {.fieldName = "year", .alias = "Ano", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true},

    };
    const unsigned int tamAuxDate = (sizeof (extructAuxDate) / sizeof (extructAuxDate[0]));
    const unsigned int tamTipoDate = sizeof (Date);

    Class dataClass = {.name = "Data", .StructTypeSize = tamTipoDate, .auxStruct = &extructAuxDate, .fieldsNumber = tamAuxDate};


    //---------------------------------------------------------------------------------------------------------//
    //Encomenda

    const unsigned MAX_ENCOMENDA = 10;

    FieldAux estructAuxEncomenda[] = {
        {.fieldName = "id_encomenda", .alias = "Numero da Encomenda", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_cliente", .alias = "Cliente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &clienteClass, .parentPrimaryKey = ID_CLIENTE},
        {.fieldName = "data_encomenda", .alias = "Data Encomenda", .date = true, .sizeBytes = tamTipoDate, .type = STRUCT, .substructClass = &dataClass, .unique = false, .required = false, .autoIncrement = false},
        {.fieldName = "data_entrega", .alias = "Data Entrega", .date = true, .sizeBytes = tamTipoDate, .type = STRUCT, .substructClass = &dataClass, .unique = false, .required = true, .autoIncrement = false},

    };

    Encomenda encomenda[MAX_ENCOMENDA];
    const unsigned int tamAuxEncomenda = (sizeof (estructAuxEncomenda) / sizeof (estructAuxEncomenda[0]));
    const unsigned int tamTipoEncomenda = sizeof (Encomenda);

    Class encomendaClass = {.name = "encomenda", .fileName = "encomenda.txt", .StructTypeSize = tamTipoEncomenda, .data = &encomenda, .auxStruct = &estructAuxEncomenda, .elements = &contadorEncomenda, .fieldsNumber = tamAuxEncomenda, .aliasField = ID_CLIENTE};

    strcpy(NomeFicheiro, "encomenda.txt");
    readFile(NomeFicheiro, &encomendaClass, MAX_ENCOMENDA);

    //---------------------------------------------------------------------------------------------------------//
    //Linha da Encomenda

    const unsigned MAX_LINHA_ENCOMENDA = 10;

    FieldAux estructAuxLinhaEncomenda[] = {
        {.fieldName = "id_linha_encomenda", .alias = "Numero da Linha da Encomenda", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_encomenda", .alias = "Encomenda", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &encomendaClass, .parentPrimaryKey = ID_ENCOMENDA},
        {.fieldName = "id_produto_final", .alias = "Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &produtoFinalClass, .parentPrimaryKey = ID_PRODUTO_FINAL},
        {.fieldName = "quantidade", .alias = "Quantidade", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false},

    };

    LinhaEncomenda linhasEncomenda[MAX_LINHA_ENCOMENDA];
    const unsigned int tamAuxLinhaEncomenda = (sizeof (estructAuxLinhaEncomenda) / sizeof (estructAuxLinhaEncomenda[0]));
    const unsigned int tamTipoLinhaEncomenda = sizeof (LinhaEncomenda);

    Class linhaEncomendaClass = {.name = "Linha Encomenda", .fileName = "linhaEncomenda.txt", .StructTypeSize = tamTipoLinhaEncomenda, .data = &linhasEncomenda, .auxStruct = &estructAuxLinhaEncomenda, .elements = &contadorLinhasEncomenda, .fieldsNumber = tamAuxLinhaEncomenda, .aliasField = ID_PRODUTO_FINAL_LINHA_ENCOMENDA};

    strcpy(NomeFicheiro, "linhaEncomenda.txt");
    readFile(NomeFicheiro, &linhaEncomendaClass, MAX_LINHA_ENCOMENDA);

    //---------------------------------------------------------------------------------------------------------//
    //Produção
    const unsigned MAX_PRODUCAO = 10;

    FieldAux estructAuxProducao[] = {
        {.fieldName = "id_producao", .alias = "Numero da Producao", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_linha_encomenda", .alias = "Linha da Encomenda", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &linhaEncomendaClass, .parentPrimaryKey = ID_LINHA_ENCOMENDA},
        {.fieldName = "quantidade", .alias = "Quantidade", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false},

    };

    Producao producoes[MAX_PRODUCAO];
    const unsigned int tamAuxProducao = (sizeof (estructAuxProducao) / sizeof (estructAuxProducao[0]));
    const unsigned int tamTipoProducao = sizeof (Producao);

    Class producaoClass = {.name = "Producao", .fileName = "producao.txt", .StructTypeSize = tamTipoProducao, .data = &producoes, .auxStruct = &estructAuxProducao, .elements = &contadorProducao, .fieldsNumber = tamAuxProducao, .aliasField = ID_LINHA_ENCOMENDA_PRODUCAO};

    strcpy(NomeFicheiro, "producao.txt");
    readFile(NomeFicheiro, &producaoClass, MAX_PRODUCAO);

    //---------------------------------------------------------------------------------------------------------//

    typedef struct {
        Class * tipoUtilizadorClass;
        Class * utilizadorClass;
        Class * clienteClass;
        Class * unidadeClass;
        Class * ingredienteClass;
        Class * produtoFinalClass;
        Class * linhaProdutoFinalClass;
        Class * encomendaClass;
        Class * linhaEncomendaClass;
        Class * producaoClass;


    } Classes;

    Classes classes;
    classes.tipoUtilizadorClass = &tipoUtilizadorClass;
    classes.utilizadorClass = &utilizadorClass;
    classes.clienteClass = &clienteClass;
    classes.unidadeClass = &unidadeClass;
    classes.ingredienteClass = &ingredienteClass;
    classes.produtoFinalClass = &produtoFinalClass;
    classes.linhaProdutoFinalClass = &linhaProdutoFinalClass;
    classes.encomendaClass = &encomendaClass;
    classes.linhaEncomendaClass = &linhaEncomendaClass;
    classes.producaoClass = &producaoClass;


    puts("Administrador:                        Cliente:");
    puts("Login: a                              Login: c");
    puts("Password: 1234                        Password 1234");
    menuLogin(&classes);
    
    //Testes
    //listarProducao_Encomenda_LinhaEncomenda(classes.producaoClass, classes.linhaEncomendaClass, classes.produtoFinalClass, classes.linhaProdutoFinalClass);

   //menuLogin(&classes);
    //unsigned short idCliente=2;
    //listarEncomendasCompletasCliente(classes.encomendaClass,idCliente,classes.linhaEncomendaClass,classes.producaoClass); 
    //---------------------------------------------------------------------------------------------------------//
    //Checks
    //inserirTipoUtilizador(classes.tipoUtilizadorClass);
    //listarTipoUtilizadores(classes.tipoUtilizadorClass);

    //listarTipoUtilizador(classes.tipoUtilizadorClass,0);
    //int chaves[] = {0, 1};
    //int campos[] = {ID_TIPO_UTILIZADOR, DESCRICAO_TIPO_UTILIZADOR};
    //filtrarTipoUtilizadores(classes.tipoUtilizadorClass, chaves, 2, campos, 2);
    //filtrarTipoUtilizador(classes.tipoUtilizadorClass,0,campos,2);
    //filtrarEditarTipoUtilizador(classes.tipoUtilizadorClass,0,campos,2);
    //editarTipoUtilizador(classes.tipoUtilizadorClass,1);
    //listar_editar_tipoUtilizadores(classes.tipoUtilizadorClass);
    //editarTipoUtilizadores(classes.tipoUtilizadorClass,chaves,2);
    //TipoUtilizador *tipoUtilizadorData = classes.tipoUtilizadorClass->data;
    //removerTipoUtilizador(classes.tipoUtilizadorClass, 2);
    //listarTipoUtilizadores(classes.tipoUtilizadorClass);

    //inserirUtilizador(classes.utilizadorClass);
    //listarUtilizadores(classes.utilizadorClass);
    // (*classes.utilizadorClass->elements)=0;
    // listarUtilizador(classes.utilizadorClass, 0);
    //listar_editar_utilizadores(classes.utilizadorClass);
    //printShort(classes.utilizadorClass->elements);

    //inserirCliente(classes.clienteClass);
    //removerCliente(classes.clienteClass,1);
    //listarClientes(classes.clienteClass);


    // inserirIngrediente(classes.ingredienteClass);
    //listarIngredientes(classes.ingredienteClass);

    //inserirProdutoFinal(classes.produtoFinalClass);
    //listarProdutosFinais(classes.produtoFinalClass);

   // inserirLinhaProdutoFinal(classes.linhaProdutoFinalClass);
    //listarLinhaProdutosFinais(classes.linhaProdutoFinalClass);

    // inserirEncomenda(classes.encomendaClass);
    //listarEncomendas(classes.encomendaClass);

    // inserirLinhaEncomenda(classes.linhaEncomendaClass);
    // listarLinhaEncomendas(classes.linhaEncomendaClass);


    //inserirProducao(classes.producaoClass);
    //printShort(classes.producaoClass->elements);
    //listarProducoes(classes.producaoClass);

    //listarProdutosFinais_LinhasProdutoFinal(classes.produtoFinalClass,classes.linhaProdutoFinalClass);
    //listarProdutoFinal_LinhasProdutoFinal(classes.produtoFinalClass,classes.linhaProdutoFinalClass,0);

    // listar_Encomenda_linhaEncomenda_producao(classes.encomendaClass,classes.linhaEncomendaClass,classes.producaoClass);

    //listarProducao_Encomenda_LinhaEncomenda(classes.producaoClass,classes.linhaEncomendaClass,classes.produtoFinalClass,classes.linhaProdutoFinalClass);


    //time_t time=getUnixTime();
    //convertDate(&time);




    return (EXIT_SUCCESS);
}



