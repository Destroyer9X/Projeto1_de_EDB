#ifndef LISTA_PEDIDOS_H
#define LISTA_PEDIDOS_H

#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura da lista ligada
typedef struct Lista_ligada {
   int valor; 
   struct Lista_ligada *proximo;
} pendente;

// Funções
void inicializar(pendente **lista);
void adicionar(pendente **lista, int valor);
void lista_pendente(pendente *lista);
void remover(pendente **lista, int idPedido);
void processar(pendente **lista);

#endif