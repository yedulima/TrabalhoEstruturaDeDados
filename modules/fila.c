#include <stdio.h>
#include <stdlib.h>

#include "../headers/fila.h"

void menu_fila(Fila *fila) {
    int running = 1;

    while (running) {
        int op, val;

        printf("\n================= FILA ==================\n");
        printf("1 - Enfileirar\n2 - Desenfileirar\n3 - Exibir fila\n4 - Mostrar primeiro elemento\n0 - Sair\n");
        printf("=========================================\n");

        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
            {
                printf("Valor: ");
                scanf("%d", &val);
                enqueue(fila, val);
                break;
            }
            case 2:
            {
                val = dequeue(fila);
                if (val != -1) {
                    printf("Elemento removido: %d\n", val);
                }
                break;
            }
            case 3:
            {
                exibir_fila(fila);
                break;
            }
            case 4:
            {
                val = peek(fila);
                if (val != -1) {
                    printf("Primeiro da fila: %d\n", val);
                }
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

void iniciar_fila(Fila *fila) {
    fila->inicio = fila->fim = 0;
}

int fila_vazia(Fila *fila) {
    return fila->inicio == fila->fim;
}

int fila_cheia(Fila *fila) {
    return (fila->fim + 1) % MAX == fila->inicio;
}

void enqueue(Fila *fila, int val) {
    if (fila_cheia(fila)) {
        printf("Fila cheia.");
        return;
    }

    fila->dados[fila->fim] = val;
    fila->fim = (fila->fim + 1) % MAX;
}

int dequeue(Fila *fila) {
    if (fila_vazia(fila)) {
        printf("Fila vazia.\n");
        return -1;
    }

    int valor = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    return valor;
}

int peek(Fila *fila) {
    if (fila_vazia(fila)) {
        printf("Fila vazia.\n");
        return -1;
    }

    return fila->dados[fila->inicio];
}

void exibir_fila(Fila *fila) {
    if (fila_vazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    for (int i = fila->inicio; i != fila->fim; i = (i + 1) % MAX)
        printf("%d ", fila->dados[i]);
    printf("\n");
}
