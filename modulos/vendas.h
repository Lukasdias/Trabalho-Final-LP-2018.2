///////////////////////////////////////////////
///////////////FUNÇÕES VENDAS/////////////////
/////////////////////////////////////////////
#ifndef VENDAS_H
#define VENDAS_H

#include "clientes.h"
#include "carrinho.h"

struct comprador {
    char nome[100];
    char endereco[210];
    char telefone[15];
    char data[9];
    char hora[9];
};

struct venda {
    int id;
    struct comprador cliente;
    Carrinho carrinho;
};

typedef struct {
    int tamanho;
    struct venda *vendas;
} Vendas;

Vendas *criar_vendas();
void apagar_vendas(Vendas *);
void popular_vendas(Vendas *);
void salvar_vendas(Vendas *);
void adicionar_venda(Vendas *, struct comprador cliente, Carrinho *);
void remover_venda(Vendas *, int);
void relizar_vendas(Vendas *, Carrinho *, Clientes *);
void listar_vendas(Vendas *, Carrinho *);
void relatorio_do_dia(Vendas *, Carrinho *);
int tamanhoArquivo3(const char* );

Vendas *criar_vendas(){
    Vendas *lista = (Vendas *) malloc(sizeof(Vendas));
    lista->tamanho = 0;
    lista->vendas = NULL;
    return lista;
}

void apagar_vendas(Vendas *lista){
    if (lista == NULL){
        printf("Lista nao existe");
        return;
    }

    free(lista->vendas);
    free(lista);
}

void salvar_vendas(Vendas *lista){
    int i, j;
    char horario[9];
    char data[9];
    FILE *arquivo;
    arquivo = fopen("dados/vendas.txt", "w");

    fprintf(arquivo, "%d\n", lista->tamanho);
    for (i = 0; i < lista->tamanho; i++){
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.data);
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.hora);
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.nome);
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.endereco);
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.telefone);
        fprintf(arquivo, "%d\n", lista->vendas[i].carrinho.tamanho);

        for (j = 0; j < lista->vendas[i].carrinho.tamanho; j++){
            fprintf(arquivo, "%s\n", lista->vendas[i].carrinho.produtos[j].nome);
            fprintf(arquivo, "%.2lf\n", lista->vendas[i].carrinho.produtos[j].preco);
            fprintf(arquivo, "%d\n", lista->vendas[i].carrinho.produtos[j].qtd);
        }
        fprintf(arquivo, "%.2lf\n", lista->vendas[i].carrinho.preco);
        fprintf(arquivo, "%.2lf\n", lista->vendas[i].carrinho.precoFinal);
    }

    fclose(arquivo);
}

void adicionar_venda(Vendas *lista, struct comprador cliente, Carrinho *carrinho){
    if (!lista){
        fprintf(stderr, "As vendas precisam ser inicializadas primeiro.\n");
        return;
    }

    lista->vendas = (struct venda *) realloc(lista->vendas, (lista->tamanho + 1) * sizeof(struct venda));
    lista->vendas[lista->tamanho].cliente = cliente;
    lista->vendas[lista->tamanho].carrinho = *carrinho;
    lista->tamanho++;
}

void remover_venda(Vendas *lista, int id){
    for (; lista->tamanho < lista->tamanho - 1; id++)
        lista->vendas[id] = lista->vendas[id + 1];
    lista->vendas = (struct venda *) realloc(lista->vendas, (lista->tamanho - 1) * sizeof(struct venda));
    lista->tamanho--;
}

int tamanhoArquivo3(const char* nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL)
        return 0; // função deve retornar um inteiro//

    fseek(arquivo, 0, SEEK_END);
    int tamanho = ftell(arquivo);
    fclose(arquivo);

    return tamanho;
}

