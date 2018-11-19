///////////////////////////////////////////////
///////////////FUNÇÕES CLIENTES/////////////////
/////////////////////////////////////////////
#ifndef CLIENTES_H
#define CLIENTES_H

struct cliente {
    char nome[50];
    char endereco[128];
    char telefone[20];
    char cidade[20];
    char estado[15];
    char datas[9];
    char horas[9];
};

typedef struct {
    int tamanho;
    struct cliente *clientes;
} Clientes;

void addC(Clientes *);
void listC(Clientes *);
Clientes *criar_clientes();
void armazenar_clientes(Clientes *);

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

void armazenar_clientes(Clientes *lista){
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
        printf("arquivo vazio");
        return;
    }

    fscanf(arquivo, "%d\n", &tam);
    for (i = 0; i < tam; i++){
        fscanf(arquivo, "%[^\n]%*c\n", cliente.nome);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.telefone);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.endereco);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.cidade);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.estado);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.datas);
        fscanf(arquivo, "%[^\n]%*c\n", cliente.horas);
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
        fprintf(arquivo, "%s\n", lista->clientes[i].datas);
        fprintf(arquivo, "%s\n", lista->clientes[i].horas);
    }

    fclose(arquivo);
}

int tamanhoArquivo(const char* nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL)
        return 0; // função deve retornar um inteiro//

    fseek(arquivo, 0, SEEK_END);
    int tamanho = ftell(arquivo);
    fclose(arquivo);

    return tamanho;
}

void addC(Clientes *lista){
    struct cliente cliente;
    
    char data[9];
    char horario[9];

    system("cls");
    printf("=================================Loja NerdZ====================================\n");
    printf("================================NOVO CLIENTE===================================\n");
    printf("===============================================================================\n");

    
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]*c", cliente.nome);
    fflush(stdin);

    printf("Telefone: ");
    scanf("%[^\n]*c", cliente.telefone);
    fflush(stdin);

    printf("Endereco: ");
    scanf("%[^\n]*c", cliente.endereco);
    fflush(stdin);

    printf("Cidade: ");
    scanf("%[^\n]*c", cliente.cidade);
    fflush(stdin);

    printf("Estado: ");
    scanf("%[^\n]*c", cliente.estado);
    fflush(stdin);

    _strdate(data);
    _strtime(horario);
    strcpy(cliente.datas, data);
    strcpy(cliente.horas, horario);

    adicionar_clientes(lista, cliente);
    system("pause");
}

void listC(Clientes *lista){
    int i;
    
    system("cls");
    printf("================================Loja NerdZ=====================================\n");
    printf("===============================MENU LISTAR=====================================\n");
    printf("=============================CLIENTES LISTADOS=================================\n");
    printf("===============================================================================\n");

    for (i = 0; i < lista->tamanho; i++){
        
        printf("Cliente %d\n", i + 1);
        printf("Nome: %s\n", lista->clientes[i].nome);
        printf("Telefone: %s\n", lista->clientes[i].telefone);
        printf("Endereco: %s\n", lista->clientes[i].endereco);
        printf("Cidade: %s\n", lista->clientes[i].cidade);
        printf("Estado: %s\n", lista->clientes[i].estado);
        printf("Data : %s\nHorario: %s\n", lista->clientes[i].datas, lista->clientes[i].horas);
        printf("===============================================================================\n");
    }
    system("pause");
}

void editC(Clientes *lista){
    int i;
    char *user = (char *) malloc (100 * sizeof(char));
    char data[9];
    char horario[9];

    system("cls");
    printf("==================================Loja NerdZ===================================\n");
    printf("=================================MENU CLIENTE==================================\n");
    printf("================================EDITAR CLIENTE=================================\n");
    printf("===============================================================================\n");
    printf("Informe o nome do cliente a ser buscado: ");
    scanf("%[^\n]*c", user);
    fflush(stdin);

    for(i = 0; i < lista->tamanho; i++){
        if(strcmp(user, lista->clientes[i].nome) == 0){

            printf("Cliente localizado!\n");
            printf("Novo nome:");
            scanf("%[^\n]*c", lista->clientes[i].nome);
            fflush(stdin);

            printf("Novo telefone:");
            scanf("%[^\n]*c", lista->clientes[i].telefone);
            fflush(stdin);

            printf("Nova moradia: ");
            scanf("%[^\n]*c", lista->clientes[i].endereco);
            fflush(stdin);

            printf("Nova cidade: ");
            scanf("%[^\n]*c", lista->clientes[i].cidade);
            fflush(stdin);

            printf("Novo Estado: ");
            scanf("%[^\n]*c", lista->clientes[i].estado);
            fflush(stdin);

            _strdate(data);
            _strtime(horario);
            
            strcpy(lista->clientes[i].datas, data);
            strcpy(lista->clientes[i].horas, horario);

            salvar_clientes(lista);
            system("pause");
            return;
        }
    }

    printf("O cliente digitado n existe!\n");
    system("pause");
}

int deleteC(Clientes *lista){
    int i = 0, k;
    char *dados = (char *) malloc (100 * sizeof(char));

    system("cls");
    printf("==================================Loja NerdZ===================================\n");
    printf("=================================MENU CLIENTE==================================\n");
    printf("================================DELETAR CLIENTE================================\n");
    printf("===============================================================================\n");
     printf("Informe o nome do cliente a ser buscado: ");
    scanf("%[^\n]*c", dados);

    if (lista == NULL){
        printf("Erro, nao foi possivel excluir o cliente\n");
        system("pause");
        return 0;
    }

    if (lista->tamanho == 0){
        printf("Erro, nao foi possivel excluir o cliente\n");
        system("pause");
        return 0;
    }

    if (i == lista->tamanho){
        printf("Erro, nao foi possivel excluir o cliente\n");
        system("pause");
        return 0;
    }

    for (i = 0; i < lista->tamanho; i++){
        if (strcmp(lista->clientes[i].nome, dados) == 0){
            apagar_cliente(lista, i);
            printf("Produto removido com sucesso\n");
            system("pause");
        }
    }
    printf("Cliente removido com sucesso\n");
    system("pause");
    return 1;
}

#endif
