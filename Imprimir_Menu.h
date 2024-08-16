#ifndef IMPRIMIR_MENU_H
#define IMPRIMIR_MENU_H
 
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
}cardapio;

void imprimir_menu(int idpedido);
cardapio string_para_prato(const char *nome);
const char* obter_nome_do_prato(cardapio prato_id);



#endif
