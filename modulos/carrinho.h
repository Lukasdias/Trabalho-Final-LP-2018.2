////////////////////////////////////////////////
///////////////FUNÇÕES CARRINHO/////////////////
////////////////////////////////////////////////
#ifndef CARRINHO_H
#define CARRINHO_H

#include "produtos.h"

struct vendas{
    int id;
    char nome[100];
    double valorInicial;
    int qtd;
};

typedef struct {
    int tamanho;
    struct vendas *produtos;
    double desconto;
    double descontoP;
    double valorInicial;
    double valorFinal;
} Carrinho;

Carrinho *criar_carrinho();
void salvar_itens_carrinho(Carrinho *);
void adicionar_ao_carrinho(Carrinho *);
void salvar_carrinho(Carrinho *);
void adicionar_itens_carrinho(Carrinho *, struct vendas produto, int quantidade);

Carrinho *criar_carrinho(){
    Carrinho *lista = (Carrinho *) malloc(sizeof(Carrinho));
    lista->tamanho = 0;
    lista->desconto = 0.00;
    lista->descontoP = 0.00;
    lista->valorInicial = 0.00;
    lista->valorFinal = 0.00;
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

void add_vendido_carrinho(Carrinho *lista, struct vendas produto){
    if (lista == NULL){
       printf("O carrinho precisa ser inicializado primeiro.\n");
        return;
    }

    lista->produtos = (struct vendas *) realloc(lista->produtos, (lista->tamanho + 1) * sizeof(struct vendas));
    lista->produtos[lista->tamanho].id = lista->tamanho;
    strcpy(lista->produtos[lista->tamanho].nome, produto.nome);
    lista->produtos[lista->tamanho].valorInicial = produto.valorInicial;
    lista->produtos[lista->tamanho].qtd = produto.qtd;
    lista->valorInicial += produto.valorInicial * produto.qtd;
    lista->valorFinal = lista->valorInicial - ((lista->valorInicial * lista->descontoP) / 100);
    lista->tamanho++;
}

void adicionar_itens_carrinho(Carrinho *lista, struct vendas produto, int quantidade){
    if (lista == NULL){
        printf("O carrinho precisa ser inicializado primeiro.\n");
        return;
    }

    lista->produtos = (struct vendas *) realloc(lista->produtos, (lista->tamanho + 1) * sizeof(struct vendas));
    lista->produtos[lista->tamanho].id = lista->tamanho;
    strcpy(lista->produtos[lista->tamanho].nome, produto.nome);
    lista->produtos[lista->tamanho].valorInicial = produto.valorInicial;
    lista->produtos[lista->tamanho].qtd = quantidade;
    lista->valorInicial += produto.valorInicial * quantidade;
    lista->valorFinal = lista->valorInicial - ((lista->valorInicial * lista->descontoP) / 100);
    lista->tamanho++;
    printf("Produtos localizado e adicionado ao carrinho!\n");

}

void remover_produto_carrinho(Carrinho *lista, int index){
    if (lista == NULL){
        printf("O carrinho precisa ser inicializado primeiro.\n");
        return;
    }

    lista->valorInicial -= lista->produtos[index].valorInicial;
    lista->valorFinal = lista->valorInicial - ((lista->valorInicial * lista->descontoP) / 100);

    for (; index < lista->tamanho - 1; index++){
        lista->produtos[index] = lista->produtos[index + 1];
    }
    lista->produtos = (struct vendas *) realloc(lista->produtos, (lista->tamanho - 1) * sizeof(struct vendas));
    lista->tamanho--;
}

void definir_desconto(Carrinho *lista, int descontoP){
    if (!lista){
        printf("O carrinho precisa ser inicializado primeiro.\n");
        return;
    }

    double desconto = (double) (lista->valorInicial * descontoP) / 100;
    lista->descontoP = descontoP;
    lista->desconto = desconto;
    lista->valorFinal = lista->valorInicial - desconto;
}

#endif
