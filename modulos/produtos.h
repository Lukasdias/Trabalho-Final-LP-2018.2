///////////////////////////////////////////////
///////////////FUNÇÕES PRODUTOS/////////////////
/////////////////////////////////////////////
#ifndef PRODUTOS_H
#define PRODUTOS_H

struct produto {
    char nome[50];
    double valor;
    int qtd;
    char horas[9];
    char datas[9];
};

typedef struct {
    int tamanho;
     struct produto *produtos;
} Produtos;

void addP(Produtos *);
void listP(Produtos *);
void editP(Produtos *);

Produtos *criar_produtos();
void armazenar_produtos(Produtos *);

void popular_produtos(Produtos *);
void salvar_produtos(Produtos *);

void adicionar_produtos(Produtos *, struct produto);
void apagar_produto(Produtos *, int);
//incluindo o diretório no nome do arquivo//
//função para checar se o arquivo está vazio//
int tamanhoArquivo2(const char* nome_arquivo);

Produtos *criar_produtos(){
    Produtos *lista = (Produtos *) malloc(sizeof(Produtos));
    lista->tamanho = 0;
    lista->produtos = NULL;
    return lista;
}

void armazenar_produtos(Produtos *lista){
    if (lista == NULL)
        return;
    salvar_produtos(lista);
    free(lista->produtos);
    free(lista);
}

void adicionar_produtos(Produtos *lista, struct produto produto){
    if (lista == NULL)
        return;

    lista->produtos = (struct produto *) realloc(lista->produtos, (lista->tamanho + 1) * sizeof(struct produto));
    lista->produtos[lista->tamanho] = produto;
    lista->tamanho++;
}

void apagar_produto(Produtos *lista, int posicao){
    if (lista == NULL)
        return;

    for (; posicao < lista->tamanho - 1; posicao++)
        lista->produtos[posicao] = lista->produtos[posicao + 1];
        lista->produtos = (struct produto *) realloc(lista->produtos, (lista->tamanho - 1) * sizeof(struct produto));
        lista->tamanho--;
}

void popular_produtos(Produtos *lista){
    FILE *arquivo;
    arquivo = fopen("dados/produtos.txt", "r");
    int i, tam;
    struct produto produto;

    setlocale(LC_NUMERIC, "");
    if (tamanhoArquivo2("dados/produtos.txt") == 0){
        return;
    }
        fscanf(arquivo, "%d\n", &tam);
        for (i = 0; i < tam; i++){
            fscanf(arquivo, "%[^\n]%*c\n", produto.nome);
            fscanf(arquivo, "%lf\n", &produto.valor);
            fscanf(arquivo, "%d\n", &produto.qtd);
            fscanf(arquivo, "%[^\n]%*c\n", produto.datas);
            fscanf(arquivo, "%[^\n]%*c\n", produto.horas);
            adicionar_produtos(lista, produto);
        }
    fclose(arquivo);
}

void salvar_produtos(Produtos *lista){
    if (lista == NULL)
        return;

    FILE *arquivo;
    arquivo = fopen("dados/produtos.txt", "w");

    fprintf(arquivo, "%d\n", lista->tamanho);

    setlocale(LC_NUMERIC, "");
    int i;
    for (i = 0; i < lista->tamanho; i++){
        fprintf(arquivo, "%s\n", lista->produtos[i].nome);
        fprintf(arquivo, "%lf\n", lista->produtos[i].valor);
        fprintf(arquivo, "%d\n", lista->produtos[i].qtd);
        fprintf(arquivo, "%s\n", lista->produtos[i].datas);
        fprintf(arquivo, "%s\n", lista->produtos[i].horas);
    }

    fclose(arquivo);
}

int tamanhoArquivo2(const char* nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL)
        return 0; // função deve retornar um inteiro//

    fseek(arquivo, 0, SEEK_END);
    int tamanho = ftell(arquivo);
    fclose(arquivo);

    return tamanho;
}

