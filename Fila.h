#ifndef FILA_H
#define FILA_H

// Estrutura da fila de pedidos
typedef struct Pedidos_processando pedidos_processando;

// Estrutura da lista ligada (que estará no arquivo lista.c)
typedef struct NoLista {
    int numero;
    struct NoLista *proximo;
} NoLista;

// Funções
void inserir_nos_pedidos(pedidos_processando **fila, int num);
void listarprocessamento(pedidos_processando *fila);
void inserir_da_lista_para_fila(NoLista *lista, pedidos_processando **fila);


#endif