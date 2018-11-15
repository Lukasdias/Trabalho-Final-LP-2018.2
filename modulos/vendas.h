///////////////////////////////////////////////
///////////////FUNÇÕES VENDAS/////////////////
/////////////////////////////////////////////
struct carrinho{
    int tamanho;
}

typedef struct{
    int tamanho;
    struct cliente *clientes;
    struct produto *produtos;
    struct carrinho *carrinho;
}Compras;

Compras *nova_compra();

void armazenar_compras(Compras *);
void popular_compras(Compras *);
void salvar_compras(Compras *);
void adicionar_compras(Compras *, struct carrinho);
void apagar_compra(Compras *);

int tamanhoArquivo(const char* nome_arquivo);

Compras *nova_compra(){
    Compras *lista = (Compras *) malloc(sizeof(Compras));
    lista->tamanho = 0;
    lista->clientes = NULL;
    lista->produtos = NULL;
    lista->carrinho = NULL;
    return lista;
}

void armazenar_compras(Compras *lista){
    if (lista == NULL){
        return;
    }
    salvar_compras(lista);
    free(lista->clientes);
    free(lista->produtos);
    free(lista->carrinho);
    free(lista);
}

void adicionar_compras(Compras *lista, struct carrinho){
    if(lista == NULL){
        return;
    }
}