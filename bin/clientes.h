#include <stdio.h>

struct cliente {
    char name[50];
    char adress[128];
    int *car;
    char phone[12];
};

typedef struct {
   struct cliente *clientes;
} Cliente;

