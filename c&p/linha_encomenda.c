

#include "DataManagement.h"
#include "linha_encomenda.h"
#include <string.h>

void guardarLinhaEncomenda(Class *linhaEncomendaClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "linhaEncomenda.txt");
    writeFile(NomeFicheiro, linhaEncomendaClass);
}

void listarLinhaEncomendas(Class *linhaEncomendaClass) {
    fullList(linhaEncomendaClass);

}

void listarLinhaEncomenda(Class *linhaEncomendaClass, const unsigned int chave) {
    singleList(linhaEncomendaClass, chave);
}

void filtrarLinhaEncomendas(Class *linhaEncomendaClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(linhaEncomendaClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarLinhaEncomenda(Class *linhaEncomendaClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(linhaEncomendaClass, chave, campos, numeroCampos);
}


void inserirLinhaEncomenda(Class *linhaEncomendaClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo linhaEncomenda?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(linhaEncomendaClass);
        guardarLinhaEncomenda(linhaEncomendaClass);
    } else puts("Regressar ao menu gestao de linhaEncomenda");

}

void filtrarEditarLinhaEncomenda(Class *linhaEncomendaClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(linhaEncomendaClass, UPDATE, chave, campos, numeroCampos);
    guardarLinhaEncomenda(linhaEncomendaClass);

}

void editarLinhaEncomenda(Class *linhaEncomendaClass, const unsigned int chave) {
    fullRead(linhaEncomendaClass, UPDATE, chave);
    guardarLinhaEncomenda(linhaEncomendaClass);

}

void listar_editar_linhaEncomenda(Class *linhaEncomendaClass) {
    listarLinhaEncomendas(linhaEncomendaClass);
    puts("Escolha o LinhaEncomenda que quer editar");
    unsigned int linhaEncomendaID;
    readInt(&linhaEncomendaID);
    LinhaEncomenda *linhaEncomenda;
    linhaEncomenda = linhaEncomendaClass->data;
    if (linhaEncomendaID >= linhaEncomenda[0].id_linha_encomenda && linhaEncomendaID <= linhaEncomenda[*(linhaEncomendaClass->elements) - 1].id_linha_encomenda) {
        editarLinhaEncomenda(linhaEncomendaClass, linhaEncomendaID - 1);
    }
}

void editarLinhaEncomendas(Class *linhaEncomendaClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(linhaEncomendaClass, UPDATE, chaves[i]);
    }
    guardarLinhaEncomenda(linhaEncomendaClass);

}

void removerLinhaEncomenda(Class *tipoUtilizadorClass, const unsigned short key) {
    puts("Tem a certeza que pertende remover o linhaEncomenda?[Y/N]");
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true || compareStrings(resposta, "y") == true) {
        removeKey(tipoUtilizadorClass, key);
        guardarTipoUtilizador(tipoUtilizadorClass);
        puts("Tipo de utilizador removido com sucesso Obrigado");
    } else puts("Menu eliminar linhaEncomenda");
}

int * pesquisarLinhaEncomenda(Class *linhaEncomendaClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux; 
    aux = linhaEncomendaClass->auxStruct;
    int * chaves;
    chaves=search(campo, valorPesquisar, linhaEncomendaClass->data, linhaEncomendaClass->auxStruct, (*linhaEncomendaClass->elements), linhaEncomendaClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);
    return chaves;
}