void addP(Produtos *lista){
    struct produto produto;
    char data[9];
    char horario[9];
    system("cls");
    printf("=================================Loja NerdZ====================================\n");
    printf("================================NOVO PRODUTO===================================\n");
    printf("===============================================================================\n");
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]*c", produto.nome);
    fflush(stdin);
    printf("Valor(inteiro ou float): ");
    scanf("%lf", &produto.valor);
    fflush(stdin);
    printf("Qtd em estoque(inteiro): ");
    scanf("%d", &produto.qtd);
    fflush(stdin);
    _strdate(data);
    _strtime(horario);
    strcpy(produto.datas, data);
    strcpy(produto.horas, horario);
    adicionar_produtos(lista, produto);
}

void listP(Produtos *lista){
    int i;
    
    system("cls");
    printf("================================Loja NerdZ=====================================\n");
    printf("===============================MENU LISTAR=====================================\n");
    printf("=============================PRODUTOS LISTADOS=================================\n");
    printf("===============================================================================\n");

    for (i = 0; i < lista->tamanho; i++){
        printf("Produto %d\n", i + 1);
        printf("Nome: %s\n", lista->produtos[i].nome);
        printf("Valor %.2f\n", lista->produtos[i].valor);
        printf("Quantidade em estoque: %d\n", lista->produtos[i].qtd);
        printf("Data : %s\nHorario: %s\n", lista->produtos[i].datas, lista->produtos[i].horas);
        printf("===============================================================================\n");
    }
    system("pause");
}

void editP(Produtos *lista){
    int i, j;
    char *user = (char *) malloc(50 * sizeof(char));
    char data[9];
    char horario[9];
    system("cls");
    printf("==================================Loja NerdZ===================================\n");
    printf("=================================MENU PRODUTO==================================\n");
    printf("================================EDITAR PRODUTO=================================\n");
    printf("===============================================================================\n");
    printf("Informe um nome a ser buscado na lista de produtos: ");
    scanf("%[^\n]*c", user);
    fflush(stdin);
    for(i = 0; i < lista->tamanho; i++){
        if (strcmp(user, lista->produtos[i].nome) == 0){
            printf("Nome localizado!\n");
            fflush(stdin);
            printf("Novo Nome: ");
            scanf("%[^\n]*c", lista->produtos[i].nome);
            fflush(stdin);
            printf("Novo Valor: ");
            scanf("%lf", &lista->produtos[i].valor);
            fflush(stdin);
            printf("Nova Quantidade em estoque: ");
            scanf("%d", &lista->produtos[i].qtd);
            fflush(stdin);
            
            _strdate(data);
            _strtime(horario);

            strcpy(lista->produtos[i].datas, data);
            strcpy(lista->produtos[i].horas, horario);
            
            salvar_produtos(lista);

            system("pause");
            return;
        }
    }

    printf("Nome n existe\n");
    system("pause");
}

int deleteP(Produtos *lista){
    int i = 0, k;
    char *dados = (char *) malloc (100 * sizeof(char));

    system("cls");
    printf("==================================Loja NerdZ===================================\n");
    printf("=================================MENU PRODUTO==================================\n");
    printf("================================DELETAR PRODUTO================================\n");
    printf("===============================================================================\n");

    printf("informe o nome a ser buscado: ");
    scanf("%[^\n]*c", dados);
    fflush(stdin);
    if (lista == NULL){
        printf("Lista de produtos %c nula!\n", 130);
        system("pause");
        return 0;
    }

    if (lista->tamanho == 0){
        printf("Lista de produtos vazia!\n");
        system("pause");
        return 0;
    }
    
    if (i == lista->tamanho){
        printf("Produto invalido!\n");
        system("pause");
        return 0;
    }

    for (i = 0; i < lista->tamanho; i++){
        if (strcmp(lista->produtos[i].nome, dados) == 0){
            apagar_produto(lista, i);
            printf("Produto removido com sucesso\n");
            system("pause");
        }
    }
    return 1;
}

#endif
