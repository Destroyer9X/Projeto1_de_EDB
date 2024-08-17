#include "lista_pedidos.h"
#include "Imprimir_Menu.h"


void inicializar(pendente **lista) {
    *lista = NULL;
};

void adicionar(pendente **lista, int valor) {
    pendente *novo = (pendente*) malloc(sizeof(pendente));
    novo->valor = valor;
    novo->proximo = *lista;
    *lista = novo;
};

void lista_pendente(pendente *lista) {
    pendente *atual = lista;
    while (atual != NULL) {
        // Converte o valor para o nome do prato usando a função obter_nome_do_prato
        const char* nome_do_prato = obter_nome_do_prato(atual->valor);
        printf("%s\n", nome_do_prato);
        atual = atual->proximo;
    }
}


void remover(pendente **lista, int valor) {
    pendente *atual = *lista;
    pendente *anterior = NULL;

    // Encontrar o nó a ser removido
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se o nó não foi encontrado
    if (atual == NULL) {
        printf("Esse pedido não foi feito.\n");
        return;
    }

    // Remover o nó encontrado
    if (anterior == NULL) {
        // O nó a ser removido é o primeiro nó da lista
        *lista = atual->proximo;
    } else {
        // O nó a ser removido está no meio ou no final da lista
        anterior->proximo = atual->proximo;
    }

    // Liberar a memória do nó removido
    free(atual);
    printf("O pedido %d foi removido com sucesso!\n", valor);
}

void processar(pendente **lista) {
   
};



