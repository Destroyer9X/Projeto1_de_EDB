#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include "imprimir_menu.h"
#include "Lista_Pedidos.h"


// Supondo que a função de conversão de id para nome do prato seja renomeada para evitar conflito
const char* obter_nome_do_prato(cardapio prato_id);

int main() {
    pendente* lista_pedidos;
    
    system("chcp 65001");

    impressao_do_menu();

    inicializar(&lista_pedidos);
    int opcao;
    char nome_do_prato[50];

    do {
        printf("O que você deseja senhor ?\n");
        printf("\t 0 - Finalizar o atendimento.\n\t 1 - Fazer um pedido.\n\t 2 - Ver os meus pedidos.\n\t 3 - Remover um pedido.\n");
        scanf("%d", &opcao);
        getchar();  // Consumir o caractere de nova linha residual

        switch (opcao) {
        case 1:
            printf("Digite o nome do prato que voce deseja: ");
            fgets(nome_do_prato, sizeof(nome_do_prato), stdin);
            // Remover o caractere de nova linha capturado pelo fgets
            nome_do_prato[strcspn(nome_do_prato, "\n")] = 0;

            cardapio prato_id = string_para_prato(nome_do_prato);
    
            if (prato_id != -1) {
                adicionar(&lista_pedidos, prato_id);
                printf("Prato adicionado a lista de pedidos: %s\n", obter_nome_do_prato(prato_id));
            } else {
                printf("Prato desconhecido!\n");
            }
            break;
        case 2:
            printf("\nSeus pedidos:\n");
            lista_pendente(lista_pedidos);
            break;
           break;
        case 3:
            // Código para remover um pedido
            printf("Digite o nome do prato a remover: ");
            fgets(nome_do_prato, sizeof(nome_do_prato), stdin);
            // Remover o caractere de nova linha capturado pelo fgets
            nome_do_prato[strcspn(nome_do_prato, "\n")] = 0;

            prato_id = string_para_prato(nome_do_prato);
            if (prato_id != -1) {
                remover(&lista_pedidos, prato_id);
            } else {
                printf("Prato desconhecido!\n");
            }
            break;

        default:
            if (opcao != 0) {
                printf("Opcao invalida!\n");
            }
            break;
        }
    } while (opcao != 0);

    printf("\nLista de pedidos:\n");
    lista_pendente(lista_pedidos);

    return 0;
}