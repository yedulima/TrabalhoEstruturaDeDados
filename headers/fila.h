#ifndef FILA_H
#define FILA_H

#define MAX 50

typedef struct {
    int inicio;
    int fim;
    int dados[MAX];
} Fila;

void menu_fila(Fila *fila);

void iniciar_fila(Fila *fila);
int fila_vazia(Fila *fila);
int fila_cheia(Fila *fila);
void enqueue(Fila *fila, int val);
int dequeue(Fila *fila);
int peek(Fila *fila);
void exibir_fila(Fila *fila);

#endif
