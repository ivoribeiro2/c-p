
#include "DataManagement.h"
#include "utilizador.h"
#include <string.h>

void guardarUtilizador(Class *utilizadorClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "utilizadores.txt");
    writeFile(NomeFicheiro, utilizadorClass);
}

void listarUtilizadores(Class *utilizadorClass) {
    fullList(utilizadorClass);

}

void listarUtilizador(Class *utilizadorClass, const unsigned int chave) {
    singleList(utilizadorClass, chave);
}

void filtrarUtilizadores(Class *utilizadorClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(utilizadorClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarUtilizador(Class *utilizadorClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(utilizadorClass, chave, campos, numeroCampos);
}


void inserirUtilizador(Class *utilizadorClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo utilizador?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(utilizadorClass);
        guardarUtilizador(utilizadorClass);
    } else puts("Regressar ao menu gestao de utilizador");

}

void filtrarEditarUtilizador(Class *utilizadorClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(utilizadorClass, UPDATE, chave, campos, numeroCampos);
    guardarUtilizador(utilizadorClass);

}

void editarUtilizador(Class *utilizadorClass, const unsigned int chave) {
    fullRead(utilizadorClass, UPDATE, chave);
    guardarUtilizador(utilizadorClass);

}

void listar_editar_utilizadores(Class *utilizadorClass) {
    listarUtilizadores(utilizadorClass);
    puts("Escolha o utilizador que quer editar");
    unsigned int utilizadorID;
    readInt(&utilizadorID);
    Utilizador *utilizador;
    utilizador = utilizadorClass->data;
    if (utilizadorID >= utilizador[0].id_utilizador && utilizadorID <= utilizador[*(utilizadorClass->elements) - 1].id_utilizador) {
        editarUtilizador(utilizadorClass, utilizadorID - 1);
    }
}

void editarUtilizadores(Class *utilizadorClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(utilizadorClass, UPDATE, chaves[i]);
    }
    guardarUtilizador(utilizadorClass);

}
int * pesquisarUtilizadores(Class *utilizadorClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux;
    aux = utilizadorClass->auxStruct;
    int * chaves;
    chaves = search(campo, valorPesquisar, utilizadorClass->data, utilizadorClass->auxStruct, (*utilizadorClass->elements), utilizadorClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);
    return chaves;
}

short pesquisarUtilizador(Class *utilizadorClass, const unsigned int campo, void *valorPesquisar, DataType tipoValorPesquisar, unsigned int *nResultados, char *sinal){
    
    unsigned short chave = searchSingle(utilizadorClass, campo, valorPesquisar, tipoValorPesquisar,nResultados,sinal);
    if(nResultados!=0)return chave;
    else return NO_VALUE;
}

void removerUtilizador(Class *utilizadorClass, const unsigned short key) {
        removeKey(utilizadorClass, key);
        guardarUtilizador(utilizadorClass);
        puts("utilizador removido com sucesso Obrigado");
        voltar();
}

void listar_remover_utilizador(Class *utilizadorClass) {
    listarUtilizadores(utilizadorClass);
    puts("Escolha o Utilizador que quer remover");
    unsigned int utilizadorID;
    readInt(&utilizadorID);
    Utilizador *utilizador;
    utilizador = utilizadorClass->data;
    if (utilizadorID >= utilizador[0].id_utilizador && utilizadorID <= utilizador[*(utilizadorClass->elements) - 1].id_utilizador) {
       removerUtilizador(utilizadorClass, utilizadorID - 1);
    }
}

