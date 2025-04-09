#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Tamanho máximo da pilha

typedef struct {
    int topo;
    int itens[MAX];
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int isEmpty(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

// Adiciona um elemento à pilha
void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

// Remove um elemento da pilha
int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->itens[(p->topo)--];
}

// Retorna o elemento do topo sem removê-lo
int peek(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->itens[p->topo];
}

// Exibe os elementos da pilha
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

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    display(&p);

    printf("Elemento removido: %d\n", pop(&p));
    display(&p);

    printf("Topo da pilha: %d\n", peek(&p));

    return 0;
}
