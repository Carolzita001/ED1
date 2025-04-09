#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Tamanho máximo da pilha

typedef struct {
    int topo;
    int itens[MAX];  // Array que armazena os elementos
} Pilha;

// 1. Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// 2. Verifica se a pilha está vazia
int isEmpty(Pilha *p) {
    return p->topo == -1;
}

// 3. Verifica se a pilha está cheia
int isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

// 4. Insere um elemento no topo da pilha (PUSH)
void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

// 5. Remove e retorna o elemento do topo (POP)
int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->itens[(p->topo)--];
}

// 6. Retorna o elemento do topo sem remover (PEEK)
int peek(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->itens[p->topo];
}

// 7. Exibe todos os elementos da pilha
void display(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

// Exemplo de uso
int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 5);
    push(&p, 15);
    push(&p, 25);

    display(&p);

    printf("Topo: %d\n", peek(&p));

    printf("Removido: %d\n", pop(&p));
    display(&p);

    return 0;
}
