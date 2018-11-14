#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modulos/clientes.h"
#include "modulos/produtos.h"

void menuProduto(Produtos *lista);
void menuCliente(Clientes *lista);
void addC(Clientes *);
void listC(Clientes *);
void addP(Produtos *);
void listP(Produtos *);

int main(void){
    Clientes *lista_a;
    Produtos *lista_b;

    lista_a = criar_clientes();
    lista_b = criar_produtos();

    popular_clientes(lista_a);
    popular_produtos(lista_b);

    menuProduto(lista_b);
    menuCliente(lista_a);

    apagar_clientes(lista_a);
    apagar_produtos(lista_b);
}

void menuProduto(Produtos *lista){
    int podeContinuar = true, ch;

     while(podeContinuar == true){
        system("cls");
        printf("----- MENU PRODUTO -----\n");
        printf("[1] - Adicionar Produto\n");
        printf("[2] - Remover Produto\n");
        printf("[3] - Listar Produto\n");
        printf("[0] - Salvar e Sair\n");

        printf("Escolha: ");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch){
            case 1:
                addP(lista);
                break;
            case 2:
                break;
            case 3:
                listP(lista);
            case 0:
                podeContinuar = false;
                //system("pause");
                break;
        }
    }
}

void menuCliente(Clientes *lista){
    int podeContinuar = true, ch;
        system("cls");
     while(podeContinuar == true){
        system("cls");
        printf("----- MENU Cliente -----\n");
        printf("[1] - Adicionar Cliente\n");
        printf("[2] - Remover Cliente\n");
        printf("[3] - Listar Cliente\n");
        printf("[0] - Salvar e Sair\n");

        printf("Escolha: ");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch){
            case 1:
                addC(lista);
                break;
            case 2:
                break;
            case 3:
                listC(lista);
            case 0:
                podeContinuar = false;
                break;
        }
    }
}
void addC(Clientes *lista){
    struct cliente cliente;
    system("cls");
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]*c", cliente.nome);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%[^\n]*c", cliente.telefone);
    fflush(stdin);
    printf("Endereco: ");
    scanf("%[^\n]*c", cliente.endereco);
    fflush(stdin);
    printf("Cidade: ");
    scanf("%[^\n]*c", cliente.cidade);
    fflush(stdin);
    printf("Estado: ");
    scanf("%[^\n]*c", cliente.estado);
    fflush(stdin);

    adicionar_clientes(lista, cliente);
    system("pause");
}

void listC(Clientes *lista){
    int i;
    system("cls");
    for (i = 0; i < lista->tamanho; i++){
        printf("Cliente %d\n", i);
        printf("Nome: %s\n", lista->clientes[i].nome);
        printf("Telefone: %s\n", lista->clientes[i].telefone);
        printf("Endereco: %s\n", lista->clientes[i].endereco);
        printf("Cidade: %s\n", lista->clientes[i].cidade);
        printf("Estado: %s\n", lista->clientes[i].estado);
    }
    system("pause");
}

void addP(Produtos *lista){
    struct produto produto;
    system("cls");
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]*c", produto.nome);
    fflush(stdin);
    printf("Valor: ");
    scanf("%lf", &produto.valor);
    fflush(stdin);
    printf("Qtd em estoque: ");
    scanf("%d", &produto.qtd);
    fflush(stdin);
    adicionar_produtos(lista, produto);
}

void listP(Produtos *lista){
    int i;
    system("cls");
    for (i = 0; i < lista->tamanho; i++){
        printf("Produto %d\n", i + 1);
        printf("Nome: %s\n", lista->produtos[i].nome);
        printf("Valor %lf\n", lista->produtos[i].valor);
        printf("Quantidade em estoque: %d\n", lista->produtos[i].qtd);
    }
    system("pause");
}
