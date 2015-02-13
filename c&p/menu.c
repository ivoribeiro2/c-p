#include <stdio.h>
#include "DataManagement.h"
#include "classes.h"
#include "utilizador.h"
#include "cliente.h"
#include "string.h"
#include "encomenda.h"

void clearscreen() {
    printf("\033[2J");
    printf("\033[H");
}

void voltar() {
    char s[1];
    puts("Prima [ENTER] para voltar");
    readChar(s);
}

//----------------------------------------Clientes----------------------------------------//

void gestaoClientesEncomendas(Classes *classes, unsigned short idCliente) {
    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Gestão de Encomendas                    ");
        puts("                                                          ");
        puts("                  1 - Inserir Encomenda                   ");
        puts("                  2 - Listar Encomendas Processadas       ");
        puts("                  3-  Sair                                ");
        puts("                                                          ");
        puts("                                                          ");
        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 3);

        switch (opcao) {
            case 1:
                inserirEncomendaClienteLinhaEncomenda(classes->encomendaClass, classes->linhaEncomendaClass, idCliente);
                break;
            case 2:
                listarEncomendasCliente(classes->encomendaClass, idCliente);
                voltar();
                break;
            case 3:
                menuLogin(classes);
                break;

        }
    } while (opcao != 3);
}

void relatorios(Classes *classes) {
    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Relatórios                              ");
        puts("                                                          ");
        puts("                  1 - Encomendas Pendentes                ");
        puts("                  2 - Listagem das Encomendas por Secao   ");
        puts("                  3 - Listagem de Produtos Encomendados   ");
        puts("                  4 - Relatorios mensais/anuais           ");
        puts("                  5 - Sair                                ");
        puts("                                                          ");
        puts("                                                          ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 6);

        switch (opcao) {
            case 1:
                puts("");
                voltar();
                break;
            case 2:
                puts("");
                voltar();
                break;
            case 3:
                listarProcessoCliente(classes->clienteClass,classes->encomendaClass,classes->linhaEncomendaClass,classes->producaoClass);
                puts("");
                voltar();
                break;
            case 4:
                puts("");
                break;

            case 5:
                gestaoGestores(classes);
                break;
        }
    } while (opcao != 5);
}
//---------------------------------Gestores----------------------------------//

void gestaoGestores(Classes *classes) {

    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Menu de Gestores                        ");
        puts("                                                          ");
        puts("                  1 - Documento Produto Final             ");
        puts("                  2 - Documento Encomenda                 ");
        puts("                  3 - Documento Pre-Producao              ");
        puts("                  4 - Inserir Encomenda                   ");
        puts("                  5 - Relatórios                          ");
        puts("                  6 - Sair                                ");
        puts("                                                          ");
        puts("                                                          ");

        do {
            puts("Insira o valor da opção pretendida:");

            readInt(&opcao);

        } while (opcao < 0 || opcao > 6);

        switch (opcao) {
            case 1:
                listarProdutosFinais_LinhasProdutoFinal(classes->produtoFinalClass, classes->linhaProdutoFinalClass);
                voltar();
                break;
            case 2:
                listar_Encomendas_linhaEncomenda_producao(classes->encomendaClass, classes->linhaEncomendaClass, classes->producaoClass);
                voltar();
                break;
            case 3:
            {
                listarEncomendas(classes->encomendaClass);
                voltar();
            }
                break;
            case 4:
                inserirEncomendaAdminLinhaEncomenda(classes->encomendaClass, classes->clienteClass, classes->linhaEncomendaClass);
                break;
            case 5:
                relatorios(classes);
                break;
            case 6:
                gestaoAdmin(classes);
                break;
        }
    } while (opcao != 6);
}


//---------------------------------Gestao-----------------------------------//

void gestaoClientes(Class *clienteClass, Classes *classes) {

    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Gestão de Clientes                      ");
        puts("                                                          ");
        puts("                  1 - Listar Clientes                     ");
        puts("                  2 - Inserir Cliente                     ");
        puts("                  3 - Editar Cliente                      ");
        puts("                  4 - Remover Cliente                     ");
        puts("                  5 - Sair                                ");
        puts("                                                          ");
        puts("                                                          ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarClientes(clienteClass);
                voltar();
                break;
            case 2:
                inserirCliente(clienteClass);
                break;
            case 3:
                listar_editar_cliente(clienteClass);
                break;
            case 4:
                listar_remover_cliente(clienteClass);
                break;
            case 5:
                gestaoAdmin(classes);
        }
    } while (opcao != 5);
}

