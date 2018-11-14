#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modulos/clientes.h"
#include "modulos/produtos.h"

#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"

void menu(Clientes *lista_C, Produtos *lista_P);
void menuProduto(Produtos *lista);
void menuCliente(Clientes *lista);
void addC(Clientes *);
void listC(Clientes *);
void addP(Produtos *);
void listP(Produtos *);
void editP(Produtos *);
int main(void){
    Clientes *lista_c;
    Produtos *lista_p;

    lista_c = criar_clientes();
    lista_p = criar_produtos();

    popular_clientes(lista_c);
    popular_produtos(lista_p);

    menu(lista_c, lista_p);

    printf(COLOR_RESET);
}

void menu(Clientes *lista_C, Produtos *lista_P){
    int podeContinuar = true, ch;
     while(podeContinuar == true){

         system("cls");
         printf(COLOR_RED "Loja NerdZ\n");
         printf("[1] - menu produtos\n");
         printf("[2] - menu clientes\n");
         printf("[0] - salvar sair\n");
         printf("Escolha: ");
         scanf("%d", &ch);
         fflush(stdin);

         switch (ch){
            case 1:
                menuProduto(lista_P);
                break;
            case 2:
                menuCliente(lista_C);
                break;
            case 0:
                podeContinuar = false;
                armazenar_clientes(lista_C);
                armazenar_produtos(lista_P);
                //system("pause");
                break;
        }
     }
}

void menuProduto(Produtos *lista){
    int podeContinuar = true, ch;

     while(podeContinuar == true){
        system("cls");
        printf("----- MENU PRODUTO -----\n");
        printf("[1] - Adicionar Produto\n");
        printf("[2] - Remover Produto\n");
        printf("[3] - Listar Produto\n");
        printf("[4] - Editar Produto\n");
        printf("[0] - Voltar para o Menu Principal\n");
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
                break;
            case 4:
                editP(lista);
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
        printf("-------------MENU Cliente---------\n");
        printf("[1] - Adicionar Cliente\n");
        printf("[2] - Remover Cliente\n");
        printf("[3] - Listar Cliente\n");
        printf("[0] - Voltar para o Menu Principal\n");
        printf("-------------------------------------\n");
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
                break;
            case 0:
                podeContinuar = false;
                break;
        }
    }
}

