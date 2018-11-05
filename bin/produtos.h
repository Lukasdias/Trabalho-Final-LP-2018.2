////////////////////////////////////
typedef struct produtos {
    char name[30];
    int amount;
    double price;
    int promotion_section;
} produtos;


produtos *listaProdutos = NULL;
FILE *estoqueProdutos;
void criar_prod();
void mostrar_prod();
void remove_prod();
void addCarrinho();
int ver_carrinho();
//////////////////////////////////