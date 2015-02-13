
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

void listarProcessoCliente(Class *clienteClass, Class *encomendaClass, Class *linhaEncomendaClass, Class *producaoClass) {
    unsigned short i, id_cliente;
    Cliente *clientes;
    clientes = clienteClass->data;
    for (i = 0; i<*(clienteClass->elements); i++) {
        id_cliente = clientes[i].id_cliente;
        listarEncomendasCompletasCliente(encomendaClass, id_cliente, linhaEncomendaClass, producaoClass);
    }
};

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

short pesquisarCliente(Class *clienteClass, const unsigned int campo, void *valorPesquisar, DataType tipoValorPesquisar, unsigned int *nResultados, char *sinal) {

    unsigned short chave = searchSingle(clienteClass, campo, valorPesquisar, tipoValorPesquisar, nResultados, sinal);
    if (nResultados != 0)return chave;
    else return NO_VALUE;
}

void removerCliente(Class *clienteClass, const unsigned short key) {
    removeKey(clienteClass, key);
    guardarCliente(clienteClass);
    puts("Cliente removido com sucesso");
}

void listar_remover_cliente(Class *clienteClass) {
    listarClientes(clienteClass);
    puts("Escolha o Cliente que quer remover");
    unsigned int clienteID;
    readInt(&clienteID);
    Cliente *cliente;
    cliente = clienteClass->data;
    if (clienteID >= cliente[0].id_cliente && clienteID <= cliente[*(clienteClass->elements) - 1].id_cliente) {
        removerCliente(clienteClass, clienteID - 1);
    }
}




