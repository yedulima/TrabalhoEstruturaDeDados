#ifndef PILHA_H
#define PILHA_H

#define MAX 50

typedef struct {
    int topo;
    int dados[MAX];
} Pilha;

void menu_pilha(Pilha *pilha);

void iniciar_pilha(Pilha *pilha);
int pilha_cheia(Pilha *pilha);
int pilha_vazia(Pilha *pilha);
void push(Pilha *pilha, int valor);
int pop(Pilha *pilha);
int top(Pilha *pilha);
void exibir_pilha(Pilha *pilha);

#endif