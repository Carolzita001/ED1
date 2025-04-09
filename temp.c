#include <stdio.h>

#define SIZE 3

typedef struct {
    int topo;
    int stack[SIZE];
} Pilha;

void iniciar(Pilha *pilha) {
    pilha->topo = -1;
}

void estado(Pilha *pilha){
    printf("Elementos da pilha: ");
    while (pilha->topo > -1) {
        printf("%d ", pilha->stack[pilha->topo--]);
    }

    printf("\n");
}

int main() {
    Pilha p1, p2;

    iniciar(&p1);
    iniciar(&p2);

    // Entrada dos caracteres
    printf("Digite os valores do maior para o menor (C, B, A): ");
    for (int i = 0; i < SIZE; i++) {
        scanf(" %d", &p1.stack[++p1.topo]); // Incrementa topo antes de armazenar
    }

    // Movendo elementos da pilha 1 para a pilha 2
    while (p1.topo > -1) {
        int value = p1.stack[p1.topo--]; // Desempilha da pilha 1

        // Verifica a restrição antes de empilhar na pilha 2
        if (p2.topo == SIZE - 1) {
            printf("Pilha 2 cheia, não é possível empilhar %d\n", value);
            break; // Finaliza se a pilha 2 estiver cheia
        }

        if (p2.topo == -1 || value > p2.stack[p2.topo]) {
            p2.stack[++p2.topo] = value; // Empilha na pilha 2
        } else {
            printf("Movimento inválido: %d não pode ser colocado sobre %d\n", value, p2.topo >= 0 ? p2.stack[p2.topo] : ' ');
            p1.stack[++p1.topo] = value; // Volta para a pilha 1
            break; // Finaliza em caso de erro
        }
    }

    // Exibindo os elementos da segunda pilha
    estado(&p2);

    return 0;
}