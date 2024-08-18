#ifndef LISTA_PEDIDOS_H
#define LISTA_PEDIDOS_H

#include <stdlib.h>
#include <stdio.h>

//Estrutura da Lista Ligada.
/**
 * A estrutura `Lista_ligada` representa um nó em uma lista ligada que armazena um pedido.
 * 
 * Campos:
 * - `valor`: Um inteiro que representa o ID do prato ou pedido.
 * - `proximo`: Um ponteiro para o próximo nó na lista.
 */
typedef struct Lista_ligada{
   int valor; 
   struct Lista_ligada *proximo;
} pendente;

//Funções.
/**
 * @brief Inicializa a lista ligada como uma lista vazia.
 * 
 * @param lista Um ponteiro duplo para a lista que será inicializada.
 */
void inicializar(pendente **lista);

/**
 * @brief Adiciona um novo pedido à lista ligada.
 * 
 * @param lista Um ponteiro duplo para a lista onde o pedido será adicionado.
 * @param valor O ID do prato que será adicionado à lista.
 * 
 * Este novo pedido será inserido no início da lista.
 */
void adicionar(pendente **lista, int valor);

/**
 * @brief Exibe todos os pedidos presentes na lista ligada.
 * 
 * @param lista Um ponteiro para a lista que será percorrida e exibida.
 * 
 * A função itera pela lista e, para cada nó, imprime o nome do prato correspondente ao valor armazenado.
 */
void lista_pendente(pendente *lista);

/**
 * @brief Remove um pedido específico da lista ligada.
 * 
 * @param lista Um ponteiro duplo para a lista de onde o pedido será removido.
 * @param idPedido O ID do prato que será removido da lista.
 * 
 * A função percorre a lista para encontrar o nó que corresponde ao `idPedido` e, se encontrado, o remove.
 */
void remover(pendente **lista, int idPedido);

/**
 * @brief (Ainda não implementado) Processa um pedido da lista.
 * 
 * @param lista Um ponteiro duplo para a lista de onde o pedido será processado.
 * 
 * Esta função deverá remover o primeiro pedido da lista, simulando seu processamento.
 */
void processar(pendente **lista);

#endif // LISTA_PEDIDOS_H