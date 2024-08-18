#include <stdlib.h>
#include <stdio.h>
#include "Fila.h"         //Header file que declara as funções e tipos para a fila de processamento.
#include "Lista_Pedidos.h" //Header file que declara as funções e tipos para a lista de pedidos pendentes.
#include "Imprimir_Menu.h" //Header file que declara as funções relacionadas ao menu e pedidos.

/**
 * @brief Insere um novo pedido na fila de processamento.
 * 
 * @param fila Um ponteiro duplo para a estrutura `pedidos_processando`, representando a fila de pedidos em processamento.
 * @param num O identificador do pedido a ser inserido na fila.
 * 
 * A função `inserir_nos_pedidos` aloca memória para um novo nó da fila e insere o pedido no final da fila.
 * Se a fila estiver vazia, o novo nó se torna o primeiro elemento. Caso contrário, ele é adicionado ao final da fila existente.
 */
void inserir_nos_pedidos(pedidos_processando **fila, int num){
    pedidos_processando *novo = malloc(sizeof(pedidos_processando));
    if (novo){
        novo->pedidos = num;
        novo->proximo = NULL;
        if (*fila == NULL){
            //Se a fila estiver vazia, o novo pedido é o primeiro.
            *fila = novo;
        }
        else{
            //Caso contrário, insere no final da fila.
            pedidos_processando *aux = *fila;
            while (aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else{
        printf("\nErro ao alocar memória.\n");
    }
}

/**
 * @brief Lista todos os pedidos que estão atualmente em processamento.
 * 
 * @param fila Um ponteiro para a estrutura `pedidos_processando`, representando a fila de pedidos em processamento.
 * 
 * A função `listarprocessamento` percorre a fila de pedidos em processamento e imprime os nomes dos pratos 
 * correspondentes a cada pedido. Isso fornece uma visão geral dos pedidos que estão sendo preparados.
 */
void listarprocessamento(pedidos_processando *fila) {
    printf("\n\t-------------PEDIDOS EM PROCESSO-------------\n");
    while (fila) {
        const char* nome_do_prato = obter_nome_do_prato(fila->pedidos);
        printf("\t%s\n", nome_do_prato);
        fila = fila->proximo;
    }
}

/**
 * @brief Transfere pedidos de uma lista pendente para a fila de processamento.
 * 
 * @param lista Um ponteiro para a estrutura `pendente`, representando a lista de pedidos pendentes.
 * @param fila Um ponteiro duplo para a estrutura `pedidos_processando`, representando a fila de pedidos em processamento.
 * 
 * A função `inserir_da_lista_para_fila` percorre a lista de pedidos pendentes e, para cada pedido, aloca um novo nó 
 * na fila de processamento e transfere o pedido para essa fila. Isso é útil para mover pedidos da lista de pendentes
 * para a fila onde serão processados.
 */
void inserir_da_lista_para_fila(pendente *lista, pedidos_processando **fila){
    pedidos_processando *ultimo = NULL; //Ponteiro para o último nó na fila.
    
    while (lista) {
        pedidos_processando *novo = (pedidos_processando *)malloc(sizeof(pedidos_processando));
        if (!novo){
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        novo->pedidos = lista->valor; //Atribui o valor do pedido (ou o campo apropriado).
        novo->proximo = NULL;
        
        if (*fila == NULL){
            //A fila está vazia, então o novo pedido é o primeiro.
            *fila = novo;
        }
        else{
            //Encontre o último nó e adicione o novo pedido no final.
            ultimo = *fila;
            while (ultimo->proximo != NULL){
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = novo;
        }
        lista = lista->proximo;
    }
}