#include <stdio.h>

#include "headers/lista.h"
#include "headers/pilha.h"
#include "headers/fila.h"

// Para compilar:
// gcc main.c modules/lista.c modules/pilha.c modules/fila.c -Iheaders -o output/main

int main() {
    int running = 1;

    // Inicianlizando estrutura de lista
    No* estrutura_lista = NULL;

    // Inicilizando estrutura de pilha
    Pilha estrutura_pilha;
    iniciar_pilha(&estrutura_pilha);

    // Inicializando estrutura de fila
    Fila estrutura_fila;
    iniciar_fila(&estrutura_fila);

    while (running) {
        int op;

        printf("========= SISTEMA DE ESTRUTURAS =========\n");
        printf("1 - Operar Lista Encadeada\n2 - Operar Pilha\n3 - Operar Fila\n0 - Encerrar\n");
        printf("=========================================\n");

        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
            {
                menu_lista(&estrutura_lista);
                break;
            }
            case 2:
            {
                menu_pilha(&estrutura_pilha);
                break;
            }
            case 3:
            {
                menu_fila(&estrutura_fila);
                break;
            }
            case 0:
            {
                printf("Encerrando programa...");
                running = 0;
                break;
            }
            default:
            {
                printf("Opcao invalida.\n");
                break;
            }
        }
    }

    return 0;
}