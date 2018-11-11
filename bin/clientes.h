///////////////////////////////
typedef struct cliente {
    char name[50];
    char adress[128];
    char phone[12];
    char city[20];
    char country[15];
} clientes;
///////QTD CLIENTES CADASTRADOS/////////
int tamanhoListaC;
////////PONTEIROS///////////
FILE *bancoClientes;
clientes *novoCliente = NULL;
////////////////FUNÇÕES///////////////////
///////////////DECLARAÇÕES////////////////
int sizeMeC(FILE *arq, int k);
void fullMe_C(clientes *ptr, FILE *arq);
void criar_Cliente(clientes *ptr, FILE *arq);
void editar_Cliente();
void remove_Cliente();
void ler_Cliente(FILE *arq);
////////////////FUNÇÕES///////////////////
///////////////DEFINIÇÕES////////////////
//Função para saber quantos clientes existem no arquivo//
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

//Função para acrescentar clientes//
void criar_Cliente(clientes *ptr, FILE *arq){
     system("cls");
     arq = fopen("bank/bancoClientes.txt", "a");
     tamanhoListaC = sizeMeC(arq, 6);
     ptr = (clientes *) realloc(ptr, ((tamanhoListaC + 1) * sizeof(clientes)));

     if (arq == NULL){
         printf("arquivo não existe");
     }
     else{

            printf("==================Loja NerdZ=======================\n");
            printf("==================Menu Cliente=====================\n");
            printf("==================Novo Cliente=====================\n");
            printf("***************************************************\n\n");
            fprintf(arq, "%d\n", tamanhoListaC + 1);

            printf("Nome: ");
            scanf("%[^\n]s", ptr[tamanhoListaC].name);
            fflush(stdin);
            fprintf(arq, "%s\n", ptr[tamanhoListaC].name);

            printf("Endereço: ");
            scanf("%[^\n]s", ptr[tamanhoListaC].adress);
            fflush(stdin);
            fprintf(arq, "%s\n", ptr[tamanhoListaC].adress);

            printf("Numero de telefone: ");
            scanf("%[^\n]s", ptr[tamanhoListaC].phone);
            fflush(stdin);
            fprintf(arq, "%s\n", ptr[tamanhoListaC].phone);

            printf("Sua Cidade: ");
            scanf("%[^\n]s", ptr[tamanhoListaC].city);
            fflush(stdin);
            fprintf(arq, "%s\n", ptr[tamanhoListaC].city);

            printf("Nacionalidade: ");
            scanf("%[^\n]s", ptr[tamanhoListaC].country);
            fflush(stdin);
            fprintf(arq, "%s\n", ptr[tamanhoListaC].country);

            printf("Novo Cliente Cadastrado!");
            tamanhoListaC++;
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
//Função pra preencher uma struct a partir de um arquivo já preenchido//
void fullMe_C(clientes *ptr, FILE *arq){
    arq = fopen("bank/bancoClientes.txt", "r");
    clientes past_ptr;
    int tamanhoListaC = sizeMeC(arq, 6), i = 0;
    int a = 0;

    if(arq == NULL){
        printf("arquivo não existe, pressione qualquer tecla para retornar ao menu");
        system("wait");
    }

    else{
            while (fscanf(arq, "%d ", &a) != EOF){

                fscanf(arq, "%[^\n]*c\n", past_ptr.name);
                fscanf(arq, "%[^\n]*c\n", past_ptr.adress);
                fscanf(arq, "%[^\n]*c\n", past_ptr.phone);
                fscanf(arq, "%[^\n]*c\n", past_ptr.city);
                fscanf(arq, "%[^\n]*c\n", past_ptr.country);

                ptr = (clientes *) realloc(ptr, (i + 1) * sizeof(clientes));

                strcpy(ptr[i].name, past_ptr.name);
                strcpy(ptr[i].adress, past_ptr.adress);
                strcpy(ptr[i].phone, past_ptr.phone);
                strcpy(ptr[i].city, past_ptr.city);
                strcpy(ptr[i].country, past_ptr.country);

                printf("%d %s %s %s %s %s\n", a, ptr[i].name, ptr[i].adress, ptr[i].phone, ptr[i].city, ptr[i].country);
                //i++;
            }
        getch(); 
        fclose(arq);
    }
}