void realizar_venda(Vendas *lista, Carrinho *lista_carrinho, Clientes *lista_c){
    if (!lista){
        printf("nenhuma venda realizada!!!\n");
        system("pause");
        return;
    }
    if(lista_carrinho == 0){
        printf("carrinho vazio!!!\n");
        system("pause");
        return;
    }
    char hora[9], data[9];
    int i;
    struct comprador cliente;
    system("cls");
    printf("=================================Loja NerdZ====================================\n");
    printf("===================================VENDAS======================================\n");
    printf("=================================NOVA VENDA====================================\n");
    printf("Checar usuario...\n");
    printf("Digite seu nome: ");
    scanf("%[^\n]*c", cliente.nome);
    fflush(stdin);

    for(i = 0; i < lista_c->tamanho; i++){
        if(strcmp(lista_c->clientes[i].nome, cliente.nome) == 0){
            printf("Cliente localizado!\n");
            printf("Bem vindo %s\n", cliente.nome);
            strcpy(cliente.endereco, lista_c->clientes[i].endereco);
            strcpy(cliente.telefone, lista_c->clientes[i].telefone);
            _strdate(data);
            _strtime(hora);
            strcpy(cliente.data, data);
            strcpy(cliente.hora, hora);
            adicionar_venda(lista, cliente, lista_carrinho);
            printf("Venda realizada!\n");
            system("pause");
            return;
        }
    }
}

void listar_venda(Vendas *lista, Carrinho *lista_c){
    int i, j;
    if (lista == NULL){
        printf("Lista nao foi iniciada");
        system("pause");
        return;
    }
    if (lista->tamanho == 0){
        printf("Nenhuma venda realizada vazio\n");
        system("pause");
        return;
    }
    system("cls");
    printf("=================================Loja NerdZ====================================\n");
    printf("===================================VENDAS======================================\n");
    printf("===================================LISTAR======================================\n");
    for (i = 0; i < lista->tamanho; i++){
        printf("Nome do cliente: %s\n", lista->vendas[i].cliente.nome);
        printf("Endereco: %s\n", lista->vendas[i].cliente.endereco);
        printf("Telefone: %s\n", lista->vendas[i].cliente.telefone);
        printf("Itens no carrinho: %d\n", lista->vendas[i].carrinho.tamanho);
        for(j = 0; j < lista_c->tamanho; j++){
            printf("Produtos: %s \n", lista->vendas[i].carrinho.produtos[j].nome);
            printf("Valor: %.2lf\n", lista->vendas[i].carrinho.produtos[j].preco);
            printf("Quantidade: %d\n", lista->vendas[i].carrinho.produtos[j].qtd);
        }
        printf("==========================================================================\n");
    }
    system("pause");
}

void relatorio_do_dia(Vendas *lista, Carrinho *lista_c){
    FILE *arquivo;
    int i, j;
    arquivo = fopen("dados/relatorio.txt", "w");
    printf("Gerando relatorio...\n");

    fprintf(arquivo, "Vendas realizadas: %d\n", lista->tamanho);
    for (i = 0; i < lista->tamanho; i++){
        fprintf(arquivo, "Data da venda %d: %s\n", i + 1, lista->vendas[i].cliente.data);
        fprintf(arquivo, "Horario da venda %d: %s\n", i + 1, lista->vendas[i].cliente.hora);
        fprintf(arquivo, "Nome do cliente %d: %s\n", i + 1, lista->vendas[i].cliente.nome);
        fprintf(arquivo, "Endereco do cliente %d: %s\n", i + 1, lista->vendas[i].cliente.endereco);
        fprintf(arquivo, "Telefone do cliente %d: %s\n", i + 1, lista->vendas[i].cliente.telefone);
        fprintf(arquivo, "Quantidade de itens no carrinho do cliente %d: %d\n", i + 1, lista->vendas[i].carrinho.tamanho);

        for (j = 0; j < lista_c->tamanho; j++){
            fprintf(arquivo, "Nome do produto: %s\n", lista->vendas[i].carrinho.produtos[j].nome);
            fprintf(arquivo, "Valor do unitario produto: %.2lf\n", lista->vendas[i].carrinho.produtos[j].preco);
            fprintf(arquivo, "Quantidade solicitada: %d\n", lista->vendas[i].carrinho.produtos[j].qtd);
        }
        fprintf(arquivo, "Valor sem desconto: %.2lf\n", lista->vendas[i].carrinho.preco);
        fprintf(arquivo, "Valor com desconto: %.2lf\n", lista->vendas[i].carrinho.precoFinal);
        fprintf(arquivo, "================================================================================\n");
    }
    //salvar_vendas(lista);
    printf("Relatorio feito com sucesso cheque na pasta dados para obter seu relatorio!\n");
    system("pause");
    fclose(arquivo);

}

#endif
