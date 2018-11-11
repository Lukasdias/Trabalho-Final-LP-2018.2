////////////////////////////////////
typedef struct produtos {
    char name[30];
    int amount;
    int price;
    int promotion_section;
} produtos;

FILE *estoqueProdutos;
produtos *novoProduto = NULL;

int tamanhoListaP;

void fullMe_P(produtos *ptr, FILE *arq);
void criar_Produto(produtos *ptr, FILE *arq);
void ler_Produto(produtos *ptr, FILE *arq);
void remove_Produto();
void editar_Produto();
void addCarrinho();
int ver_carrinho();
//////////////////////////////////
//Função para os produtos serem adicionados a loja!//
void criar_Produto(produtos *ptr, FILE *arq){
    cleanMe();

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
            scanf("%d", &ptr[tamanhoListaP].price);
            fflush(stdin);
            fprintf(arq, "%d\n", ptr[tamanhoListaP].price);

            printf("Quantidade disponivel: ");
            scanf("%d", &ptr[tamanhoListaP].amount);
            fflush(stdin);
            fprintf(arq, "%d\n", ptr[tamanhoListaP].amount);

            printf("Novo Produto Cadastrado!");

            tamanhoListaP++;
            fclose(arq);
     }
}

//Função para exibir todos os produtos e seus dados)//
void ler_Produto(produtos *ptr, FILE *arq){
    cleanMe();


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

void fullMe_P(produtos *ptr, FILE *arq){
    arq = fopen("bank/estoqueProdutos.txt", "r");
    produtos past_ptr;
    int tamanhoListaP = sizeMeP(arq, 4), i = 0;
    int a;
    if(arq == NULL){
        printf("arquivo não existe, pressione qualquer tecla para retornar ao menu");
        getch();
    }

    else{

           while((fscanf(arq, "%d\n%s\n%d\n%d\n", &a, past_ptr.name, &past_ptr.price, &past_ptr.amount))!=EOF){
               ptr = (produtos *) realloc(ptr, (i + 1) * sizeof(produtos));
               strcpy(ptr[i].name, past_ptr.name);
               ptr[i].price = past_ptr.price;
               ptr[i].amount = past_ptr.amount;
               printf("%d %s %d %d\n", a, ptr[i].name, ptr[i].price, ptr[i].amount);
               i++;
           }
    }
    fclose(arq);
}
