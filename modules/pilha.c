#include <stdio.h>
#include <stdlib.h>

#include "../headers/pilha.h"

void menu_pilha(Pilha *pilha) {
    int running = 1;

    while (running) {
        int op, val;

        printf("\n================ PILHA ================\n");
        printf("1 - Inserir\n2 - Remover\n3 - Mostrar proximo a ser removido\n4 - Mostrar pilha\n0 - Sair\n");
        printf("=========================================\n");

        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
            {
                printf("Valor: ");
                scanf("%d", &val);
                push(pilha, val);
                break;
            }
            case 2:
            {
                int removido = pop(pilha);
                if (removido != -1) {
                    printf("Item removido: %d\n", removido);
                }
                break;
            }
            case 3:
            {
                int topo = top(pilha);
                if (topo != 1) {
                    printf("Próximo item a ser removido: %d\n", topo);
                }
                break;
            }
            case 4:
            {
                printf("Mostrar pilha:\n");
                exibir_pilha(pilha);
                break;
            }
            case 0:
            {
                running = 0;
                printf("\n");
                break;
            }
            default:
            {
                printf("Opcao invalida.\n");
                break;
            }
        }
    }
}

void iniciar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilha_cheia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilha_vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void push(Pilha *pilha, int valor) {
    if (pilha->topo == MAX - 1) {
        printf("Pilha cheia.\n"); return;
    }

    pilha->dados[++pilha->topo] = valor;
}

int pop(Pilha *pilha) {
    if (pilha_vazia(pilha)) {
        printf("Pilha vazia.\n");
        return -1;
    }

    return pilha->dados[pilha->topo--];
}

int top(Pilha *pilha) {
    if (pilha_vazia(pilha)) {
        printf("Pilha vazia.\n");
        return -1;
    }

    return pilha->dados[pilha->topo];
}

void exibir_pilha(Pilha *pilha) {
    if (pilha_vazia(pilha)) {
        printf("Pilha vazia.\n"); return;
    }

    for (int i = pilha->topo; i >= 0; --i) {
        printf("%d ", pilha->dados[i]);
    }

    printf("\n");
}
