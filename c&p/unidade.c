
#include "DataManagement.h"
#include "unidade.h"
#include <string.h>

void guardarUnidade(Class *unidadeClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "unidade.txt");
    writeFile(NomeFicheiro, unidadeClass);
}

void listarUnidades(Class *unidadeClass) {
    fullList(unidadeClass);

}

void listarUnidade(Class *unidadeClass, const unsigned int chave) {
    singleList(unidadeClass, chave);
}

void filtrarUnidades(Class *unidadeClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(unidadeClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarUnidade(Class *unidadeClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(unidadeClass, chave, campos, numeroCampos);
}


void inserirUnidade(Class *unidadeClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo unidade?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(unidadeClass);
        guardarUnidade(unidadeClass);
    } else puts("Regressar ao menu gestao de unidade");

}

void filtrarEditarUnidade(Class *unidadeClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(unidadeClass, UPDATE, chave, campos, numeroCampos);
    guardarUnidade(unidadeClass);

}

void editarUnidade(Class *unidadeClass, const unsigned int chave) {
    fullRead(unidadeClass, UPDATE, chave);
    guardarUnidade(unidadeClass);

}

void listar_editar_unidade(Class *unidadeClass) {
    listarUnidades(unidadeClass);
    puts("Escolha o Unidade que quer editar");
    unsigned int unidadeID;
    readInt(&unidadeID);
    Unidade *unidade;
    unidade = unidadeClass->data;
    if (unidadeID >= unidade[0].id_unidade && unidadeID <= unidade[*(unidadeClass->elements) - 1].id_unidade) {
        editarUnidade(unidadeClass, unidadeID - 1);
    }
}

void editarUnidades(Class *unidadeClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(unidadeClass, UPDATE, chaves[i]);
    }
    guardarUnidade(unidadeClass);

}

void removerUnidade(Class *tipoUtilizadorClass, const unsigned short key) {
    puts("Tem a certeza que pertende remover o unidade?[Y/N]");
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true || compareStrings(resposta, "y") == true) {
        removeKey(tipoUtilizadorClass, key);
        guardarTipoUtilizador(tipoUtilizadorClass);
        puts("Tipo de utilizador removido com sucesso Obrigado");
    } else puts("Menu eliminar unidade");
}


