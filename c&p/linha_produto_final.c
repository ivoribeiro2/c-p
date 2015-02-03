

#include "DataManagement.h"
#include "linha_encomenda.h"
#include <string.h>

void guardarLinhaProdutoFinal(Class *linhaProdutoFinalClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "linhaProdutoFinal.txt");
    writeFile(NomeFicheiro, linhaProdutoFinalClass);
}

void listarLinhaProdutoFinals(Class *linhaProdutoFinalClass) {
    fullList(linhaProdutoFinalClass);

}

void listarLinhaProdutoFinal(Class *linhaProdutoFinalClass, const unsigned int chave) {
    singleList(linhaProdutoFinalClass, chave);
}

void filtrarLinhaProdutoFinals(Class *linhaProdutoFinalClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(linhaProdutoFinalClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarLinhaProdutoFinal(Class *linhaProdutoFinalClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(linhaProdutoFinalClass, chave, campos, numeroCampos);
}


void inserirLinhaProdutoFinal(Class *linhaProdutoFinalClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo linhaProdutoFinal?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(linhaProdutoFinalClass);
        guardarLinhaProdutoFinal(linhaProdutoFinalClass);
    } else puts("Regressar ao menu gestao de linhaProdutoFinal");

}

void filtrarEditarLinhaProdutoFinal(Class *linhaProdutoFinalClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(linhaProdutoFinalClass, UPDATE, chave, campos, numeroCampos);
    guardarLinhaProdutoFinal(linhaProdutoFinalClass);

}

void editarLinhaProdutoFinal(Class *linhaProdutoFinalClass, const unsigned int chave) {
    fullRead(linhaProdutoFinalClass, UPDATE, chave);
    guardarLinhaProdutoFinal(linhaProdutoFinalClass);

}

void listar_editar_linhaProdutoFinal(Class *linhaProdutoFinalClass) {
    listarLinhaProdutoFinals(linhaProdutoFinalClass);
    puts("Escolha o LinhaProdutoFinal que quer editar");
    unsigned int linhaProdutoFinalID;
    readInt(&linhaProdutoFinalID);
    LinhaProdutoFinal *linhaProdutoFinal;
    linhaProdutoFinal = linhaProdutoFinalClass->data;
    if (linhaProdutoFinalID >= linhaProdutoFinal[0].id_linha_produto_final && linhaProdutoFinalID <= linhaProdutoFinal[*(linhaProdutoFinalClass->elements) - 1].id_linha_produto_final) {
        editarLinhaProdutoFinal(linhaProdutoFinalClass, linhaProdutoFinalID - 1);
    }
}

void editarLinhaProdutoFinals(Class *linhaProdutoFinalClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(linhaProdutoFinalClass, UPDATE, chaves[i]);
    }
    guardarLinhaProdutoFinal(linhaProdutoFinalClass);

}

void removerLinhaProdutoFinal(Class *tipoUtilizadorClass, const unsigned short key) {
    puts("Tem a certeza que pertende remover o linhaProdutoFinal?[Y/N]");
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true || compareStrings(resposta, "y") == true) {
        removeKey(tipoUtilizadorClass, key);
        guardarTipoUtilizador(tipoUtilizadorClass);
        puts("Tipo de utilizador removido com sucesso Obrigado");
    } else puts("Menu eliminar linhaProdutoFinal");
}



