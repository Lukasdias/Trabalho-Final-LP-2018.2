#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "bin/clientes.h"
#include "bin/produtos.h"

void menuLoja();
void restart_C();
void restart_P();
int tamanhoListaC = 0, tamanhoListaP = 0;
//Função main que só possui uma função sendo chamada dentro dela(menuLoja chama várias outras funções dentro de si//
int main(void){
    menuLoja();
}

//Função para limpar a tela(usada frequentemente)//
void cleanMe(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//Função para os produtos serem adicionados a loja!//
void criar_Produto(){
    cleanMe();
     estoqueProdutos = fopen("bank/estoqueProdutos.txt", "a");
     novoProduto = (produtos *) realloc(novoProduto, (tamanhoListaP + 1 * sizeof(produtos)));
     if (estoqueProdutos == NULL){
         printf("Arquivo não existe");
     }
     else{
            printf("==================Loja NerdZ=======================\n");
            printf("==================Menu Produto=====================\n");
            printf("==================Novo Produto=====================\n");
            printf("***************************************************\n\n");
            printf("Nome: ");
            fflush(stdin);
            fgets(novoProduto[tamanhoListaP].name, 60, stdin);
            fflush(stdin);
            fprintf(estoqueProdutos, "Nome do Produto: %s", novoProduto[tamanhoListaP].name);

            printf("Preco: ");
            scanf("%f", &novoProduto[tamanhoListaP].price);
            fflush(stdin);
            fprintf(estoqueProdutos, "Preco do Produto: %.2f \n", novoProduto[tamanhoListaP].price);


            printf("Quantidade disponivel: ");
            scanf("%d", &novoProduto[tamanhoListaP].amount);
            fflush(stdin);
            fprintf(estoqueProdutos, "Quantidade disponivel: %d unidades \n", novoProduto[tamanhoListaP].amount);
            fprintf(estoqueProdutos, "======================================\n");

            printf("Novo Produto Cadastrado!");
            tamanhoListaP++;
            fclose(estoqueProdutos);
     }
}

//Função para exibir todos os produtos e seus dados)//
void ler_Produto(){
    cleanMe();
    char *dadosProdutos = (char *) malloc (100 * sizeof(char));
    estoqueProdutos = fopen("bank/estoqueProdutos.txt", "r");
     printf("==================Loja NerdZ=======================\n");
     printf("==================Menu Produto=====================\n");
     printf("==================Ler Produtos=====================\n");
     printf("***************************************************\n\n");

    if (estoqueProdutos == NULL){
        printf("arquivo não existe");
    }
    else {
        while((fgets(dadosProdutos, sizeof(dadosProdutos), estoqueProdutos))!=NULL){
            printf("%s", dadosProdutos);
        }
    }
    printf("Pressione qualquer tecla para voltar ao menu!");
    getch();
    fclose(estoqueProdutos);
}

//Função para editar produtos já cadastrados na Loja//
void editar_Produto(){
    cleanMe();
    printf("===================Loja NerdZ=======================\n");
    printf("==================Menu Produto=====================\n");
    printf("=================Editar Produtos=====================\n");
    printf("***************************************************\n\n");

    estoqueProdutos = fopen("bank/estoqueProdutos.txt", "r+");


}

//Função para apagar produtos cadastrados//
void remove_Produto(){
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
                criar_Cliente();
                break;
            }
            case 2:{
                criar_Produto();
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                ler_Cliente();
                break;
            }
            case 6:{
                ler_Produto();
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

//Função para acrescentar clientes//
void criar_Cliente(){

     cleanMe();
     bancoClientes = fopen("bank/bancoClientes.txt", "a");
     novoCliente = (clientes *) realloc(novoCliente, (tamanhoListaC + 1 * sizeof(clientes)));
     if (bancoClientes == NULL){
         printf("arquivo não existe");
     }
     else{

            printf("==================Loja NerdZ=======================\n");
            printf("==================Menu Cliente=====================\n");
            printf("==================Novo Cliente=====================\n");
            printf("***************************************************\n\n");

            printf("Nome: ");
            fflush(stdin);
            fgets(novoCliente[tamanhoListaC].name, 50, stdin);
            fflush(stdin);
            fprintf(bancoClientes, "%s", novoCliente[tamanhoListaC].name);

            printf("Endereço: ");
            fflush(stdin);
            fgets(novoCliente[tamanhoListaC].adress, 128, stdin);
            fflush(stdin);
            fprintf(bancoClientes, "%s", novoCliente[tamanhoListaC].adress);

            printf("Numero de telefone: ");
            fflush(stdin);
            fgets(novoCliente[tamanhoListaC].phone, 12, stdin);
            fflush(stdin);
            fprintf(bancoClientes, "%s", novoCliente[tamanhoListaC].phone);

            printf("Sua Cidade: ");
            fflush(stdin);
            fgets(novoCliente[tamanhoListaC].city, 20, stdin);
            fflush(stdin);
            fprintf(bancoClientes, "%s", novoCliente[tamanhoListaC].city);

            printf("Nacionalidade: ");
            fflush(stdin);
            fgets(novoCliente[tamanhoListaC].country, 15, stdin);
            fflush(stdin);
            fprintf(bancoClientes, "%s", novoCliente[tamanhoListaC].country);
            fprintf(bancoClientes, "======================================\n");

            printf("Novo Cliente Cadastrado!");
            tamanhoListaC++;
            //getch();
            fclose(bancoClientes);
     }
}

//Função que imprime todos os clientes cadastrados na Loja NerdZ//
void ler_Cliente(){
     cleanMe();

     bancoClientes = fopen("bank/bancoClientes.txt", "r");
     char *dadosClientes = (char *) malloc (100 * sizeof(char));

     printf("==================Loja NerdZ=======================\n");
     printf("==================Menu Cliente=====================\n");
     printf("==================Ler Cliente=====================\n");
     printf("***************************************************\n\n");

    if (bancoClientes == NULL){
        printf("arquivo não existe");
    }
    else {
      while((fgets(dadosClientes, sizeof(dadosClientes), bancoClientes))!=NULL){
            printf("%s", dadosClientes);
        }
    }
    printf("\nPressione qualquer tecla para voltar ao menu!");
    getch();
    fclose(bancoClientes);

}

//Função para editar os dados dos Clientes//
void editar_Cliente(){
}

//Função para apagar Clientes cadastrados//
void remove_Cliente(){
}

