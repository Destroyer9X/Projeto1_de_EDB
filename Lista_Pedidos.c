#include "lista_pedidos.h"



void inicializar(pendente **lista) {
    *lista = NULL;
};

void adicionar(pendente **lista, int valor) {
    pendente *novo = (pendente*) malloc(sizeof(pendente));
    novo->valor = valor;
    novo->proximo = *lista;
    *lista = novo;
};

void lista_pendente( pendente *lista) {
     pendente *atual = lista;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
};

void remover(pendente **lista, int valor) {
    pendente *atual = *lista;
    pendente *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Esse pedido nâo foi feito \n", valor);
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("O pedido %d  foi removido com sucesso !!.\n", valor);
};

void processar(pendente **lista) {
   
};



