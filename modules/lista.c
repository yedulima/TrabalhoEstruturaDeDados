#include <stdio.h>
#include <stdlib.h>

#include "../headers/lista.h"

void menu_lista(No **lista) {
    int running = 1;

    while (running) {
        int op, val;

        printf("\n============ LISTA ENCADEADA ============\n");
        printf("1 - Inserir inicio\n2 - Inserir fim\n3 - Buscar\n4 - Remover\n5 - Mostrar lista\n0 - Sair\n");
        printf("=========================================\n");

        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
            {
                printf("Valor: ");
                scanf("%d", &val);
                inserir_inicio(lista, val);
                break;
            }
            case 2:
            {
                printf("Valor: ");
                scanf("%d", &val);
                inserir_fim(lista, val);
                break;
            }
            case 3:
            {
                printf("Valor: ");
                scanf("%d", &val);
                if (buscar(*lista, val)) {
                    printf("Encontrado: %d\n", val);
                } else {
                    printf("Não encontrado.\n");
                }
                break;
            }
            case 4:
            {
                printf("Valor: ");
                scanf("%d", &val);
                if (remover(lista, val)) {
                    printf("Elemento removido com sucesso!\n");
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;
            }
            case 5:
            {
                printf("Mostrar lista:\n");
                imprimir(*lista);
                printf("\n");
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

void inserir_inicio(No **lista, int val) {
    No *novo_item = (No*) malloc(sizeof(No));

    if (!novo_item) {
        printf("Falha em gravar novo elemento.");
        exit(1);
    }

    novo_item->valor = val;
    novo_item->prox = *lista;
    *lista = novo_item;
};

void inserir_fim(No **lista, int val) {
    No *novo_item = (No*) malloc(sizeof(No));

    if (!novo_item) {
        printf("Falha em gravar novo elemento.");
        exit(1);
    }

    novo_item->valor = val;
    novo_item->prox = NULL;

    if (*lista == NULL) {
        *lista = novo_item;
        return;
    }

    No *p = *lista;
    while (p->prox != NULL) p = p->prox;
    p->prox = novo_item;
};

No* buscar(No *lista, int chave) {
    No *p = lista;
    while (p) {
        if (p->valor == chave) return p;
        p = p->prox;
    }
    return NULL;
};

int remover(No **lista, int chave) {
    if (!*lista) return 0;

    No *p = *lista, *ant = NULL;

    while (p && p->valor != chave) {
        ant = p;
        p = p->prox;
    }
    if (!p) return 0;

    if (!ant) {
        *lista = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    return 1;
};

void imprimir(const No *lista) {
    if (lista == NULL) {
        return;
    }

    printf("%d ", lista->valor);
    imprimir(lista->prox);
};
