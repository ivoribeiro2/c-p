
#include <stdio.h>
#include <stdlib.h>
#include "DataManagement.h"

FILE *ap_ficheiro;

void readFile(char *nome, Class *class, unsigned int tam_max) {
    ap_ficheiro = fopen(nome, "r+"); // Abre o ficheiro
    if (!ap_ficheiro) { // Se o apontador devolvido for inválido ocorreu um erro na leitura
        // printf("\n IMPOSSIVEL ABRIR O FICHEIRO.");
        // printf("\n\n ");
    } else {
        *(class->elements) = fread(class->data, class->StructTypeSize, tam_max, ap_ficheiro); // Lê a informação do ficheiro e armazena no array
        fclose(ap_ficheiro); // Fecha o ficheiro
        // printf("\n O FICHEIRO FOI LIDO COM SUCESSO.\n\n ");
    }
}

void writeFile(char *nome, Class *class) {
    ap_ficheiro = fopen(nome, "w"); // Abre o ficheiro  em modo de escrita
    if (!ap_ficheiro) {
        printf("\n IMPOSSIVEL ABRIR O FICHEIRO."); // Se o apontador devolvido for inválido ocorreu um erro na leitura
        //printf("\n\n ");
    } else {

        fwrite(class->data, class->StructTypeSize, *(class->elements), ap_ficheiro); // Guarda a informação do array no ficheiro 

        fclose(ap_ficheiro); // Fecha o ficheiro
        //printf("\n O FICHEIRO FOI GUARDADO COM SUCESSO.\n\n ");
    }
}