void gestaoIngredientes(Class *ingredientesClass, Classes *classes) {
    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                              ");
        puts("                  Gestão de Ingredientes                      ");
        puts("                                                              ");
        puts("                  1 - Listar Ingredientes                     ");
        puts("                  2 - Inserir Ingrediente                     ");
        puts("                  3 - Editar Ingrediente                      ");
        puts("                  4 - Remover Ingrediente                     ");
        puts("                  5 - Sair                                    ");
        puts("                                                              ");
        puts("                                                              ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarIngredientes(ingredientesClass);
                voltar();
                break;
            case 2:
                inserirIngrediente(ingredientesClass);
                break;
            case 3:
                listar_editar_ingrediente(ingredientesClass);
                break;
            case 4:
                listar_remover_ingrediente(ingredientesClass);
                break;
            case 5:
                gestaoAdmin(classes);

        }
    } while (opcao != 5);
}

void gestaoUtilizadores(Class *utilizadorClass, Classes *classes) {
    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Gestão de Utilizadpres                  ");
        puts("                                                          ");
        puts("                  1 - Listar Utilizadores                 ");
        puts("                  2 - Inserir Utilizadores                ");
        puts("                  3 - Editar Utilizadores                 ");
        puts("                  4 - Remover Utilizadores                ");
        puts("                  5 - Sair                                ");
        puts("                                                          ");
        puts("                                                          ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarUtilizadores(utilizadorClass);
                voltar();
                break;
            case 2:
                inserirUtilizador(utilizadorClass);
                break;
            case 3:
                listar_editar_utilizadores(utilizadorClass);
                break;
            case 4:
                listar_remover_utilizador(utilizadorClass);
                break;
            case 5:
                gestaoAdmin(classes);
        }
    } while (opcao != 5);
}

void gestaoUnidades(Class *unidadesClass, Classes *classes) {

    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Gestão de Unidades                      ");
        puts("                                                          ");
        puts("                  1 - Listar Unidades                     ");
        puts("                  2 - Inserir Unidades                    ");
        puts("                  3 - Editar Unidades                     ");
        puts("                  4 - Remover Unidades                    ");
        puts("                  5 - Sair                                ");
        puts("                                                          ");
        puts("                                                          ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarUnidades(unidadesClass);
                voltar();
                break;
            case 2:
                inserirUnidade(unidadesClass);
                break;
            case 3:
                listar_editar_unidade(unidadesClass);
                break;
            case 4:
                listar_remover_unidade(unidadesClass);
                break;
            case 5:
                gestaoAdmin(classes);
        }
    } while (opcao != 5);

}

void gestaoTipoUtilizadores(Class *tipoUtilizadorClass, Classes *classes) {
    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Gestão de Tipo Utilizadores             ");
        puts("                                                          ");
        puts("                  1 - Listar Tipo Utilizadores            ");
        puts("                  2 - Inserir Tipo Utilizadores           ");
        puts("                  3 - Editar Tipo Utilizadores            ");
        puts("                  4 - Remover Tipo Utilizadores           ");
        puts("                  5 - Sair                                ");
        puts("                                                          ");
        puts("                                                          ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarTipoUtilizadores(tipoUtilizadorClass);
                voltar();
                break;
            case 2:
                inserirTipoUtilizador(tipoUtilizadorClass);
                break;
            case 3:
                listar_editar_tipoUtilizadores(tipoUtilizadorClass);
                break;
            case 4:
                listar_remover_tipoUtilizador(tipoUtilizadorClass);
                break;
            case 5:
                gestaoAdmin(classes);
                break;
        }
    } while (opcao != 5);

}

void gestaoEncomenda(Class *encomendaClass, Classes *classes) {

    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Gestão de Encomendas                    ");
        puts("                                                          ");
        puts("                  1 - Listar Encomendas                   ");
        puts("                  2 - Inserir Encomenda                   ");
        puts("                  3 - Editar Encomenda                    ");
        puts("                  4 - Remover Encomenda                   ");
        puts("                  5 - Sair                                ");
        puts("                                                          ");
        puts("                                                          ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarEncomendas(encomendaClass);
                voltar();
                break;
            case 2:
                inserirEncomenda(encomendaClass);
                break;
            case 3:
                listar_editar_encomenda(encomendaClass);
                break;
            case 4:
                listar_remover_encomenda(encomendaClass);
                break;
            case 5:
                gestaoAdmin(classes);
                break;
        }
    } while (opcao != 5);

}

