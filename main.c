#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bin/clientes.h"
#include "bin/produtos.h"


int main(void){
    menuLoja();
}
//Função para limpar a tela(usada frequentemente)//
void cleanMe(){
    system("cls");
}
//Função para os produtos serem adicionados a loja!//
void criar_prod(){
    cleanMe();
     estoqueProdutos = fopen("bank/estoqueProdutos.txt", "a");
     if (estoqueProdutos == NULL){
         printf("merda");
     }
     printf("==================Loja NerdZ=======================\n");
     printf("==================Menu Produto=====================\n");
     printf("==================Novo Produto=====================\n");
     printf("***************************************************\n\n");
    int i = 0, n, add = 0;

    listaProdutos = (produtos *) realloc(listaProdutos, (i + 1) * sizeof(produtos));

    printf("Nome: ");
    fflush(stdin);
    fgets(listaProdutos[i].name, 60, stdin);
    fflush(stdin);
    fprintf(estoqueProdutos, "Nome do Produto: %s", listaProdutos[i].name);

    printf("Preco: ");
    scanf("%lf", &listaProdutos[i].price);
    fflush(stdin);
    fprintf(estoqueProdutos, "Preco do Produto: %.2f \n", listaProdutos[i].price);


    printf("Quantidade disponivel: ");
    scanf("%d", &listaProdutos[i].amount);
    fflush(stdin);
    fprintf(estoqueProdutos, "Quantidade disponivel: %d unidades \n\n", listaProdutos[i].amount);



    i++;
    fclose(estoqueProdutos);
}
//Função para exibir todos os produtos e seus dados)//
void mostrar_prod(){
    int i = 0;
    char *texto = (char *) malloc (100*sizeof(char));
    estoqueProdutos = fopen("bank/estoqueProdutos.txt", "r");
    if (listaProdutos == NULL){
        printf("merda");
    }
    else{
        listaProdutos = (produtos *) realloc(listaProdutos, (i + 1) * sizeof(produtos));
        while(fscanf(estoqueProdutos, "Nome do Produto : %s", &listaProdutos[i].name)!= NULL){
                printf("Nome do Produto :%s", texto);
                i++;
        }
    }
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
        printf("[7] = acrescentar produtos ao carrinho\n");
        printf("[8] = remover produtos do carrinho\n");
        printf("[9] = ver carrinho\n");
        printf("========================================================\n");
		printf("Sua Escolha: ");
        scanf("%d", &menuFlag);
        fflush(stdin);


        switch(menuFlag){
            case 1:{
                break;
            }
            case 2:{
                criar_prod();
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                //mostrar_prod();
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
