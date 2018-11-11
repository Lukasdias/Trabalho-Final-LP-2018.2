////////////////////////////////////
typedef struct produtos {
    char name[30];
    int amount;
    float price;
    int promotion_section;
} produtos;
int tamanhoListaP;
////////PONTEIROS///////////
FILE *estoqueProdutos;
produtos *novoProduto = NULL;
////////////////FUNÇÕES///////////////////
///////////////DECLARAÇÕES////////////////
void imprimir(produtos *ptr, FILE *arq);
int sizeMeP(FILE *arq, int k);
void fullMe_P(produtos *ptr, FILE *arq);
void criar_Produto(produtos *ptr, FILE *arq);
void ler_Produto(produtos *ptr, FILE *arq);
void remove_Produto();
void editar_Produto();
void addCarrinho();
int ver_carrinho();
////////////////FUNÇÕES///////////////////
///////////////DEFINIÇÕES////////////////
int sizeMeP(FILE *arq, int k){

    arq = fopen("bank/estoqueProdutos.txt", "r");

    char *c = (char *) malloc(50 * sizeof(char));
    int linhas = 0;

    if (arq == NULL){
        return -1;
    }
    else {
        while((fgets(c, 50, arq))!=NULL){
                ++linhas;
        }
    }
    int total = linhas/k;
    return (total);
    fclose(arq);
}
//Função para os produtos serem adicionados a loja!//
void criar_Produto(produtos *ptr, FILE *arq){
    system("cls");

    int tamanhoListaP = sizeMeP(estoqueProdutos, 4);

     arq = fopen("bank/estoqueProdutos.txt", "a");

     ptr = (produtos *) realloc(ptr, ((tamanhoListaP + 1) * sizeof(produtos)));

     if (arq == NULL){
         printf("Arquivo não existe");
     }
     else{
            printf("==================Loja NerdZ=======================\n");
            printf("==================Menu Produto=====================\n");
            printf("==================Novo Produto=====================\n");
            printf("***************************************************\n");

            fprintf(arq, "%d\n", tamanhoListaP + 1);

            printf("Nome: ");
            scanf("%[^\n]s", ptr[tamanhoListaP].name);
            fflush(stdin);
            fprintf(arq, "%s\n", ptr[tamanhoListaP].name);

            printf("Preco: ");
            scanf("%f", &ptr[tamanhoListaP].price);
            fflush(stdin);
            fprintf(arq, "%.2f\n", ptr[tamanhoListaP].price);

            printf("Quantidade disponivel: ");
            scanf("%i", &ptr[tamanhoListaP].amount);
            fflush(stdin);
            fprintf(arq, "%i\n", ptr[tamanhoListaP].amount);

            printf("Novo Produto Cadastrado!");
            getch();
            tamanhoListaP++;
            fclose(arq);
     }
}
//Função para exibir todos os produtos e seus dados)//
void ler_Produto(produtos *ptr, FILE *arq){
    system("cls");

    char *dadosProdutos = (char *) malloc (100 * sizeof(char));

    arq = fopen("bank/estoqueProdutos.txt", "r");

     printf("==================Loja NerdZ=======================\n");
     printf("==================Menu Produto=====================\n");
     printf("==================Ler Produtos=====================\n");
     printf("***************************************************\n\n");

    if (arq == NULL){
        printf("arquivo não existe");
    }
    else {
        while((fgets(dadosProdutos, sizeof(dadosProdutos), arq))!=NULL){
            printf("%s", dadosProdutos);
        }
    }
    printf("Pressione qualquer tecla para voltar ao menu!");
    getch();
    fclose(arq);
}
//Função para editar produtos já cadastrados na Loja//
void editar_Produto(){
    system("cls");
    printf("===================Loja NerdZ=======================\n");
    printf("==================Menu Produto=====================\n");
    printf("=================Editar Produtos=====================\n");
    printf("***************************************************\n\n");

    estoqueProdutos = fopen("bank/estoqueProdutos.txt", "r+");


}
//Função para apagar produtos cadastrados//
void remove_Produto(){
}
//Função para preencher a struct a partir de um arquivo já existente//
void fullMe_P(produtos *ptr, FILE *arq){
    arq = fopen("bank/estoqueProdutos.txt", "r");
    produtos past_ptr;
    int tamanhoListaP = sizeMeP(arq, 4), i = 0;
    int a;

    if(arq == NULL){
        printf("arquivo não existe, pressione qualquer tecla para retornar ao menu");
        system("wait");
    }

    else{
            setlocale(LC_NUMERIC, "");
            while (fscanf(arq, "%d ", &a) != EOF){
                fscanf(arq, "%[^\n]*c\n", past_ptr.name);
                fscanf(arq, "%f\n", &past_ptr.price);
                fscanf(arq, "%i\n", &past_ptr.amount);

                ptr = (produtos *) realloc(ptr, (i + 1) * sizeof(produtos));
                strcpy(ptr[i].name, past_ptr.name);
                ptr[i].price = past_ptr.price;
                ptr[i].amount = past_ptr.amount;
                printf("%d %s %.2f %d\n", a, ptr[i].name, ptr[i].price, ptr[i].amount);
                i++;
            }
    }
    getch();
    fclose(arq);
}

void imprimir(produtos *ptr, FILE *arq){
    int i, tamanhoListaP = sizeMeP(arq, 4);
    for(i = 0; i < tamanhoListaP; i++){
        printf("%s", ptr[i].name);
    }
}

