#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct No* prox;
} No;

void menu_lista(No **lista);

void inserir_inicio(No **lista, int val);
void inserir_fim(No **lista, int val);
No* buscar(No *lista, int chave);
int remover(No **lista, int chave);
void imprimir(const No *lista);

#endif