#include <stdio.h>
#include <stdlib.h>

///////////////////////////////
typedef struct cliente {
    char name[50];
    char adress[128];
    char phone[12];
    char city[20];
    char country[15];
} clientes;

int tamanhoListaC;

FILE *bancoClientes;
clientes *novoCliente = NULL;

void fullMe_C(clientes *ptr, FILE *arq);
void criar_Cliente(clientes *ptr, FILE *arq);
void editar_Cliente();
void remove_Cliente();
void ler_Cliente(FILE *arq);

int sizeMeC(FILE *arq, int k){

    arq = fopen("bank/bancoClientes.txt", "r");
    char *c = (char*) malloc(25000 * sizeof(char));

    int linhas = 0;

    if (arq == NULL){
        return -1;
    }
    else{
       while((fgets(c, 25000, arq))!=NULL){
                ++linhas;
       }
    }
    int total = linhas/k;
    return (total);
    fclose(arq);
}

////////////////////////////////////////////////////
////////////////FUNÇÕES CLIENTES///////////////////
//////////////////////////////////////////////////

/////////Função para acrescentar clientes///////
void criar_Cliente(clientes *ptr, FILE *arq){
     system("cls");
     arq = fopen("bank/bancoClientes.txt", "a");
     tamanhoListaC = sizeMeC(arq, 6);
     ptr = (clientes *) realloc(ptr, (tamanhoListaC + 1 * sizeof(clientes)));

     if (arq == NULL){
         printf("arquivo não existe");
     }
     else{

            printf("==================Loja NerdZ=======================\n");
            printf("==================Menu Cliente=====================\n");
            printf("==================Novo Cliente=====================\n");
            printf("***************************************************\n\n");
            //fprintf(arq, "Cliente: %d\n", tamanhoListaC + 1);

            printf("Nome: ");
            fflush(stdin);
            fgets(ptr[tamanhoListaC].name, 50, stdin);
            fflush(stdin);
            fprintf(arq, "%s", ptr[tamanhoListaC].name);

            printf("Endereço: ");
            fflush(stdin);
            fgets(ptr[tamanhoListaC].adress, 128, stdin);
            fflush(stdin);
            fprintf(arq, "%s", ptr[tamanhoListaC].adress);

            printf("Numero de telefone: ");
            fflush(stdin);
            fgets(ptr[tamanhoListaC].phone, 12, stdin);
            fflush(stdin);
            fprintf(arq, "%s", ptr[tamanhoListaC].phone);

            printf("Sua Cidade: ");
            fflush(stdin);
            fgets(ptr[tamanhoListaC].city, 20, stdin);
            fflush(stdin);
            fprintf(arq, "%s", ptr[tamanhoListaC].city);

            printf("Nacionalidade: ");
            fflush(stdin);
            fgets(ptr[tamanhoListaC].country, 15, stdin);
            fflush(stdin);
            fprintf(arq, "%s", ptr[tamanhoListaC].country);

            printf("Novo Cliente Cadastrado!");
            tamanhoListaC++;
            system("pause");
            fclose(arq);
     }
}

//Função que imprime todos os clientes cadastrados na Loja NerdZ//
void ler_Cliente(FILE *arq){
    system("cls");

     arq = fopen("bank/bancoClientes.txt", "r");
     char *dadosClientes = (char *) malloc (100 * sizeof(char));

     printf("==================Loja NerdZ=======================\n");
     printf("==================Menu Cliente=====================\n");
     printf("==================Ler Cliente=====================\n");
     printf("***************************************************\n\n");

    if (arq == NULL){
        printf("arquivo não existe");
    }
    else {
      while((fgets(dadosClientes, sizeof(dadosClientes), arq))!=NULL){
            printf("%s", dadosClientes);
        }
    }
    printf("Pressione qualquer tecla para voltar ao menu!");
    system("pause");
    fclose(arq);

}

//Função para editar os dados dos Clientes//
void editar_Cliente(){
}

//Função para apagar Clientes cadastrados//
void remove_Cliente(){
}
