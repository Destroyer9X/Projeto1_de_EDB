#include "Lista_Pedidos.h"
#include "imprimir_menu.h"
#include "Fila.h"

#include <string.h>
#include <ctype.h>  // Necessário para tolower

void impressao_do_menu() {
    printf(" _____________________________________________\n");
    printf("< Olá, bem-vindo ao restaurante Hack 'n' Cheese >\n");
    printf(" -----------------------------------------------\n");
    printf("        \\   \n");
    printf("         \\  ─────█─▄▀█──█▀▄─█─────\n");
    printf("          \\ ────▐▌──────────▐▌────\n");
    printf("           \\────█▌▀▄──▄▄──▄▀▐█────\n");
    printf("            ───▐██──▀▀──▀▀──██▌───\n");
    printf("            ──▄████▄──▐▌──▄████▄──\n\n");
    printf("CARDÁPIO\n");
    printf("Entradas\n");
    printf("\t1. Sopa de Cebola.\n\t2. Salada Caesar.\n\t3. Bruschetta.\n\t4. Carpaccio de Carne.\n\t5. Camarão ao Alho.\n");
    printf("Pratos Principais\n");
    printf("\t1. Lasanha à Bolonhesa.\n\t2. Filé Mignon com Fritas.\n\t3. Frango Grelhado com Legumes.\n\t4. Bacalhau à Gomes de Sá.\n\t5. Risoto de Cogumelos.\n");
    printf("Sobremesas\n");
    printf("\t1. Tiramisu.\n\t2. Cheesecake de Frutas Vermelhas.\n\t3. Mousse de Chocolate.\n\t4. Pudim de Leite.\n\t5. Sorvete de Baunilha com Calda de Morango.\n\n\n");
}

cardapio string_para_prato(const char* nome_do_prato) {
    // Criar uma cópia da string original em minúsculas
    char nome_minusculo[100];
    int i = 0;

    while (nome_do_prato[i]) {
        nome_minusculo[i] = tolower(nome_do_prato[i]);
        i++;
    }
    nome_minusculo[i] = '\0';  // Finalizar a string

    // Comparar a string convertida
    if (strcmp(nome_minusculo, "sopa de cebola") == 0) return SOPA_DE_CEBOLA;
    if (strcmp(nome_minusculo, "salada caesar") == 0) return SALADA_CAESAR;
    if (strcmp(nome_minusculo, "bruschetta") == 0) return BRUSCHETTA;
    if (strcmp(nome_minusculo, "carpaccio de carne") == 0) return CARPACCIO_DE_CARNE;
    if (strcmp(nome_minusculo, "camarao ao alho") == 0) return CAMARAO_AO_ALHO;
    if (strcmp(nome_minusculo, "lasanha a bolonhesa") == 0) return LASANHA_A_BOLONHESA;
    if (strcmp(nome_minusculo, "file mignon com fritas") == 0) return FILE_MIGNON_COM_FRITAS;
    if (strcmp(nome_minusculo, "frango grelhado com legumes") == 0) return FRANGO_GRELHADO_COM_LEGUMES;
    if (strcmp(nome_minusculo, "bacalhau a gomes de sa") == 0) return BACALHAU_A_GOMES_DE_SA;
    if (strcmp(nome_minusculo, "risoto de cogumelos") == 0) return RISOTO_DE_COGUMELOS;
    if (strcmp(nome_minusculo, "tiramisu") == 0) return TIRAMISU;
    if (strcmp(nome_minusculo, "cheesecake de frutas vermelhas") == 0) return CHEESECAKE_DE_FRUTAS_VERMELHAS;
    if (strcmp(nome_minusculo, "mousse de chocolate") == 0) return MOUSSE_DE_CHOCOLATE;
    if (strcmp(nome_minusculo, "pudim de leite") == 0) return PUDIM_DE_LEITE;
    if (strcmp(nome_minusculo, "sorvete de baunilha com calda de morango") == 0) return SORVETE_DE_BAUNILHA_COM_CALDA_DE_MORANGO;

    // Se não encontrar o prato, retornar um valor inválido
    return -1;
}

const char* nome_do_prato(cardapio prato) {
    switch (prato) {
        case SOPA_DE_CEBOLA: return "Sopa de Cebola";
        case SALADA_CAESAR: return "Salada Caesar";
        case BRUSCHETTA: return "Bruschetta";
        case CARPACCIO_DE_CARNE: return "Carpaccio de Carne";
        case CAMARAO_AO_ALHO: return "Camarão ao Alho";
        case LASANHA_A_BOLONHESA: return "Lasanha à Bolonhesa";
        case FILE_MIGNON_COM_FRITAS: return "Filé Mignon com Fritas";
        case FRANGO_GRELHADO_COM_LEGUMES: return "Frango Grelhado com Legumes";
        case BACALHAU_A_GOMES_DE_SA: return "Bacalhau à Gomes de Sá";
        case RISOTO_DE_COGUMELOS: return "Risoto de Cogumelos";
        case TIRAMISU: return "Tiramisu";
        case CHEESECAKE_DE_FRUTAS_VERMELHAS: return "Cheesecake de Frutas Vermelhas";
        case MOUSSE_DE_CHOCOLATE: return "Mousse de Chocolate";
        case PUDIM_DE_LEITE: return "Pudim de Leite";
        case SORVETE_DE_BAUNILHA_COM_CALDA_DE_MORANGO: return "Sorvete de Baunilha com Calda de Morango";
        default: return "Prato Desconhecido";
    }
}

void pedido_finalizado(pedidos_processando *fila) {

    printf("\n╔════════════════════════════════════════════╗\n");
    printf("║              PEDIDOS FINALIZADOS!          ║\n");
    printf("╠════════════════════════════════════════════╣\n");

    while (fila) {
        // Obter o nome do prato para o ID atual
        const char* nome_do_prato = obter_nome_do_prato(fila->pedidos);
        printf("║ %-40s   ║\n", nome_do_prato);
        fila = fila->proximo;
    }

    printf("╚════════════════════════════════════════════╝\n");
    printf("\nObrigado por aguardar. Aqui estão os seus pratos! Tenha um bom apetite!\n");
}
const char* obter_nome_do_prato(cardapio prato_id) {
    return nome_do_prato(prato_id);
}