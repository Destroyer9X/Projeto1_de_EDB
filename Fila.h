#ifndef FILA_H
#define FILA_H

#include "Lista_Pedidos.h"

/**
 * @brief Estrutura para representar os pedidos em processamento.
 * 
 * A estrutura `Pedidos_processando` é usada para criar uma fila que armazena os pedidos que estão 
 * atualmente sendo processados. Cada nó da fila contém um pedido (representado por um inteiro) 
 * e um ponteiro para o próximo elemento da fila.
 */
typedef struct Pedidos_processando{
    int pedidos;  //Identificador do pedido. Pode ser substituído por um tipo mais adequado, se necessário.
    struct Pedidos_processando *proximo;  //Ponteiro para o próximo pedido na fila.
} pedidos_processando;

/**
 * @brief Insere pedidos da lista pendente na fila de processamento.
 * 
 * @param lista Um ponteiro para a estrutura `pendente` representando a lista de pedidos pendentes.
 * @param fila Um ponteiro duplo para a estrutura `pedidos_processando`, representando a fila de pedidos em processamento.
 * 
 * A função `inserir_da_lista_para_fila` transfere os pedidos da lista de pedidos pendentes para a fila de
 * processamento, mantendo a ordem de chegada (FIFO). Esta função é usada para mover pedidos da lista para a fila.
 */
void inserir_da_lista_para_fila(pendente *lista, pedidos_processando **fila);

/**
 * @brief Lista todos os pedidos atualmente em processamento.
 * 
 * @param fila Um ponteiro para a estrutura `pedidos_processando`, representando a fila de pedidos em processamento.
 * 
 * A função `listarprocessamento` percorre a fila de pedidos em processamento e imprime uma lista
 * de todos os pedidos que estão atualmente sendo processados.
 */
void listarprocessamento(pedidos_processando *fila);

/**
 * @brief Exibe uma mensagem de finalização para todos os pedidos na fila.
 * 
 * @param fila Um ponteiro para a estrutura `pedidos_processando`, representando a fila de pedidos em processamento.
 * 
 * A função `pedido_finalizado` percorre a fila de pedidos e exibe uma mensagem indicando que todos os pedidos foram 
 * finalizados. Esta função pode ser chamada quando todos os pedidos na fila foram processados.
 */
void pedido_finalizado(pedidos_processando *fila);

#endif // FILA_H