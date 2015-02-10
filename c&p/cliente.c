
#include "DataManagement.h"
#include "cliente.h"
#include <string.h>


void guardarCliente(Class *clienteClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "cliente.txt");
    writeFile(NomeFicheiro, clienteClass);
}

void listarClientes(Class *clienteClass) {
    fullList(clienteClass);

}

void listarCliente(Class *clienteClass, const unsigned int chave) {
    singleList(clienteClass, chave);
}

void filtrarClientes(Class *clienteClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
    parsedList(clienteClass, chaves, numeroChaves, campos, numeroCampos);
}

void filtrarCliente(Class *clienteClass, int chave, int *campos, int numeroCampos) {
    singleParsedList(clienteClass, chave, campos, numeroCampos);
}

void inserirCliente(Class *clienteClass) {
    char mensagemConfirmacao[MEDIUM_STRING];
    strcpy(mensagemConfirmacao, "Tem a certeza que pertende inserir um novo cliente?[Y/N]");
    puts(mensagemConfirmacao);
    char resposta[1 + 1];
    readChar(resposta);
    if (compareStrings(resposta, "Y") == true) {
        create(clienteClass);
        guardarCliente(clienteClass);
    } else puts("Regressar ao menu cliente");

}

void filtrarEditarCliente(Class *clienteClass, const unsigned int chave, const unsigned int *campos, const unsigned int numeroCampos) {
    singleParsedRead(clienteClass, UPDATE, chave, campos, numeroCampos);
    guardarCliente(clienteClass);

}

void editarCliente(Class *clienteClass, const unsigned int chave) {
    fullRead(clienteClass, UPDATE, chave);
    guardarCliente(clienteClass);

}

void listar_editar_cliente(Class *clienteClass) {
    listarClientes(clienteClass);
    puts("Escolha o Cliente que quer editar");
    unsigned int clienteID;
    readInt(&clienteID);
    Cliente *cliente;
    cliente = clienteClass->data;
    if (clienteID >= cliente[0].id_cliente && clienteID <= cliente[*(clienteClass->elements) - 1].id_cliente) {
        editarCliente(clienteClass, clienteID - 1);
    }
}

void editarClientes(Class *clienteClass, const unsigned int *chaves, const unsigned numeroChaves) {
    unsigned int i;
    for (i = 0; i < numeroChaves; i++) {
        fullRead(clienteClass, UPDATE, chaves[i]);
    }
    guardarCliente(clienteClass);

}

void removerCliente(Class *clienteClass, const unsigned short key) {
   
        removeKey(clienteClass, key);
        guardarCliente(clienteClass);
        puts("Cliente removido com sucesso");
}



