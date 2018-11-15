#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <stdlib.h>
#include <locale.h>

struct produto {
    char nome[50];
    float valor;
    int qtd;
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
            fscanf(arquivo, "%f\n", &produto.valor);
            fscanf(arquivo, "%d\n", &produto.qtd);

            adicionar_produtos(lista, produto);
        }
    fclose(arquivo);
    setlocale(LC_ALL, "");
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
        fprintf(arquivo, "%.2f\n", lista->produtos[i].valor);
        fprintf(arquivo, "%d\n", lista->produtos[i].qtd);
    }

    fclose(arquivo);
}

int tamanhoArquivo2(const char* nome_arquivo)
{
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
    system("cls");
    printf("======================Loja NerdZ===================\n");
    printf("=====================Menu Adicionar=================\n");
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]*c", produto.nome);
    fflush(stdin);
    printf("Valor: ");
    scanf("%f", &produto.valor);
    fflush(stdin);
    printf("Qtd em estoque: ");
    scanf("%d", &produto.qtd);
    fflush(stdin);
    adicionar_produtos(lista, produto);
}

void listP(Produtos *lista){
    int i;
    system("cls");
    printf("=====================Loja NerdZ===================\n");
    printf("=====================Menu Listar=================\n");
    for (i = 0; i < lista->tamanho; i++){
        printf("Produto %d\n", i + 1);
        printf("Nome: %s\n", lista->produtos[i].nome);
        printf("Valor %f\n", lista->produtos[i].valor);
        printf("Quantidade em estoque: %d\n", lista->produtos[i].qtd);
    }
    system("pause");
}

void editP(Produtos *lista){
    int i, j;
    char *user = (char *) malloc(100 * sizeof(char));
    system("cls");
    printf("=====================Loja NerdZ===================\n");
    printf("=====================Menu Editar=================\n");
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
            scanf("%f", &lista->produtos[i].valor);
            fflush(stdin);
            printf("Nova Quantidade em estoque: ");
            scanf("%d", &lista->produtos[i].qtd);
            fflush(stdin);
            salvar_produtos(lista);

            system("pause");
            return;
        }
    }

    printf("Nome n existe\n");
    system("pause");
}

int deleteP(Produtos *lista, const char* nomeProduto){
    int i = 0, k;
    printf("=====================Loja NerdZ===================\n");
    printf("=====================Menu Remover=================\n");
    if (lista == NULL) 
        return 0;
        
    if (lista->tamanho == 0) 
        return 0;

    while(i < lista->tamanho && strcmp(lista->produtos[i].nome, nomeProduto)!= 0)
        i++;
    if (i == lista->tamanho) 
        return 0;

    for(k = i; k < lista->tamanho-1; k++)
        lista->produtos[k] = lista->produtos[k+1];

    lista->tamanho--;

    printf("Produto removido com sucesso\n");
    system("pause");
    return 1;
}

#endif
