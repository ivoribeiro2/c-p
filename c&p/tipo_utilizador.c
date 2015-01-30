
#include "DataManagement.h"
#include "tipo_utilizador.h"
#include <string.h>

void guardarTipoUtilizador(Class *tipoUtilizadorClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "tipoUtilizadores.txt");
    writeFile(NomeFicheiro, tipoUtilizadorClass);
}

void listarTipoUtilizadores(Class *tipoUtilizadorClass) {
    fullList(tipoUtilizadorClass);

}

void listarTipoUtilizador(Class *tipoUtilizadorClass, const unsigned int chave) {
    singleList(tipoUtilizadorClass, chave);
}

void filtrarTipoUtilizadores(Class *tipoUtilizadorClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(tipoUtilizadorClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarTipoUtilizador(Class *tipoUtilizadorClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(tipoUtilizadorClass, chave, campos, numeroCampos);
}


void inserirTipoUtilizador(Class *tipoUtilizadorClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo tipo de utilizador?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(tipoUtilizadorClass);
        guardarTipoUtilizador(tipoUtilizadorClass);
    } else puts("Regressar ao menu gestao de tipo de utilizador");

}

void filtrarEditarTipoUtilizador(Class *tipoUtilizadorClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(tipoUtilizadorClass, UPDATE, chave, campos, numeroCampos);
    guardarTipoUtilizador(tipoUtilizadorClass);

}

void editarTipoUtilizador(Class *tipoUtilizadorClass, const unsigned int chave) {
    fullRead(tipoUtilizadorClass, UPDATE, chave);
    guardarTipoUtilizador(tipoUtilizadorClass);

}

void listar_editar_tipoUtilizadores(Class *tipoUtilizadorClass) {
    listarTipoUtilizadores(tipoUtilizadorClass);
    puts("Escolha o tipo de utilizador que quer editar");
    unsigned int tipoUtilizadorID;
    readInt(&tipoUtilizadorID);
    TipoUtilizador *tipoUtilizador;
    tipoUtilizador = tipoUtilizadorClass->data;
    if (tipoUtilizadorID >= tipoUtilizador[0].id_tipo_utilizador && tipoUtilizadorID <= tipoUtilizador[*(tipoUtilizadorClass->elements) - 1].id_tipo_utilizador) {
        editarTipoUtilizador(tipoUtilizadorClass, tipoUtilizadorID - 1);
    }
}

void editarTipoUtilizadores(Class *tipoUtilizadorClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(tipoUtilizadorClass, UPDATE, chaves[i]);
    }
    guardarTipoUtilizador(tipoUtilizadorClass);

}

void removerTipoUtilizador(Class *tipoUtilizadorClass, const unsigned short key) {
    puts("Tem a certeza que pertende remover o tipo de utilizador?[Y/N]");
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true || compareStrings(resposta, "y") == true) {
        removeKey(tipoUtilizadorClass, key);
        guardarTipoUtilizador(tipoUtilizadorClass);
        puts("Tipo de utilizador removido com sucesso Obrigado");
    } else puts("Menu eliminar tipo utilizador");
}


