#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "modulos/clientes.h"
#include "modulos/produtos.h"

void menu(Clientes *lista_C, Produtos *lista_P);
void menuProduto(Produtos *lista);
void menuCliente(Clientes *lista);
void addC(Clientes *);
void listC(Clientes *);
void addP(Produtos *);
void listP(Produtos *);
void editP(Produtos *);
int main(void){
    //Mudando Cor do Terminal//
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

    Clientes *lista_c;
    Produtos *lista_p;

    lista_c = criar_clientes();
    lista_p = criar_produtos();

    popular_clientes(lista_c);
    popular_produtos(lista_p);

    menu(lista_c, lista_p);

}

void menu(Clientes *lista_C, Produtos *lista_P){
    int podeContinuar = true, ch;
     while(podeContinuar == true){

         system("cls");
         printf("Loja NerdZ\n");
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
        printf("[4] - Editar Produto");
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

