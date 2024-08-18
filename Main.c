//Bibliotecas padrão de C para manipulação de strings, entrada/saída, conversões e operações de memória.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include "Imprimir_Menu.h"
#include "Lista_Pedidos.h"
#include "Fila.h"

//Supondo que a função de conversão de id para nome do prato seja renomeada para evitar conflito.
const char* obter_nome_do_prato(cardapio prato_id);

int main() {
    //Declaração de ponteiros para a lista de pedidos e a fila de processamento.
    pendente* lista_pedidos = NULL;
    pedidos_processando* filaProcessamento = NULL;
    
    //Configura o terminal para usar o código de página UTF-8 (apenas para sistemas Windows).
    system("chcp 65001");

    //Imprime o menu inicial na tela.
    impressao_do_menu();

    //Inicializa a lista de pedidos como uma lista vazia.
    inicializar(&lista_pedidos);

    int opcao;  //Variável para armazenar a escolha do usuário no menu.
    char nome_do_prato[50];  //Buffer para armazenar o nome do prato inserido pelo usuário.

    do {
        //Exibe as opções do menu para o usuário.
        printf("\nO que você deseja, senhor?\n");
        printf("\t 0 - Finalizar o atendimento.\n\t 1 - Fazer um pedido.\n\t 2 - Ver os meus pedidos pendentes.\n\t 3 - Remover um pedido.\n");
        scanf("%d", &opcao);
        getchar();  //Consumir o caractere de nova linha residual para evitar problemas ao ler strings.

        switch(opcao){
        case 1:
            //Opção para fazer um pedido.
            printf("Digite o nome do prato que você deseja: ");
            fgets(nome_do_prato, sizeof(nome_do_prato), stdin);  //Lê o nome do prato inserido pelo usuário.
            nome_do_prato[strcspn(nome_do_prato, "\n")] = 0;  //Remove o caractere de nova linha capturado pelo fgets.

            //Converte o nome do prato para um ID correspondente usando uma função de mapeamento.
            cardapio prato_id = string_para_prato(nome_do_prato);
    
            if(prato_id != -1){
                //Se o prato for válido, adiciona à lista de pedidos.
                adicionar(&lista_pedidos, prato_id);
                printf("Prato adicionado à lista de pedidos: %s\n", obter_nome_do_prato(prato_id));
            } 
            else{
                //Se o prato não for reconhecido, exibe uma mensagem de erro.
                printf("Prato desconhecido!\n");
            }
            break;
        case 2:
            //Opção para listar os pedidos pendentes.
            printf("\nSeus pedidos pendentes:\n");
            lista_pendente(lista_pedidos);
            break;
        case 3:
            //Opção para remover um pedido da lista.
            printf("Digite o nome do prato a remover: ");
            fgets(nome_do_prato, sizeof(nome_do_prato), stdin);
            nome_do_prato[strcspn(nome_do_prato, "\n")] = 0;

            prato_id = string_para_prato(nome_do_prato);  //Converte o nome do prato para o ID.
            if(prato_id != -1){
                //Se o prato for válido, remove-o da lista.
                remover(&lista_pedidos, prato_id);
            } 
            else{
                //Se o prato não for reconhecido, exibe uma mensagem de erro.
                printf("Prato desconhecido!\n");
            }
            break;

        default:
            //Se o usuário selecionar uma opção inválida, exibe uma mensagem de erro.
            if(opcao != 0){
                printf("Opção inválida!\n");
            }
            break;
        }
    } while(opcao != 0);  //Continua exibindo o menu até o usuário escolher finalizar o atendimento.
    
    //Transfere os pedidos pendentes da lista para a fila de processamento.
    inserir_da_lista_para_fila(lista_pedidos, &filaProcessamento);

    //Lista os pedidos que estão na fila de processamento.
    listarprocessamento(filaProcessamento);
    
    //Imprime o status final dos pedidos.
    pedido_finalizado(filaProcessamento);

    return 0;
}