void gestaoProducao(Class *producaoClass, Classes *classes) {

    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Gestão de Produção                      ");
        puts("                                                          ");
        puts("                  1 - Listar Produção                     ");
        puts("                  2 - Inserir Produção                    ");
        puts("                  3 - Editar Produção                     ");
        puts("                  4 - Remover Produção                    ");
        puts("                  5 - Sair                                ");
        puts("                                                          ");
        puts("                                                          ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarProducoes(producaoClass);
                voltar();
                break;
            case 2:
                inserirProducao(producaoClass);
                break;
            case 3:
                listar_editar_producao(producaoClass);
                break;
            case 4:
                listar_remover_Producao(producaoClass);
                break;
            case 5:
                gestaoAdmin(classes);
        }
    } while (opcao != 5);

}

void gestaoProdutoFinal(Class *produtoFinalClass, Classes *classes) {

    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                           ");
        puts("                  Gestão de Produto Final                  ");
        puts("                                                           ");
        puts("                  1 - Listar Produto Final                 ");
        puts("                  2 - Inserir Produto Final                ");
        puts("                  3 - Editar Produto Final                 ");
        puts("                  4 - Remover Produto Final                ");
        puts("                  5 - Sair                                 ");
        puts("                                                           ");
        puts("                                                           ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarProdutosFinais(produtoFinalClass);
                voltar();
                break;
            case 2:
                inserirProdutoFinal(produtoFinalClass);
                break;
            case 3:
                listar_editar_produtoFinal(produtoFinalClass);
                break;
            case 4:
                listar_remover_ProdutoFinal(produtoFinalClass);
                break;
            case 5:
                gestaoAdmin(classes);
                break;
        }
    } while (opcao != 5);

}

void gestaoLinhaEncomenda(Class *linhaEncomendaClass, Classes *classes) {

    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                          ");
        puts("                  Gestão de Linha Encomenda               ");
        puts("                                                          ");
        puts("                  1 - Listar Linha Encomenda              ");
        puts("                  2 - Inserir Linha Encomenda             ");
        puts("                  3 - Editar Linha Encomenda              ");
        puts("                  4 - Remover Linha Encomenda             ");
        puts("                  5 - Sair                                ");
        puts("                                                           ");
        puts("                                                           ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarLinhaEncomendas(linhaEncomendaClass);
                voltar();
                break;
            case 2:
                inserirLinhaEncomenda(linhaEncomendaClass);
                break;
            case 3:
                listar_editar_linhaEncomenda(linhaEncomendaClass);
                break;
            case 4:
                listar_remover_linha_encomenda(linhaEncomendaClass);
                break;
            case 5:
                gestaoAdmin(classes);
                break;
        }
    } while (opcao != 5);

}

