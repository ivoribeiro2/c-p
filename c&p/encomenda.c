
#include "DataManagement.h"
#include "encomenda.h"
#include <string.h>

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

void removerEncomenda(Class *tipoUtilizadorClass, const unsigned short key) {
    puts("Tem a certeza que pertende remover o tipo de utilizador?[Y/N]");
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true || compareStrings(resposta, "y") == true) {
        removeKey(tipoUtilizadorClass, key);
        guardarTipoUtilizador(tipoUtilizadorClass);
        puts("Tipo de utilizador removido com sucesso Obrigado");
    } else puts("Menu eliminar tipo utilizador");
}




