#include <stdlib.h>
#include <stdio.h>
#include "fila.h"  // Header file para declarar as funções e tipos

typedef struct Pedidos_processando {
    int pedidos;
    struct Pedidos_processando *proximo;
} pedidos_processando;

void inserir_nos_pedidos(pedidos_processando **fila, int num) {
    pedidos_processando *aux, *novo = malloc(sizeof(pedidos_processando));
    if (novo) {
        novo->pedidos = num;
        novo->proximo = NULL;
        if (*fila == NULL) {
            *fila = novo;
        } else {
            aux = *fila;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else {
        printf("\nErro ao alocar memoria.\n");
    }
}

void listarprocessamento(pedidos_processando *fila) {
    printf("\t-------------PEDIDOS EM PROCESSO-------------\n");
    while (fila) {
        printf("\t%d\n", fila->pedidos);
        fila = fila->proximo;
    }
    
}

// Função para inserir pedidos da lista ligada na fila
void inserir_da_lista_para_fila(NoLista *lista, pedidos_processando **fila) {
    while (lista != NULL) {
        inserir_nos_pedidos(fila, lista->numero);  // Insere o número atual da lista na fila
        lista = lista->proximo;                    // Avança para o próximo nó da lista
    }
}