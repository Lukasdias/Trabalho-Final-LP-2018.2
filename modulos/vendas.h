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
    time_t horario;
    struct comprador cliente;
    Carrinho carrinho;
};

typedef struct {
    int tamanho;
    struct venda *vendas;
} Vendas;


#endif