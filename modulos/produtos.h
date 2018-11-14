#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <stdlib.h>
#include <locale.h>

struct produto {
    char nome[50];
    double valor;
    int qtd;
};

typedef struct {
    int tamanho;
     struct produto *produtos;
} Produtos;

Produtos *criar_produtos();
void apagar_produtos(Produtos *);

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

void apagar_produtos(Produtos *lista){
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

    if (tamanhoArquivo2("dados/produtos.txt") == 0){
        return;
    }
        setlocale(LC_NUMERIC, "");
        fscanf(arquivo, "%d\n", &tam);
        for (i = 0; i < tam; i++){
            fscanf(arquivo, "%[^\n]%*c\n", produto.nome);
            fscanf(arquivo, "%lf\n", &produto.valor);
            fscanf(arquivo, "%d\n", &produto.qtd);
            
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
    
    int i;
    for (i = 0; i < lista->tamanho; i++){
        fprintf(arquivo, "%s\n", lista->produtos[i].nome);
        fprintf(arquivo, "%lf\n", lista->produtos[i].valor);
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
#endif