
#include "DataManagement.h"
#include "ingrediente.h"
#include <string.h>

void guardarIngrediente(Class *ingredienteClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "ingrediente.txt");
    writeFile(NomeFicheiro, ingredienteClass);
}

void listarIngredientes(Class *ingredienteClass) {
    fullList(ingredienteClass);

}

void listarIngrediente(Class *ingredienteClass, const unsigned int chave) {
    singleList(ingredienteClass, chave);
}

void filtrarIngredientes(Class *ingredienteClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(ingredienteClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarIngrediente(Class *ingredienteClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(ingredienteClass, chave, campos, numeroCampos);
}


void inserirIngrediente(Class *ingredienteClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo ingrediente?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(ingredienteClass);
        guardarIngrediente(ingredienteClass);
    } else puts("Regressar ao menu gestao de ingrediente");

}

void filtrarEditarIngrediente(Class *ingredienteClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(ingredienteClass, UPDATE, chave, campos, numeroCampos);
    guardarIngrediente(ingredienteClass);

}

void editarIngrediente(Class *ingredienteClass, const unsigned int chave) {
    fullRead(ingredienteClass, UPDATE, chave);
    guardarIngrediente(ingredienteClass);

}

void listar_editar_ingrediente(Class *ingredienteClass) {
    listarIngredientes(ingredienteClass);
    puts("Escolha o Ingrediente que quer editar");
    unsigned int ingredienteID;
    readInt(&ingredienteID);
    Ingrediente *ingrediente;
    ingrediente = ingredienteClass->data;
    if (ingredienteID >= ingrediente[0].id_ingrediente && ingredienteID <= ingrediente[*(ingredienteClass->elements) - 1].id_ingrediente) {
        editarIngrediente(ingredienteClass, ingredienteID - 1);
    }
}

void editarIngredientes(Class *ingredienteClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(ingredienteClass, UPDATE, chaves[i]);
    }
    guardarIngrediente(ingredienteClass);

}

void removerIngrediente(Class *tipoUtilizadorClass, const unsigned short key) {
    puts("Tem a certeza que pertende remover o ingrediente?[Y/N]");
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true || compareStrings(resposta, "y") == true) {
        removeKey(tipoUtilizadorClass, key);
        guardarTipoUtilizador(tipoUtilizadorClass);
        puts("Tipo de utilizador removido com sucesso Obrigado");
    } else puts("Menu eliminar ingrediente");
}





