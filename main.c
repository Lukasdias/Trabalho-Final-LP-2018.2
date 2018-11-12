/*///////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
//////////////////////////
#include "bin/clientes.h"
#include "bin/produtos.h"
// Função que retorna o número de produtos ou clientes, parametro k indica o quantos itens um produtos recebe por padrão //
void menuLoja();
void cleanMe();
//Função main que só possui uma função sendo chamada dentro dela(menuLoja chama várias outras funções dentro de si//
int main(void){
    fullMe_C(novoCliente, bancoClientes);
    setlocale(LC_ALL, "Portuguese");
    fullMe_P(novoProduto, estoqueProdutos);
    //simprimir(novoProduto, estoqueProdutos);
    menuLoja();
}
//Função para limpar a tela(usada frequentemente)//
void cleanMe(){
    system("cls");
}
//Função Menu que organiza as decisões do usuário//
void menuLoja(){
    int menuFlag;
    int continuar = true;
    while (continuar == true){
        cleanMe();
        printf("=========================Loja NerdZ====================\n");
        printf("============================Menu=======================\n");
        printf("[0] = Sair\n");
        printf("[1] = acrescentar clientes\n");
        printf("[2] = acrescentar produtos\n");
        printf("[3] = remover clientes\n");
        printf("[4] = remover produtos\n");
        printf("[5] = ver clientes\n");
        printf("[6] = ver produtos\n");
        printf("[7] = editar clientes\n");
        printf("[8] = editar produtos\n");
        //printf("[9] = ver carrinho\n");
        printf("========================================================\n");
		printf("Sua Escolha: ");
        scanf("%d", &menuFlag);
        fflush(stdin);

        switch(menuFlag){
            case 1:{
                criar_Cliente(novoCliente, bancoClientes);
                break;
            }
            case 2:{
                criar_Produto(novoProduto, estoqueProdutos);
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                //ler_Cliente(bancoClientes);
                break;
            }
            case 6:{
                ler_Produto(novoProduto, estoqueProdutos);
                break;
            }
            case 7:{
                break;
            }
            case 8:{
                break;
            }
            case 9:{
                break;
            }
            case 0:{
                printf("saindo...\n");
                continuar = false;
                break;
            }
            default:{
               break;
            }

        }
    }

}
*/

#include <stdio.h>
#include "bin/clientes.h"

void menu(Clientes *);
void add(Clientes *);
void list(Clientes *);

int main(void){
    Clientes *lista;
    lista = criar_clientes();
    popular_clientes(lista);
    menu(lista);
    apagar_clientes(lista);
}

void menu(Clientes *lista){
    int ch;
    do {
        system("cls");
        printf("----- MENU -----\n");
        printf("(1) - Adicionar Cliente\n");
        printf("(2) - Remover Cliente\n");
        printf("(3) - Listar Clientes\n");
        printf("(0) - Sair\n");

        scanf("%d", &ch);

        switch (ch){
            case 1:
                add(lista);
                break;
            case 2:
                break;
            case 3:
                list(lista);
                break;
        }
    } while(ch != 0);
}

void add(Clientes *lista){
    struct cliente cliente;
    
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]*c", cliente.name);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%[^\n]*c", cliente.phone);
    fflush(stdin);
    printf("Endereco: ");
    scanf("%[^\n]*c", cliente.address);
    fflush(stdin);
    printf("Cidade: ");
    scanf("%[^\n]*c", cliente.city);
    fflush(stdin);
    printf("Estado: ");
    scanf("%[^\n]*c", cliente.estado);
    fflush(stdin);

    adicionar_clientes(lista, cliente);
}

void list(Clientes *lista){
    int i;
    for (i = 0; i < lista->tamanho; i++){
        printf("Cliente %d\n", i);
        printf("Nome: %s\n", lista->clientes[i].name);
        printf("Telefone: %s\n", lista->clientes[i].phone);
        printf("Endereco: %s\n", lista->clientes[i].address);
        printf("Cidade: %s\n", lista->clientes[i].city);
        printf("Estado: %s\n", lista->clientes[i].estado);
    }

    system("pause");
}