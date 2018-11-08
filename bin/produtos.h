////////////////////////////////////
typedef struct produtos {
    char name[30];
    int amount;
    float price;
    int promotion_section;
} produtos;

FILE *estoqueProdutos;
produtos *novoProduto = NULL;


void criar_Produto();
void ler_Produto();
void remove_Produto();
void editar_Produto();
void addCarrinho();
int ver_carrinho();
//////////////////////////////////
