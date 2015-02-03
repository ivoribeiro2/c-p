
#include "DataManagement.h"
#include "producao.h"
#include <string.h>

void guardarProducao(Class *producaoClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "producao.txt");
    writeFile(NomeFicheiro, producaoClass);
}

void listarProducaos(Class *producaoClass) {
    fullList(producaoClass);

}

void listarProducao(Class *producaoClass, const unsigned int chave) {
    singleList(producaoClass, chave);
}

void filtrarProducaos(Class *producaoClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(producaoClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarProducao(Class *producaoClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(producaoClass, chave, campos, numeroCampos);
}


void inserirProducao(Class *producaoClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo producao?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(producaoClass);
        guardarProducao(producaoClass);
    } else puts("Regressar ao menu gestao de producao");

}

void filtrarEditarProducao(Class *producaoClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(producaoClass, UPDATE, chave, campos, numeroCampos);
    guardarProducao(producaoClass);

}

void editarProducao(Class *producaoClass, const unsigned int chave) {
    fullRead(producaoClass, UPDATE, chave);
    guardarProducao(producaoClass);

}

void listar_editar_producao(Class *producaoClass) {
    listarProducaos(producaoClass);
    puts("Escolha o Producao que quer editar");
    unsigned int producaoID;
    readInt(&producaoID);
    Producao *producao;
    producao = producaoClass->data;
    if (producaoID >= producao[0].id_producao && producaoID <= producao[*(producaoClass->elements) - 1].id_producao) {
        editarProducao(producaoClass, producaoID - 1);
    }
}

void editarProducaos(Class *producaoClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(producaoClass, UPDATE, chaves[i]);
    }
    guardarProducao(producaoClass);

}

void removerProducao(Class *tipoUtilizadorClass, const unsigned short key) {
    puts("Tem a certeza que pertende remover o producao?[Y/N]");
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true || compareStrings(resposta, "y") == true) {
        removeKey(tipoUtilizadorClass, key);
        guardarTipoUtilizador(tipoUtilizadorClass);
        puts("Tipo de utilizador removido com sucesso Obrigado");
    } else puts("Menu eliminar producao");
}


