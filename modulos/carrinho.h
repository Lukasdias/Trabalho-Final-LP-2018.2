////////////////////////////////////////////////
///////////////FUNÇÕES CARRINHO/////////////////
////////////////////////////////////////////////
#ifndef CARRINHO_H
#define CARRINHO_H

#include "produtos.h"

struct produtoCarrinho{
    char nome[100];
    double preco;
    int qtd;
};

typedef struct {
    int tamanho;
    struct produtoCarrinho *produtos;
    double desconto;
    double descontoP;
    double preco;
    double precoFinal;
} Carrinho;

Carrinho *criar_carrinho();
void apagar_carrinho(Carrinho *);
void salvar_itens_carrinho(Carrinho *);
void popular_carrinho(Carrinho *, struct produtoCarrinho produto);
void adicionar_carrinho(Carrinho *, struct produtoCarrinho produto, int quantidade);
void remover_produto_carrinho(Carrinho *, int);
void add_carrinho(Carrinho *, Produtos *);
void delete_carrinho(Carrinho *);
void listar_Carrinho(Carrinho *);

Carrinho *criar_carrinho(){
    Carrinho *lista = (Carrinho *) malloc(sizeof(Carrinho));
    lista->tamanho = 0;
    lista->produtos = NULL;
    lista->desconto = 0;
    lista->descontoP = 0;
    lista->preco = 0;
    lista->precoFinal = 0;
    return lista;
}

void apagar_carrinho(Carrinho *lista){
    if (lista == NULL){
        printf("O carrinho precisa ser inicializado primeiro.\n");
        return;
    }
    free(lista->produtos);
    free(lista);
}

void popular_carrinho(Carrinho *lista, struct produtoCarrinho produto){
    if (lista == NULL){
       printf("O carrinho precisa ser inicializado primeiro.\n");
        return;
    }

    lista->produtos = (struct produtoCarrinho *) realloc(lista->produtos, (lista->tamanho + 1) * sizeof(struct produtoCarrinho));
    strcpy(lista->produtos[lista->tamanho].nome, produto.nome);
    lista->produtos[lista->tamanho].preco = produto.preco;
    lista->produtos[lista->tamanho].qtd = produto.qtd;
    lista->preco += produto.preco * produto.qtd;
    lista->precoFinal = lista->preco - ((lista->preco * lista->descontoP) / 100);
    lista->tamanho++;
}

void adicionar_carrinho(Carrinho *lista, struct produtoCarrinho produto, int quantidade){
    if (lista == NULL){
        printf("O carrinho precisa ser inicializado primeiro.\n");
        return;
    }

    lista->produtos = (struct produtoCarrinho *) realloc(lista->produtos, (lista->tamanho + 1) * sizeof(struct produtoCarrinho));
    strcpy(lista->produtos[lista->tamanho].nome, produto.nome);
    lista->produtos[lista->tamanho].preco = produto.preco;
    lista->produtos[lista->tamanho].qtd = quantidade;
    lista->preco += (produto.preco * quantidade);
    lista->precoFinal = lista->preco - ((lista->preco * lista->descontoP) / 100);
    lista->tamanho++;

    printf("Produtos adicionado ao carrinho!\n");

}

void definir_desconto(Carrinho *lista, int descontoP){
    if (lista == NULL){
        printf("O carrinho precisa ser inicializado primeiro.\n");
        return;
    }

    double desconto = (lista->preco * descontoP) / 100;
    lista->descontoP = descontoP;
    lista->desconto = desconto;
    lista->precoFinal = lista->preco - desconto;
}

void remover_produto_carrinho(Carrinho *lista, int id){
    if (lista == NULL){
        return;
    }

    lista->preco -= (lista->produtos[id].preco * lista->produtos[id].qtd);
    lista->precoFinal = lista->preco - ((lista->preco * lista->descontoP) / 100);

    for (; id < lista->tamanho - 1; id++){
        lista->produtos[id] = lista->produtos[id + 1];
    }
    lista->produtos = (struct produtoCarrinho *) realloc(lista->produtos, (lista->tamanho - 1) * sizeof(struct produtoCarrinho));
    lista->tamanho--;
}

void add_carrinho(Carrinho *lista, Produtos *lista_p){
   struct produtoCarrinho produto;
    int i, quantidade;

    system("cls");
    printf("=================================Loja NerdZ====================================\n");
    printf("==================================Carrinho=====================================\n");
    printf("===============================================================================\n");

    printf("Informe o nome do produto a ser adicionado ao carrinho: ");
    scanf("%[^\n]*c", produto.nome);
    fflush(stdin);
    for(i = 0; i < lista_p->tamanho; i++){
        if (strcmp(lista_p->produtos[i].nome, produto.nome) == 0){
            printf("Produto localizado!\n");
            produto.preco = lista_p->produtos[i].valor;
            printf("Quantos %s deseja adicionar? ", produto.nome);
            scanf("%d", &quantidade);
            fflush(stdin);
            while((lista_p->produtos[i].qtd - quantidade) < 0){
                printf("Quantidade requisitada maior que a disponivel\n");
                printf("Voce pediu %d unidades, sendo que nos temos apenas %d unidades\n", quantidade, lista_p->produtos[i].qtd);
                printf("Digite a quantidade novamente!\n");
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                fflush(stdin);
            };
            lista_p->produtos[i].qtd -= quantidade;
            printf("definir desconto de: ");
            scanf("%d", &lista->desconto);
            fflush(stdin);
            while((lista->desconto > 100)){
                printf("O produto ja esta de gratuito com esse desconto senhor!\n");
                printf("Digite (100 %) ou uma quantia menor!");
                printf("Desconto: ");
                scanf("%d", &lista->desconto);
                fflush(stdin);
            }
            adicionar_carrinho(lista, produto, quantidade);
            definir_desconto(lista, lista->desconto);
            system("pause");
            return;
        }
    }

    if (i == lista_p->tamanho){
        printf("Produto nao encontrado");
        return;
    }


}

void delete_carrinho(Carrinho *lista){
    struct produtoCarrinho produto;
    int i;
    system("cls");
    printf("=================================Loja NerdZ====================================\n");
    printf("==================================Carrinho=====================================\n");
    printf("==================================DELETAR======================================\n");

    printf("Informe o nome do produto a ser removido do carrinho: ");
    scanf("%[^\n]*c", produto.nome);
    for(i = 0; i < lista->tamanho; i++){
        if (strcmp(lista->produtos[i].nome, produto.nome) == 0){
            remover_produto_carrinho(lista, i);
            printf("Produto removido!\n");
            system("pause");
            return;
        }
    }
    printf("Produto nao encontrado\n");
    system("pause");
}

void listar_Carrinho(Carrinho *lista){
    int i, t;

    if (lista == NULL){
        printf("Lista vazia\n");
        return;
    }
    system("cls");
    printf("=================================Loja NerdZ====================================\n");
    printf("==================================Carrinho=====================================\n");
    printf("===================================LISTAR======================================\n");

    for(i = 0; i < lista->tamanho;i++){
        printf("Produto no Carrinho %d\n", i + 1);
        printf("Nome: %s\n", lista->produtos[i].nome);
        printf("Valor: %.2lf\n", lista->produtos[i].preco);
        printf("Quantidade requisitada: %d\n", lista->produtos[i].qtd);
        printf("===============================================================================\n");
    }
    if (i == lista->tamanho){
            printf("*************************\n");
            printf("Valor total %lf\n", lista->precoFinal);
            printf("*************************\n");
            t = 1;
    }
    system("pause");

}

#endif
