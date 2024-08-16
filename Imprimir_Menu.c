#include "Lista_Pedidos.h"
#include "imprimir_menu.h"

#include <string.h>

// Função para converter string em ID do prato
cardapio string_para_prato(const char* nome_do_prato) {
    if (strcmp(nome_do_prato, "Sopa de Cebola") == 0) return SOPA_DE_CEBOLA;
    if (strcmp(nome_do_prato, "Salada Caesar") == 0) return SALADA_CAESAR;
    if (strcmp(nome_do_prato, "Bruschetta") == 0) return BRUSCHETTA;
    if (strcmp(nome_do_prato, "Carpaccio de Carne") == 0) return CARPACCIO_DE_CARNE;
    if (strcmp(nome_do_prato, "Camarão ao Alho") == 0) return CAMARAO_AO_ALHO;
    if (strcmp(nome_do_prato, "Lasanha à Bolonhesa") == 0) return LASANHA_A_BOLONHESA;
    if (strcmp(nome_do_prato, "Filé Mignon com Fritas") == 0) return FILE_MIGNON_COM_FRITAS;
    if (strcmp(nome_do_prato, "Frango Grelhado com Legumes") == 0) return FRANGO_GRELHADO_COM_LEGUMES;
    if (strcmp(nome_do_prato, "Bacalhau à Gomes de Sá") == 0) return BACALHAU_A_GOMES_DE_SA;
    if (strcmp(nome_do_prato, "Risoto de Cogumelos") == 0) return RISOTO_DE_COGUMELOS;
    if (strcmp(nome_do_prato, "Tiramisu") == 0) return TIRAMISU;
    if (strcmp(nome_do_prato, "Cheesecake de Frutas Vermelhas") == 0) return CHEESECAKE_DE_FRUTAS_VERMELHAS;
    if (strcmp(nome_do_prato, "Mousse de Chocolate") == 0) return MOUSSE_DE_CHOCOLATE;
    if (strcmp(nome_do_prato, "Pudim de Leite") == 0) return PUDIM_DE_LEITE;
    if (strcmp(nome_do_prato, "Sorvete de Baunilha com Calda de Morango") == 0) return SORVETE_DE_BAUNILHA_COM_CALDA_DE_MORANGO;

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

const char* obter_nome_do_prato(cardapio prato_id) {
    
    return nome_do_prato(prato_id);
}

