///////////////////////////////
typedef struct cliente {
    char name[50];
    char adress[128];
    char phone[12];
    char city[20];
    char country[15];
} clientes;


FILE *bancoClientes;
clientes *novoCliente = NULL;

void criar_Cliente();
void editar_Cliente();
void remove_Cliente();
void ler_Cliente();
//////////////////////////////