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
};

struct venda {
    int id;
    char horario[9];
    char data[9];
    struct comprador cliente;
    Carrinho carrinho;
};

typedef struct {
    int tamanho;
    struct venda *vendas;
} Vendas;

Vendas *criar_vendas();
void apagar_vendas(Vendas *lista);
void popular_vendas(Vendas *lista);
void salvar_vendas(Vendas *lista);
void adicionar_venda(Vendas *lista, struct comprador cliente, Carrinho *carrinho);
void remover_venda(Vendas *lista, int);
void relizar_vendas(Vendas *lista, Carrinho *, Clientes *);
void listar_vendas(Vendas *lista);
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

void popular_vendas(Vendas *lista){
    FILE *arquivo;
    Carrinho *carrinho;
    struct comprador cliente;
    struct produtoCarrinho produto;
    int i, j, quant;
    double desconto;

    carrinho = criar_carrinho();

    arquivo = fopen("dados/vendas.txt", "r");

    if (tamanhoArquivo2("dados/vendas.txt") == 0){
        return;
    }

    if (!arquivo)
        return;
    setlocale(LC_NUMERIC, "");

    fscanf(arquivo, "%d ", &quant);
    for (i = 0; i < quant; i++){
        fscanf(arquivo, "%[^\n]%*c\n", &cliente.nome);
        fscanf(arquivo, "%[^\n]%*c\n", &cliente.endereco);
        fscanf(arquivo, "%[^\n]%*c\n", &cliente.telefone);

        fscanf(arquivo, "%d\n", &j);
        for (; j > 0; j--){
            fscanf(arquivo, "%[^\n]%*c\n", &produto.nome);
            fscanf(arquivo, "%lf\n", &produto.preco);
            fscanf(arquivo, "%d\n", &produto.qtd);
            popular_carrinho(carrinho, produto);
        }

        fscanf(arquivo, "%lf\n", &carrinho->desconto);
        fscanf(arquivo, "%lf\n", &carrinho->descontoP);
        fscanf(arquivo, "%lf\n", &carrinho->preco);
        fscanf(arquivo, "%lf\n", &carrinho->precoFinal);

        adicionar_venda(lista, cliente, carrinho);
        carrinho = criar_carrinho();
    }

    fclose(arquivo);
}

void salvar_vendas(Vendas *lista){
    int i, j;
    char horario[9];
    char data[9];
    FILE *arquivo;
    arquivo = fopen("dados/vendas.txt", "w");

    fprintf(arquivo, "%d\n", lista->tamanho);
    for (i = 0; i < lista->tamanho; i++){
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.nome);
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.endereco);
        fprintf(arquivo, "%s\n", lista->vendas[i].cliente.telefone);
        fprintf(arquivo, "%d\n", lista->vendas[i].carrinho.tamanho);

        for (j = 0; j < lista->vendas[i].carrinho.tamanho; j++){
            fprintf(arquivo, "%s\n", lista->vendas[i].carrinho.produtos[j].nome);
            fprintf(arquivo, "%lf\n", lista->vendas[i].carrinho.produtos[j].preco);
            fprintf(arquivo, "%d\n", lista->vendas[i].carrinho.produtos[j].qtd);
        }

        fprintf(arquivo, "%lf\n", lista->vendas[i].carrinho.desconto);
        fprintf(arquivo, "%d\n", lista->vendas[i].carrinho.descontoP);
        fprintf(arquivo, "%lf\n", lista->vendas[i].carrinho.preco);
        fprintf(arquivo, "%lf\n", lista->vendas[i].carrinho.precoFinal);
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
    int i, j, ch;
    struct comprador cliente;
    printf("Confirmaçao de usuario\n");
    printf("Digite seu nome: ");
    scanf("%[^\n]*c", cliente.nome);
    fflush(stdin);

    for(i = 0; i < lista_c->tamanho; i++){
        if(strcmp(lista_c->clientes[i].nome, cliente.nome) == 0){
            printf("Cliente localizado!\n");
            printf("Bem vindo %s", cliente.nome);
            strcpy(cliente.endereco, lista_c->clientes[i].endereco);
            strcpy(cliente.telefone, lista_c->clientes[i].telefone);
            adicionar_venda(lista, cliente, lista_carrinho);
            printf("Venda realizada!\n");
            system("pause");
            return;
        }
    }
    printf("Deseja mesmo comprar os seguintes itens abaixo");
}

void listar_venda(Vendas *lista){
    int i, j;
    if (lista == NULL){
        printf("Lista nao foi iniciada");
        return;
    }
    if (lista->vendas[i].carrinho.tamanho == 0){
        printf("Carrinho vazio");
        return;
    }
    for (i = 0; i < lista->tamanho; i++){
        printf("Nome do cliente: %s\n", lista->vendas[i].cliente.nome);
        printf("Endereco: %s\n", lista->vendas[i].cliente.endereco);
        printf("Telefone: %s\n", lista->vendas[i].cliente.telefone);
        printf("Itens no carrinho: %d\n", lista->vendas[i].carrinho.tamanho);

        for (j = 0; j < lista->vendas[i].carrinho.tamanho; j++){
            printf("Nome do item no carrinho: %s\n", lista->vendas[i].carrinho.produtos[j].nome);
            printf("Valor: %lf\n", lista->vendas[i].carrinho.produtos[j].preco);
            printf("Valor: %d\n", lista->vendas[i].carrinho.produtos[j].qtd);
        }

        printf("Desconto: %lf\n", lista->vendas[i].carrinho.desconto);
        printf("DescontoP %d\n", lista->vendas[i].carrinho.descontoP);
        printf("Valor unitario: %lf\n", lista->vendas[i].carrinho.preco);
        printf("Valor total: %lf\n", lista->vendas[i].carrinho.precoFinal);
    }
    system("pause");
} 

#endif
