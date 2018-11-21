///////////////////////////////////////////////
///////////////FUNÇÕES VENDAS/////////////////
/////////////////////////////////////////////
#ifndef VENDAS_H
#define VENDAS_H

#include "clientes.h"
#include "carrinho.h"

struct comprador {
    char nome[100];
    char endereco[210];
    char telefone[15];
};

struct venda {
    int id;
    struct comprador cliente;
    Carrinho carrinho;
};

typedef struct {
    int tamanho;
    struct venda *vendas;
} Vendas;

Vendas *criar_vendas();
void apagar_vendas(Vendas *lista);
void popular_vendas(Vendas *lista);
void salvar_vendas(Vendas *lista);
void adicionar_venda(Vendas *lista, struct comprador cliente, Carrinho *carrinho);
void remover_venda(Vendas *lista, int);
void relizar_vendas(Vendas *lista, Carrinho *, Clientes *);
void listar_vendas(Vendas *lista);
int tamanhoArquivo3(const char* );

Vendas *criar_vendas(){
    Vendas *lista = (Vendas *) malloc(sizeof(Vendas));
    lista->tamanho = 0;
    lista->vendas = NULL;
    return lista;
}

void apagar_vendas(Vendas *lista){
    if (lista == NULL){
        printf("Lista nao existe");
        return;
    }

    free(lista->vendas);
    free(lista);
}


void salvar_vendas(Vendas *lista){
    int i, j;
    char horario[9];
    char data[9];
    FILE *arquivo;
    arquivo = fopen("dados/vendas.txt", "w");

    fprintf(arquivo, "%d\n", lista->tamanho);
    for (i = 0; i < lista->tamanho; i++){
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.nome);
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.endereco);
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.telefone);
        fprintf(arquivo, "%d\n", lista->vendas[i].carrinho.tamanho);

        for (j = 0; j < lista->vendas[i].carrinho.tamanho; j++){
            fprintf(arquivo, "%s\n", lista->vendas[i].carrinho.produtos[j].nome);
            fprintf(arquivo, "%lf\n", lista->vendas[i].carrinho.produtos[j].preco);
            fprintf(arquivo, "%d\n", lista->vendas[i].carrinho.produtos[j].qtd);
        }
        fprintf(arquivo, "%lf\n", lista->vendas[i].carrinho.preco);
        fprintf(arquivo, "%lf\n", lista->vendas[i].carrinho.precoFinal);
    }

    fclose(arquivo);
}

void adicionar_venda(Vendas *lista, struct comprador cliente, Carrinho *carrinho){
    if (!lista){
        fprintf(stderr, "As vendas precisam ser inicializadas primeiro.\n");
        return;
    }

    lista->vendas = (struct venda *) realloc(lista->vendas, (lista->tamanho + 1) * sizeof(struct venda));
    lista->vendas[lista->tamanho].cliente = cliente;
    lista->vendas[lista->tamanho].carrinho = *carrinho;
    lista->tamanho++;
}

void remover_venda(Vendas *lista, int id){
    for (; lista->tamanho < lista->tamanho - 1; id++)
        lista->vendas[id] = lista->vendas[id + 1];
    lista->vendas = (struct venda *) realloc(lista->vendas, (lista->tamanho - 1) * sizeof(struct venda));
    lista->tamanho--;
}

int tamanhoArquivo3(const char* nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL)
        return 0; // função deve retornar um inteiro//

    fseek(arquivo, 0, SEEK_END);
    int tamanho = ftell(arquivo);
    fclose(arquivo);

    return tamanho;
}

void realizar_venda(Vendas *lista, Carrinho *lista_carrinho, Clientes *lista_c){
    if (listar_Carrinho == NULL || listar_Carrinho == 0){
        printf("Carrinho vazio!\n");
        system("pause");
    }
    int i;
    struct comprador cliente;
    printf("Confirmaçao de usuario\n");
    printf("Digite seu nome: ");
    scanf("%[^\n]*c", cliente.nome);
    fflush(stdin);

    for(i = 0; i < lista_c->tamanho; i++){
        if(strcmp(lista_c->clientes[i].nome, cliente.nome) == 0){
            printf("Cliente localizado!\n");
            printf("Bem vindo %s\n", cliente.nome);
            strcpy(cliente.endereco, lista_c->clientes[i].endereco);
            strcpy(cliente.telefone, lista_c->clientes[i].telefone);
            adicionar_venda(lista, cliente, lista_carrinho);
            printf("Venda realizada!\n");
            system("pause");
            return;
        }
    }
}

void listar_venda(Vendas *lista){
    int i, j;
    if (lista == NULL){
        printf("Lista nao foi iniciada");
        return;
    }
    if (lista->tamanho == 0){
        printf("Carrinho vazio");
        return;
    }
    for (i = 0; i < lista->tamanho; i++){
        printf("Nome do cliente: %s\n", lista->vendas[i].cliente.nome);
        printf("Endereco: %s\n", lista->vendas[i].cliente.endereco);
        printf("Telefone: %s\n", lista->vendas[i].cliente.telefone);
        printf("Itens no carrinho: %d\n", lista->vendas[i].carrinho.tamanho);
        for(j = 0; j < carrinho.tamanho; j++){
            printf("Produtos: %s\n", lista->vendas[i].carrinho.produtos[j].nome);
            printf("Valor: %.2lf\n", lista->vendas[i].carrinho.produtos[j].preco);
            printf("Quantidade: %d\n", lista->vendas[i].carrinho.produtos[j].qtd);
        }
    }

    system("pause");
} 

#endif
