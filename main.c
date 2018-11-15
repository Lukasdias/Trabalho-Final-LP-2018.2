#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "modulos/clientes.h"
#include "modulos/produtos.h"

//#define COLOR_RED "\x1b[31m"
//#define COLOR_RESET "\x1b[0m"

void menu(Clientes *lista_C, Produtos *lista_P);
void menuProduto(Produtos *lista);
void menuCliente(Clientes *lista);

void addC(Clientes *);
void addP(Produtos *);
void listC(Clientes *);
void listP(Produtos *);
void editP(Produtos *);
void editC(Clientes *);

int deleteP(Produtos *, const char* nomeProduto);
int deleteC(Clientes *, const char* nomeCliente);

int main(void){
    system("color 12");

    Clientes *lista_c;
    Produtos *lista_p;

    lista_c = criar_clientes();
    lista_p = criar_produtos();

    popular_clientes(lista_c);
    popular_produtos(lista_p);

    menu(lista_c, lista_p);

    //printf(COLOR_RESET);
}

void menu(Clientes *lista_C, Produtos *lista_P){
    int podeContinuar = true, ch;
     while(podeContinuar == true){
         system("cls");
         printf("============Loja NerdZ============\n");
         printf("[1] *** menu produtos\n");
         printf("[2] *** menu clientes\n");
         printf("[3] *** historico de compras");
         printf("[0] *** salvar sair (somente aqui e possivel salvar dados)\n");
         printf("==================================\n");
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
    char *dados = (char *) malloc (100 * sizeof(char));

     while(podeContinuar == true){
        system("cls");
         printf("============Loja NerdZ============\n");
         printf("[1] *** Adicionar produtos\n");
         printf("[2] *** Remover Produtos\n");
         printf("[3] *** Listar Produtos\n");
         printf("[4] *** Editar Produtos\n");
         printf("[0] *** voltar ao menu principal\n");
         printf("===================================\n");
         printf("Escolha: ");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch){
            case 1:
                addP(lista);
                break;
            case 2:
                system("cls");
                printf("******MENU PRODUTO******\n");
                printf("*****DELETAR PRODUTO****\n");
                printf("informe o nome a ser buscado: ");
                scanf("%[^\n]*c", dados);
                deleteP(lista, dados);
                break;
            case 3:
                listP(lista);
                break;
            case 4:
                editP(lista);
                break;
            case 0:
                podeContinuar = false;
                //system("pause");
                break;
        }
    }
}

void menuCliente(Clientes *lista){
    int podeContinuar = true, ch;
    char *dados = (char *) malloc (100 * sizeof(char));
     system("cls");
     while(podeContinuar == true){

        system("cls");
         printf("============Loja NerdZ============\n");
         printf("[1] *** Adicionar Clientes\n");
         printf("[2] *** Remover Clientes\n");
         printf("[3] *** Listar Clientes\n");
         printf("[4] *** Editar Clientes\n");
         printf("[0] *** voltar ao menu principal\n");
         printf("===================================\n");
        printf("Escolha: ");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch){
            case 1:
                addC(lista);
                break;
            case 2:
                system("cls");
                printf("====MENU CLIENTE====\n");
                printf("===DELETAR CLIENTE===\n");
                printf("Informe o nome do cliente a ser buscado: ");
                scanf("%[^\n]*c", dados);
                deleteC(lista, dados);
                break;
            case 3:
                listC(lista);
                break;
            case 4:
                editC(lista);
                break;
            case 0:
                podeContinuar = false;
                break;
        }
    }
}

