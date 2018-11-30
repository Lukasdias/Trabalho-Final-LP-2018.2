#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <locale.h>
#include "modulos/clientes.h"
#include "modulos/produtos.h"
#include "modulos/carrinho.h"
#include "modulos/vendas.h"

void menu(Clientes *, Produtos *, Carrinho *, Vendas *);
void menuProduto(Produtos *);
void menuCliente(Clientes *);
void menuVendas(Carrinho *, Produtos *, Vendas *, Clientes *);
//void menuCarrinho(Carrinho *lista);

void addC(Clientes *);
void addP(Produtos *);

void listC(Clientes *);
void listP(Produtos *);

void editP(Produtos *);
void editC(Clientes *);

int deleteP(Produtos *);
int deleteC(Clientes *);

int main(void){
    setlocale(LC_ALL,"");
    system ("color F9");

    Clientes *lista_c;
    Produtos *lista_p;
    Carrinho *lista_carrinho;
    Vendas *lista_vendas;

    lista_c = criar_clientes();
    lista_p = criar_produtos();
    lista_carrinho = criar_carrinho();
    lista_vendas = criar_vendas();


    popular_clientes(lista_c);
    popular_produtos(lista_p);

    menu(lista_c, lista_p, lista_carrinho, lista_vendas);

    //printf(COLOR_RESET);
}

void menu(Clientes *lista_C, Produtos *lista_P, Carrinho *lista_Carrinho, Vendas *lista_vendas){
    int podeContinuar = true, ch;
     while(podeContinuar == true){
         system("cls");
         printf("==================================Loja NerdZ===================================\n");
         printf("\t [1] *** Menu Produtos\n");
         printf("\t [2] *** Menu Clientes\n");
         printf("\t [3] *** Menu Compra\n");
         printf("\t [0] *** Salvar && Sair (somente aqui e possivel salvar os dados)\n");
         printf("===============================================================================\n");
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
            case 3:
                menuVendas(lista_Carrinho, lista_P, lista_vendas, lista_C);
                break;
            case 0:
                podeContinuar = false;
                armazenar_clientes(lista_C);
                armazenar_produtos(lista_P);
                salvar_vendas(lista_vendas);
                //system("pause");
                break;
        }
     }
}

void menuProduto(Produtos *lista){
    int podeContinuar = true, ch;
     while(podeContinuar == true){
        system("cls");
         printf("==================================Loja NerdZ===================================\n");
         printf("[1] *** Adicionar produtos\n");
         printf("[2] *** Remover Produtos\n");
         printf("[3] *** Listar Produtos\n");
         printf("[4] *** Editar Produtos\n");
         printf("[0] *** Voltar ao menu principal\n");
         printf("===============================================================================\n");
         printf("Escolha: ");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch){
            case 1:
                addP(lista);
                break;
            case 2:
                deleteP(lista);
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
    while(podeContinuar == true){

    system("cls");
    printf("==================================Loja NerdZ===================================\n");
    printf("[1] *** Adicionar Clientes\n");
    printf("[2] *** Remover Clientes\n");
    printf("[3] *** Listar Clientes\n");
    printf("[4] *** Editar Clientes\n");
    printf("[0] *** Voltar ao menu principal\n");
    printf("===============================================================================\n");
    printf("Escolha: ");
    scanf("%d", &ch);
    fflush(stdin);

        switch (ch){
            case 1:
                addC(lista);
                break;
            case 2:
                deleteC(lista);
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

void menuVendas(Carrinho *lista, Produtos *listaP, Vendas *lista_vendas, Clientes *lista_c){
    int podeContinuar = true,ch;

    while(podeContinuar == true){
        system("cls");
        printf("==================================Loja NerdZ===================================\n");
        printf("[1] *** Adicionar no Carrinho\n");
        printf("[2] *** Remover do Carrinho\n");
        printf("[3] *** Listar Carrinho\n");
        printf("[4] *** Realizar Compra\n");
        printf("[5] *** Listar compras ja realizadas\n");
        printf("[6] *** Gerar relatorio das compras feitas no dia\n");
        printf("[0] *** Voltar ao menu principal\n");
        printf("===============================================================================\n");
        printf("Escolha: ");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch){
                case 1:
                    add_carrinho(lista, listaP);
                    break;
                case 2:
                    delete_carrinho(lista, listaP);
                    break;
                case 3:
                    listar_Carrinho(lista);
                    break;
                case 4:
                    realizar_venda(lista_vendas, lista, lista_c);
                    break;
                case 5:
                    listar_venda(lista_vendas, lista);
                    break;
                case 6:
                    relatorio_do_dia(lista_vendas, lista);
                    break;
                case 0:
                    podeContinuar = false;
                    break;
            }
}
}


