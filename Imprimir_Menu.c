#include "Lista_Pedidos.h"
#include "imprimir_menu.h"

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
