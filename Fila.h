#ifndef FILA_H
#define FILA_H
#include "Lista_Pedidos.h"

typedef struct Pedidos_processando {
    int pedidos;  // Substitua por um tipo adequado se necessário
    struct Pedidos_processando *proximo;
} pedidos_processando;

void inserir_da_lista_para_fila(pendente *lista, pedidos_processando **fila);
void listarprocessamento(pedidos_processando *fila);
void pedido_finalizado(pedidos_processando *fila);

#endif // FILA_H