void gestaoLinhaProducaoFinal(Class *linhaProdutoFinalClass, Classes *classes) {

    unsigned short int opcao;
    do {
        clearscreen();
        puts("                                                              ");
        puts("                  Gestão de Linhas Producao Final             ");
        puts("                                                              ");
        puts("                  1 - Listar Linhas Producao Final            ");
        puts("                  2 - Inserir Linhas Producao Final           ");
        puts("                  3 - Editar Linhas Produção Final            ");
        puts("                  4 - Remover Linhas Produção Final           ");
        puts("                  5 - Sair                                    ");
        puts("                                                           ");
        puts("                                                           ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 5);

        switch (opcao) {
            case 1:
                listarLinhaProdutosFinais(linhaProdutoFinalClass);
                voltar();
                break;
            case 2:
                inserirLinhaProdutoFinal(linhaProdutoFinalClass);
                break;
            case 3:
                listar_editar_linhaProdutoFinal(linhaProdutoFinalClass);
                break;
            case 4:
                listar_remover_linha_produto_final(linhaProdutoFinalClass);
                break;
            case 5:
                gestaoAdmin(classes);
                break;
        }
    } while (opcao != 5);

}

void gestaoAdmin(Classes *classes) {
    int opcao;
    do {
        clearscreen();
        puts("                                                           ");
        puts("                                                           ");
        puts("                  MENU ADMINISTRAÇÃO                       ");
        puts("                                                           ");
        puts("                                                           ");
        puts("                  1 -  Menu de Gestores                    ");
        puts("                  2 -  Gestão Tipo Utilizador              ");
        puts("                  3 -  Gestão Utilizadores                 ");
        puts("                  4 -  Gestão Clientes                     ");
        puts("                  5 -  Gestão Unidades                     ");
        puts("                  6 -  Gestão Ingrediente                  ");
        puts("                  7 -  Gestão Produto Final                ");
        puts("                  8 -  Gestão Linha Produto Fincal         ");
        puts("                  9 -  Gestão Encomenda                    ");
        puts("                  10 - Gestão Linha Encomenda              ");
        puts("                  11 - Gestão Produção                     ");
        puts("                  12 - Sair                                ");
        puts("                                                           ");
        puts("                                                           ");

        do {
            puts("Insira o valor da opção pretendida:");
            readInt(&opcao);

        } while (opcao < 0 || opcao > 12);


        switch (opcao) {
            case 1:
                gestaoGestores(classes);
                break;
            case 2:
                gestaoTipoUtilizadores(classes->tipoUtilizadorClass, classes);
                break;
            case 3:
                gestaoUtilizadores(classes->utilizadorClass, classes);
                break;
            case 4:
                gestaoClientes(classes->clienteClass, classes);
                break;
            case 5:
                gestaoUnidades(classes->unidadeClass, classes);
                break;
            case 6:
                gestaoIngredientes(classes->ingredienteClass, classes);
                break;
            case 7:
                gestaoProdutoFinal(classes->produtoFinalClass, classes);
                break;
            case 8:
                gestaoLinhaProducaoFinal(classes->linhaProdutoFinalClass, classes);
                break;
            case 9:
                gestaoEncomenda(classes->encomendaClass, classes);
                break;
            case 10:
                gestaoLinhaEncomenda(classes->linhaEncomendaClass, classes);
                break;
            case 11:
                gestaoProducao(classes->producaoClass, classes);
                break;
            case 12:
                menuLogin(classes);
                break;
        }
    } while (opcao != 12);
}

void menuLogin(Classes *classes) {
    clearscreen();
    puts("Administrador:                        Cliente:");
    puts("Login: a                              Login: c");
    puts("Password: 1234                        Password: qwer");
    puts("");
    puts("------------------------------------------------------");
    Utilizador * utilizadores;
    utilizadores = classes->utilizadorClass->data;
    Cliente * clientes;
    clientes = classes->clienteClass->data;
    unsigned short int TAM_STRING = 24;
    char nome[TAM_STRING], password[TAM_STRING];
    puts("                      ");
    puts("          Login       ");
    puts("                      ");
    puts("User:");
    readString(&nome, TAM_STRING);


    unsigned short chavePesquisaNome;
    int counterNome;
    char sinal[2 + 1];
    strcpy(sinal, "==");
    chavePesquisaNome = pesquisarUtilizador(classes->utilizadorClass, USERNAME, nome, STRING, &counterNome, sinal);

    if (counterNome == 1) {
        puts("Password:");
        readString(&password, TAM_STRING);
        if (compareStrings(password, utilizadores[chavePesquisaNome].password) == true) {

            unsigned short idUtilizador;
            idUtilizador = utilizadores[chavePesquisaNome].id_utilizador;

            unsigned short tipoUtilizador;
            tipoUtilizador = utilizadores[chavePesquisaNome].id_tipo_utilizador;

            if (tipoUtilizador == 1) {
                gestaoAdmin(classes);
            }
            if (tipoUtilizador == 2) {
                unsigned int chavePesquisaCliente;
                int counterIdCliente;
                chavePesquisaCliente = pesquisarCliente(classes->clienteClass, ID_UTILIZADOR_CLIENTE, &idUtilizador, INT, &counterIdCliente, sinal);
                if (counterIdCliente == 1) {
                    unsigned short idCliente;
                    idCliente = clientes[chavePesquisaCliente].id_cliente;
                    gestaoClientesEncomendas(classes, idCliente);
                } else puts("Não existe cliente para este utilizador");
            } else {
                menuLogin(classes);
            }

        } else {
            puts("Password Errada");
            voltar();
            menuLogin(classes);
        }
    } else {
        puts("Username Errado");
        voltar();
        menuLogin(classes);
    }

}