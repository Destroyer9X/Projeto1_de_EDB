#include <stdlib.h>
#include <stdio.h>
#include "Fila.h"  // Header file para declarar as funções e tipos
#include "Lista_Pedidos.h"
#include "Imprimir_Menu.h"

// Função para inserir um pedido na fila
void inserir_nos_pedidos(pedidos_processando **fila, int num) {
    pedidos_processando *novo = malloc(sizeof(pedidos_processando));
    if (novo) {
        novo->pedidos = num;
        novo->proximo = NULL;
        if (*fila == NULL) {
            // Se a fila estiver vazia, o novo pedido é o primeiro
            *fila = novo;
        } else {
            // Caso contrário, insere no final da fila
            pedidos_processando *aux = *fila;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else {
        printf("\nErro ao alocar memória.\n");
    }
}

// Função para listar os pedidos em processamento
void listarprocessamento(pedidos_processando *fila) {
    printf("\n\t-------------PEDIDOS EM PROCESSO-------------\n");
    while (fila) {
        const char* nome_do_prato = obter_nome_do_prato(fila->pedidos);
        printf("\t%s\n", nome_do_prato);
        fila = fila->proximo;
    }
}

void inserir_da_lista_para_fila(pendente *lista, pedidos_processando **fila) {
    pedidos_processando *ultimo = NULL; // Ponteiro para o último nó na fila
    
    while (lista) {
        pedidos_processando *novo = (pedidos_processando *)malloc(sizeof(pedidos_processando));
        if (!novo) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        novo->pedidos = lista->valor; // Ou o campo apropriado
        novo->proximo = NULL;
        
        if (*fila == NULL) {
            // A fila está vazia, então o novo pedido é o primeiro
            *fila = novo;
        } else {
            // Encontre o último nó e adicione o novo pedido no final
            ultimo = *fila;
            while (ultimo->proximo != NULL) {
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = novo;
        }
        lista = lista->proximo;
    }
}