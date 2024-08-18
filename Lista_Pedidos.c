#include "lista_pedidos.h"
#include "Imprimir_Menu.h"

/**
 * @brief Inicializa a lista ligada como uma lista vazia.
 * 
 * @param lista Um ponteiro duplo para a lista que será inicializada.
 * 
 * Esta função simplesmente define o ponteiro inicial da lista como `NULL`, indicando que a lista está vazia.
 */
void inicializar(pendente **lista){
    *lista = NULL;
}

/**
 * @brief Adiciona um novo pedido ao final da lista ligada.
 * 
 * @param lista Um ponteiro duplo para a lista onde o pedido será adicionado.
 * @param valor O ID do prato que será adicionado à lista.
 * 
 * Esta função aloca memória para um novo nó e insere esse nó no final da lista ligada.
 * Se a lista estiver vazia, o novo nó se torna o primeiro elemento.
 */
void adicionar(pendente **lista, int valor){
    pendente *novo = (pendente*) malloc(sizeof(pendente)); //Aloca memória para o novo nó.
    novo->valor = valor; //Atribui o valor do pedido ao novo nó.
    novo->proximo = NULL; //O próximo nó será NULL, pois este será o último nó da lista.

    if (*lista == NULL){
        //Se a lista estiver vazia, o novo pedido é o primeiro.
        *lista = novo;
    }
    else{
        //Encontrar o último nó da lista.
        pendente *atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        //Adiciona o novo pedido no final da lista.
        atual->proximo = novo;
    }
}

/**
 * @brief Exibe todos os pedidos presentes na lista ligada.
 * 
 * @param lista Um ponteiro para a lista que será percorrida e exibida.
 * 
 * Esta função itera pela lista e, para cada nó, imprime o nome do prato correspondente ao valor armazenado.
 * A função `obter_nome_do_prato` é usada para converter o valor do pedido em um nome legível.
 */
void lista_pendente(pendente *lista){
    pendente *atual = lista; //Começa no início da lista.
    while (atual != NULL){
        //Converte o valor para o nome do prato usando a função obter_nome_do_prato.
        const char* nome_do_prato = obter_nome_do_prato(atual->valor);
        printf("%s\n", nome_do_prato); // Imprime o nome do prato.
        atual = atual->proximo; // Move para o próximo nó.
    }
}

/**
 * @brief Remove um pedido específico da lista ligada.
 * 
 * @param lista Um ponteiro duplo para a lista de onde o pedido será removido.
 * @param valor O ID do prato que será removido da lista.
 * 
 * A função percorre a lista para encontrar o nó que corresponde ao `valor` e, se encontrado, o remove.
 * Se o nó a ser removido for o primeiro na lista, a função ajusta o ponteiro da lista para o próximo nó.
 * Caso contrário, ela ajusta os ponteiros para manter a continuidade da lista.
 */
void remover(pendente **lista, int valor){
    pendente *atual = *lista; //Começa no início da lista.
    pendente *anterior = NULL; //Mantém o nó anterior para ajuste de ponteiros.

    //Encontrar o nó a ser removido.
    while (atual != NULL && atual->valor != valor){
        anterior = atual; //Avança o ponteiro anterior.
        atual = atual->proximo; //Avança para o próximo nó.
    }

    //Se o nó não foi encontrado.
    if (atual == NULL){
        printf("Esse pedido não foi feito.\n");
        return;
    }

    //Remover o nó encontrado.
    if (anterior == NULL){
        //O nó a ser removido é o primeiro nó da lista.
        *lista = atual->proximo;
    }
    else{
        //O nó a ser removido está no meio ou no final da lista.
        anterior->proximo = atual->proximo;
    }

    //Liberar a memória do nó removido.
    free(atual);
    printf("O pedido %d foi removido com sucesso!\n", valor);
}