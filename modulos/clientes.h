#ifndef CLIENTES_H
#define CLIENTES_H
#include <stdlib.h>

struct cliente {
    char nome[50];
    char endereco[128];
    char telefone[20];
    char cidade[20];
    char estado[15];
};

typedef struct {
    int tamanho;
    struct cliente *clientes;
} Clientes;

Clientes *criar_clientes();
void apagar_clientes(Clientes *);

void popular_clientes(Clientes *);
void salvar_clientes(Clientes *);

void adicionar_clientes(Clientes *, struct cliente);
void apagar_cliente(Clientes *, int posicao);
//incluindo o diretório no nome do arquivo//
int tamanhoArquivo(const char* nome_arquivo);

Clientes *criar_clientes(){
    Clientes *lista = (Clientes *) malloc(sizeof(Clientes));
    lista->tamanho = 0;
    lista->clientes = NULL;
    return lista;
}

void apagar_clientes(Clientes *lista){
    if (lista == NULL)
        return;

    salvar_clientes(lista);
    free(lista->clientes);
    free(lista);
}

void adicionar_clientes(Clientes *lista, struct cliente cliente){
    if (lista == NULL)
        return;

    lista->clientes = (struct cliente *) realloc(lista->clientes, (lista->tamanho + 1) * sizeof(struct cliente));
    lista->clientes[lista->tamanho] = cliente;
    lista->tamanho++;
}

void apagar_cliente(Clientes *lista, int posicao){
    if (lista == NULL)
        return;

    for (; posicao < lista->tamanho - 1; posicao++)
        lista->clientes[posicao] = lista->clientes[posicao + 1];
        lista->clientes = (struct cliente *) realloc(lista->clientes, (lista->tamanho - 1) * sizeof(struct cliente));
        lista->tamanho--;
}

void popular_clientes(Clientes *lista){
    FILE *arquivo;
    arquivo = fopen("dados/clientes.txt", "r");
    int i, tam;
    struct cliente cliente;

    if (tamanhoArquivo("dados/clientes.txt") == 0){
        return;
    }

    fscanf(arquivo, "%d\n", &tam);
    for (i = 0; i < tam; i++){
        fscanf(arquivo, "%[^\n]%*c\n", cliente.nome);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.telefone);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.endereco);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.cidade);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.estado);

        adicionar_clientes(lista, cliente);
    }

    fclose(arquivo);
}

void salvar_clientes(Clientes *lista){
    if (lista == NULL)
        return;

    FILE *arquivo;
    arquivo = fopen("dados/clientes.txt", "w");

    fprintf(arquivo, "%d\n", lista->tamanho);

    int i;
    for (i = 0; i < lista->tamanho; i++){
        fprintf(arquivo, "%s\n", lista->clientes[i].nome);
        fprintf(arquivo, "%s\n", lista->clientes[i].telefone);
        fprintf(arquivo, "%s\n", lista->clientes[i].endereco);
        fprintf(arquivo, "%s\n", lista->clientes[i].cidade);
        fprintf(arquivo, "%s\n", lista->clientes[i].estado);
    }

    fclose(arquivo);
}

int tamanhoArquivo(const char* nome_arquivo)
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
