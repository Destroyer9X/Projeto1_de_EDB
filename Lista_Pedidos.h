#ifndef LISTA_PEDIDOS
#define LISTA_PEDIDOS

#include <stdlib.h>
#include <stdio.h>

struct Lista_ligada {
   int valor ; 
   struct Lista_ligada *proximo;

};

typedef struct Lista_ligada pendente;

void iniciailizar(pendente ** lista);
void adicionar(pendente ** lista, int valor);
void lista_pendente(pendente ** lista);
void remover(pendente ** lista, int idPedido);
void processar(pendente **lista);

#endif