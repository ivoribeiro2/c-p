#include "DataManagement.h"
#include "encomenda.h"
#include <string.h>
#include "linha_encomenda.h"
#include "producao.h"

void guardarEncomenda(Class *encomendaClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "encomenda.txt");
    writeFile(NomeFicheiro, encomendaClass);
}

void listarEncomendas(Class *encomendaClass) {
    fullList(encomendaClass);
}

void listarEncomenda(Class *encomendaClass, const unsigned int chave) {
    singleList(encomendaClass, chave);
}

void filtrarEncomendas(Class *encomendaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(encomendaClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarEncomenda(Class *encomendaClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(encomendaClass, chave, campos, numeroCampos);
}

void inserirEncomenda(Class *encomendaClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo encomenda?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(encomendaClass);
        guardarEncomenda(encomendaClass);
    } else puts("Regressar ao menu gestao de tipo de utilizador");

}

void inserirEncomendaCliente(Class *encomendaClass, const unsigned short idCliente){
    int camposEncomendaCliente[] = { ID_ENCOMENDA, DATA_ENCOMENDA, DATA_ENTREGA};
    singleParsedRead(encomendaClass, CREATE, *(encomendaClass->elements), camposEncomendaCliente, 3);
    Encomenda *encomendas;
    encomendas = encomendaClass->data;
    (*encomendaClass->elements)++;
    encomendas[*(encomendaClass->elements)-1].id_cliente = idCliente;
    guardarEncomenda(encomendaClass);
    
}

void inserirEncomendaClienteLinhaEncomenda(Class *encomendaClass, Class *linhaEncomendaClass, const unsigned short idCliente){
    inserirEncomendaCliente(encomendaClass, idCliente);
    unsigned short numLinhas;
    puts("Insira o numero de produtos que pretende inserir:");
    readShort(&numLinhas);
    unsigned short i, idEncomenda;
    Encomenda *encomendas;
    encomendas = encomendaClass->data;
    encomendas[*(encomendaClass->elements)-1].id_encomenda = idEncomenda;
    
    for(i=0;i<numLinhas;i++){
        inserirLinhaEncomendaEncomenda(linhaEncomendaClass, idEncomenda);       
    }
    
}

void filtrarEditarEncomenda(Class *encomendaClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(encomendaClass, UPDATE, chave, campos, numeroCampos);
    guardarEncomenda(encomendaClass);

}

void editarEncomenda(Class *encomendaClass, const unsigned int chave) {
    fullRead(encomendaClass, UPDATE, chave);
    guardarEncomenda(encomendaClass);

}

void listar_editar_encomenda(Class *encomendaClass) {
    listarEncomendas(encomendaClass);
    puts("Escolha o Encomenda que quer editar");
    unsigned int encomendaID;
    readInt(&encomendaID);
    Encomenda *encomenda;
    encomenda = encomendaClass->data;
    if (encomendaID >= encomenda[0].id_encomenda && encomendaID <= encomenda[*(encomendaClass->elements) - 1].id_encomenda) {
        editarEncomenda(encomendaClass, encomendaID - 1);
    }
}

void editarEncomendas(Class *encomendaClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(encomendaClass, UPDATE, chaves[i]);
    }
    guardarEncomenda(encomendaClass);

}

int * pesquisarEncomendas(Class *encomendaClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux;
    aux = encomendaClass->auxStruct;
    int * chaves;
    chaves = search(campo, valorPesquisar, encomendaClass->data, encomendaClass->auxStruct, (*encomendaClass->elements), encomendaClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);
    return chaves;
}

void removerEncomenda(Class *encomendaClass, const unsigned short key) {
        removeKey(encomendaClass, key);
        guardarTipoUtilizador(encomendaClass);
        puts("Encomenda removido com sucesso Obrigado");
}


void listar_remover_encomenda(Class *encomendaClass) {
    listarEncomendas(encomendaClass);
    puts("Escolha a Encomenda que quer remover");
    unsigned int encomendaID;
    readInt(&encomendaID);
    Encomenda *encomenda;
    encomenda = encomendaClass->data;
    if (encomendaID >= encomenda[0].id_encomenda && encomendaID <= encomenda[*(encomendaClass->elements) - 1].id_encomenda) {
       removerEncomenda(encomendaClass, encomendaID - 1);
    }
}




