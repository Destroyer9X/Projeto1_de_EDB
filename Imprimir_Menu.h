#ifndef IMPRIMIR_MENU_H
#define IMPRIMIR_MENU_H
#include "Fila.h"

/**
 * @brief Enumeração representando os itens do cardápio.
 * 
 * Este enum associa cada prato a um identificador único. Os pratos podem ser referenciados
 * por seus nomes dentro do programa, enquanto seus valores são representados por números inteiros.
 */
typedef enum{
    SOPA_DE_CEBOLA,
    SALADA_CAESAR,
    BRUSCHETTA,
    CARPACCIO_DE_CARNE,
    CAMARAO_AO_ALHO,
    LASANHA_A_BOLONHESA,
    FILE_MIGNON_COM_FRITAS,
    FRANGO_GRELHADO_COM_LEGUMES,
    BACALHAU_A_GOMES_DE_SA,
    RISOTO_DE_COGUMELOS,
    TIRAMISU,
    CHEESECAKE_DE_FRUTAS_VERMELHAS,
    MOUSSE_DE_CHOCOLATE,
    PUDIM_DE_LEITE,
    SORVETE_DE_BAUNILHA_COM_CALDA_DE_MORANGO,
} cardapio;

/**
 * @brief Imprime o menu correspondente ao ID do pedido.
 * 
 * @param idpedido O ID do pedido para o qual o menu deve ser impresso.
 * 
 * Esta função é responsável por exibir o prato correspondente ao ID fornecido.
 * O ID é um valor do tipo `cardapio`.
 */
void imprimir_menu(int idpedido);

/**
 * @brief Converte uma string que representa o nome de um prato para o tipo `cardapio`.
 * 
 * @param nome A string com o nome do prato.
 * @return O valor correspondente ao prato do tipo `cardapio`.
 * 
 * Esta função é usada para converter uma entrada de texto, como "Sopa de Cebola", 
 * em um valor do enum `cardapio` correspondente. Se o nome não corresponder a nenhum
 * prato, a função retornará um valor que indica erro (normalmente -1).
 */
cardapio string_para_prato(const char *nome);

/**
 * @brief Obtém o nome do prato correspondente a um ID de `cardapio`.
 * 
 * @param prato_id O ID do prato do tipo `cardapio`.
 * @return Uma string constante com o nome do prato.
 * 
 * Esta função converte um ID do enum `cardapio` em uma string legível com o nome do prato.
 */
const char* obter_nome_do_prato(cardapio prato_id);

/**
 * @brief Imprime o menu completo de todos os pratos disponíveis.
 * 
 * Esta função exibe uma lista de todos os pratos disponíveis no menu, com seus respectivos nomes.
 * Ela é útil para mostrar ao usuário as opções de pratos disponíveis para pedido.
 */
void impressao_do_menu();

/**
 * @brief Exibe uma mensagem para cada pedido na fila indicando que o pedido foi finalizado.
 * 
 * @param fila Um ponteiro para a fila de pedidos em processamento.
 * 
 * Esta função percorre a fila de pedidos e imprime uma mensagem indicando que cada pedido foi finalizado.
 * Ela também pode ser usada para limpar ou liberar a fila, dependendo da implementação.
 */
void pedido_finalizado(pedidos_processando *fila);

#endif