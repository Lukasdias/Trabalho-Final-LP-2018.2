#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "bin/clientes.h"
#include "bin/produtos.h"
// Função que retorna o número de produtos ou clientes, parametro k indica o quantos itens um produtos recebe por padrão //
int sizeMeP(FILE *arq, int k);
int sizeMeC(FILE *arq, int k);

void menuLoja();
void cleanMe();
void printfS(produtos *ptr);

//Função main que só possui uma função sendo chamada dentro dela(menuLoja chama várias outras funções dentro de si//
int main(void){
    int tamanhoListaC = sizeMeC(bancoClientes, 6);
    fullMe_P(novoProduto, estoqueProdutos);
    //menuLoja();
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
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                ler_Cliente(bancoClientes);
                break;
            }
            case 6:{
                ler_Produto(novoProduto, estoqueProdutos);
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