void listar_Encomenda_linhaEncomenda_producao(Class * encomendaClass, Class * linhaEncomendaClass, Class * producaoClass) {
    unsigned short i, j, k, l, m, id_encomenda, id_linha_encomenda, producao_encomenda, total_producao_encomenda, quantidade_linha_encomenda;
    unsigned int nResultados, nResultadosProducao;
    char sinal[2 + 1];
    strcpy(sinal, "==");
    int *resultadosLinha;
    int *resultadosProducao;
    Producao *producoes;
    producoes = producaoClass->data;
    LinhaEncomenda *linhasEncomenda;
    linhasEncomenda = linhaEncomendaClass->data;
    int camposLinhaEncomenda[] = {ID_PRODUTO_FINAL_LINHA_ENCOMENDA};


    int chaves[MAX_RESULTS];
    int chavesProducao[MAX_RESULTS];

    for (i = 0; i<*(encomendaClass->elements); i++) {
        puts("----------------------------------Encomenda---------------------------------");
        listarEncomenda(encomendaClass, i);
        puts("-----------------------------Linhas da Encomenda--------------------------------");

        id_encomenda = i + 1;
        resultadosLinha = pesquisarLinhaEncomenda(linhaEncomendaClass, ID_ENCOMENDA_LINHA_ENCOMENDA, &id_encomenda, &nResultados, sinal);
        if (nResultados != 0) {
            for (j = 0; j < nResultados; j++) {

                chaves[j] = *(resultadosLinha + j);

            }

            for (k = 0; k < nResultados; k++) {
                id_linha_encomenda = chaves[k] + 1;
                puts("------------------------------------Linha---------------------------------------");
                listarLinhaEncomenda(linhaEncomendaClass, chaves[k]);
                getAtributeValue(&linhasEncomenda[chaves[k]], linhaEncomendaClass->auxStruct, QUANTIDADE_LINHA_ENCOMENDA, &quantidade_linha_encomenda);

                puts("--------------------------------------------------------------------------------");
                resultadosProducao = pesquisarProducao(producaoClass, ID_LINHA_ENCOMENDA_PRODUCAO, &id_linha_encomenda, &nResultadosProducao, sinal);

                if (nResultadosProducao != 0) {

                    for (l = 0; l < nResultadosProducao; l++) {
                        chavesProducao[l] = *(resultadosProducao + l);
                    }
                    puts("----------------------------------Producoes-------------------------------------");

                    for (m = 0; m < nResultadosProducao; m++) {
                        puts("------------------------------------Linha---------------------------------------");

                        listarProducao(producaoClass, chavesProducao[m]);

                        getAtributeValue(&producoes[chavesProducao[m]], producaoClass->auxStruct, QUANTIDADE_PRODUCAO, &producao_encomenda);
                        total_producao_encomenda = total_producao_encomenda + producao_encomenda;
                        puts("--------------------------------------------------------------------------------");

                    }
                    puts("------------------------------------Resumo Linha--------------------------------");
                    filtrarLinhaEncomenda(linhaEncomendaClass, chaves[k], camposLinhaEncomenda, 1);
                    puts("Unidades encomendadas");
                    printShort(&quantidade_linha_encomenda);
                    puts("Unidades produzidas");
                    printShort(&total_producao_encomenda);
                    total_producao_encomenda = 0;
                } else puts("Não foram encontradas producões para a linha");
            }


        } else puts("Não foram encontradas linhas de encomenda");
    }



}

void listarEncomendasCliente(Class *encomendaClass, unsigned short idCliente) {
    int *rIdEncomendas;
    unsigned int nResultadosCliente;
    char sinal[2 + 1];
    strcpy(sinal, "==");
    rIdEncomendas = pesquisarEncomendas(encomendaClass, ID_CLIENTE_ENCOMENDA, &idCliente, &nResultadosCliente, &sinal);
    int a, s, chavesIdEncomendas[MAX_RESULTS];

    for (a = 0; a < nResultadosCliente; a++) {
        chavesIdEncomendas[a] = *(rIdEncomendas + a);
    }
    puts("----------------------------------Encomendas do Cliente-------------------------------------");

    for (s = 0; s < nResultadosCliente; s++) {
        puts("------------------------------------Encomenda---------------------------------------");
        listarEncomenda(encomendaClass, chavesIdEncomendas[s]);
        puts("--------------------------------------------------------------------------------");

    }
    puts("--------------------------------------------------------------------------------");

}
