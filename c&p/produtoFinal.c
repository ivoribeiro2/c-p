

#include "DataManagement.h"
#include "produto_final.h"
#include "linha_produto_final.h"
#include <string.h>

void guardarProdutoFinal(Class *produtoFinalClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "produtoFinal.txt");
    writeFile(NomeFicheiro, produtoFinalClass);
}

void listarProdutosFinais(Class *produtoFinalClass) {
    fullList(produtoFinalClass);

}

void listarProdutoFinal(Class *produtoFinalClass, const unsigned int chave) {
    singleList(produtoFinalClass, chave);
}

void filtrarProdutosFinais(Class *produtoFinalClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(produtoFinalClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarProdutoFinal(Class *produtoFinalClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(produtoFinalClass, chave, campos, numeroCampos);
}

void inserirProdutoFinal(Class *produtoFinalClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo produtoFinal?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(produtoFinalClass);
        guardarProdutoFinal(produtoFinalClass);
    } else puts("Regressar ao menu gestao de produto final");

}

void filtrarEditarProdutoFinal(Class *produtoFinalClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(produtoFinalClass, UPDATE, chave, campos, numeroCampos);
    guardarProdutoFinal(produtoFinalClass);

}

void editarProdutoFinal(Class *produtoFinalClass, const unsigned int chave) {
    fullRead(produtoFinalClass, UPDATE, chave);
    guardarProdutoFinal(produtoFinalClass);

}

void listar_editar_produtoFinal(Class *produtoFinalClass) {
    listarProdutosFinais(produtoFinalClass);
    puts("Escolha o Produto Final que quer editar");
    unsigned int produtoFinalID;
    readInt(&produtoFinalID);
    ProdutoFinal *produtoFinal;
    produtoFinal = produtoFinalClass->data;
    if (produtoFinalID >= produtoFinal[0].id_produto_final && produtoFinalID <= produtoFinal[*(produtoFinalClass->elements) - 1].id_produto_final) {
        editarProdutoFinal(produtoFinalClass, produtoFinalID - 1);
    }
}

void editarProdutosFinais(Class *produtoFinalClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(produtoFinalClass, UPDATE, chaves[i]);
    }
    guardarProdutoFinal(produtoFinalClass);

}

void removerProdutoFinal(Class *tipoUtilizadorClass, const unsigned short key) {
    puts("Tem a certeza que pertende remover o produto final?[Y/N]");
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true || compareStrings(resposta, "y") == true) {
        removeKey(tipoUtilizadorClass, key);
        guardarTipoUtilizador(tipoUtilizadorClass);
        puts("Produto Final removido com sucesso Obrigado");
    } else puts("Menu eliminar produto final");
}

listarProdutosFinais_LinhasProdutoFinal(Class * produtoFinalClass, Class * linhaProdutoFinalClass) {

    unsigned short i = 0, j = 0, k = 0, id_produto_final;
    unsigned int nResultados;
    char sinal[2 + 1];
    strcpy(sinal, "==");
    int *resultados;
    int chaves[MAX_RESULTS];

    for (i = 0; i<*(produtoFinalClass->elements); i++) {
        puts("----------------------------------Produto Final---------------------------------");
        listarProdutoFinal(produtoFinalClass, i);
        puts("-----------------------------Linhas do Produto Final----------------------------");

        id_produto_final = i + 1;
        resultados = pesquisarLinhaProdutoFinal(linhaProdutoFinalClass, ID_PRODUTO_FINAL_LINHA_PRODUTO_FINAL, &id_produto_final, &nResultados, sinal);
        if (nResultados != 0) {
            for (j = 0; j < nResultados; j++) {
                chaves[j] = *(resultados + j);
            }

            for (k = 0; k < nResultados; k++) {
                puts("------------------------------------Linha---------------------------------------");
                listarLinhaProdutoFinal(linhaProdutoFinalClass, chaves[k]);
                puts("--------------------------------------------------------------------------------");
            }

        } else puts("Não foram encontradas linhas do produto final");


    }

}

listarProdutoFinal_LinhasProdutoFinal(Class * produtoFinalClass, Class * linhaProdutoFinalClass, const unsigned short chaveProdutoFinal) {

    unsigned short j = 0, k = 0, id_produto_final;
    unsigned int nResultados;
    char sinal[2 + 1];
    strcpy(sinal, "==");
    int *resultados;
    int chaves[MAX_RESULTS];

    puts("----------------------------------Produto Final---------------------------------");
    listarProdutoFinal(produtoFinalClass, chaveProdutoFinal);
    puts("-----------------------------Linhas do Produto Final----------------------------");

    id_produto_final = chaveProdutoFinal + 1;
    resultados = pesquisarLinhaProdutoFinal(linhaProdutoFinalClass, ID_PRODUTO_FINAL_LINHA_PRODUTO_FINAL, &id_produto_final, &nResultados, sinal);
    if (nResultados != 0) {
        for (j = 0; j < nResultados; j++) {
            chaves[j] = *(resultados + j);
        }

        for (k = 0; k < nResultados; k++) {
            puts("------------------------------------Linha---------------------------------------");
            listarLinhaProdutoFinal(linhaProdutoFinalClass, chaves[k]);
            puts("--------------------------------------------------------------------------------");
        }

    } else puts("Não foram encontradas linhas do produto final");


}





