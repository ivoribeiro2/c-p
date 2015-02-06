
#include "DataManagement.h"
#include "producao.h"
#include "linha_encomenda.h"
#include "produto_final.h"
#include "linha_produto_final.h"

#include <string.h>

void guardarProducao(Class *producaoClass) {
    char NomeFicheiro[SHORT_STRING];
    strcpy(NomeFicheiro, "producao.txt");
    writeFile(NomeFicheiro, producaoClass);
}

void listarProducoes(Class *producaoClass) {
    fullList(producaoClass);

}

void listarProducao(Class *producaoClass, const unsigned int chave) {
    singleList(producaoClass, chave);
}

void filtrarProducoes(Class *producaoClass, int *chaves, int numeroChaves, int *campos, int numeroCampos) {
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
    listarProducoes(producaoClass);
    puts("Escolha o Producao que quer editar");
    unsigned int producaoID;
    readInt(&producaoID);
    Producao *producao;
    producao = producaoClass->data;
    if (producaoID >= producao[0].id_producao && producaoID <= producao[*(producaoClass->elements) - 1].id_producao) {
        editarProducao(producaoClass, producaoID - 1);
    }
}

void editarProducoes(Class *producaoClass, const unsigned int *chaves, const unsigned numeroChaves) {
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

int * pesquisarProducao(Class *producaoClass, const unsigned int campo, void *valorPesquisar, unsigned int *numeroResultados, char *sinal) {
    FieldAux *aux;
    aux = producaoClass->auxStruct;
    int * chaves;
    chaves = search(campo, valorPesquisar, producaoClass->data, producaoClass->auxStruct, (*producaoClass->elements), producaoClass->StructTypeSize, aux[campo].type, numeroResultados, sinal);
    return chaves;
}

void listarProducao_Encomenda_LinhaEncomenda(Class * producaoClass, Class* linhaEncomendaClass, Class *produtoFinalClass, Class * linhaProdutoFinalClass) {
    unsigned short i, j, k, idLinhaEncomenda, idProdutoFinal, nResultados, totalEncomendado;
    float quantidadeLinha, quantidadeTotal;
    Producao *producao;
    LinhaEncomenda *linhaEncomenda;
    LinhaProdutoFinal *linhaProdutoFinal;
    linhaProdutoFinal = linhaProdutoFinalClass->data;
    producao = producaoClass->data;
    linhaEncomenda = linhaEncomendaClass->data;
    int * resultados;
    int chaves[MAX_RESULTS];
    char sinal[2 + 1];
    strcpy(sinal, "==");
    int camposListProdutoFinal[] = {ID_INGREDIENTE_LINHA_PRODUTO_FINAL, ID_UNIDADE_LINHA_PRODUTO_FINAL};
    for (i = 0; i<*(producaoClass->elements); i++) {
        puts("----------------------------------Producao--------------------------");

        listarProducao(producaoClass, i);
        getAtributeValue(&producao[i], producaoClass->auxStruct, ID_LINHA_ENCOMENDA_PRODUCAO, &idLinhaEncomenda);
        getAtributeValue(&linhaEncomenda[idLinhaEncomenda - 1], linhaEncomendaClass->auxStruct, ID_PRODUTO_FINAL_LINHA_ENCOMENDA, & idProdutoFinal);
        listarProdutoFinal_LinhasProdutoFinal(produtoFinalClass, linhaProdutoFinalClass, (idProdutoFinal - 1));
        puts("---------------------Calculo Necessidades------------------------------");
        resultados = pesquisarLinhaProdutoFinal(linhaProdutoFinalClass, ID_PRODUTO_FINAL_LINHA_PRODUTO_FINAL, &idProdutoFinal, &nResultados, sinal);
        if (nResultados != 0) {
            for (j = 0; j < nResultados; j++) {
                chaves[j] = *(resultados + j);
            }

            for (k = 0; k < nResultados; k++) {
                quantidadeLinha = linhaProdutoFinal[chaves[k]].quantidade;
                totalEncomendado = linhaEncomenda[producao[i].id_linha_encomenda - 1].quantidade;
                quantidadeTotal = quantidadeLinha*totalEncomendado;

                filtrarLinhaProdutoFinal(linhaProdutoFinalClass, chaves[k], camposListProdutoFinal, 2);
                puts("Quantidade:");
                printFloat(&quantidadeTotal);
                puts("");

            }


        } else puts("Não foram encontradas linhas do produto final");
    }
};

