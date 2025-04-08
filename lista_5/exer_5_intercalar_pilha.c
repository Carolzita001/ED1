#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int elemento) {
    if (!cheia(p)) {
        p->topo++;
        p->itens[p->topo] = elemento;
    }
}

int desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo--];
    }
    return -1; // Retorna -1 caso a pilha esteja vazia
}

// Retorna o tamanho da pilha
int tamanho(Pilha *p) {
    return p->topo + 1;
}

// Função que intercala duas pilhas
Pilha intercalaPilha(Pilha *p1, Pilha *p2) {
    Pilha p3;
    inicializar(&p3);

    // Verifica se as pilhas têm o mesmo tamanho
    if (tamanho(p1) != tamanho(p2)) {
        printf("As pilhas não têm o mesmo tamanho! Não é possível intercalar.\n");
        return p3;
    }

    Pilha temp1, temp2;
    inicializar(&temp1);
    inicializar(&temp2);

    // Transfere os elementos de p1 e p2 para pilhas temporárias (invertendo a ordem)
    while (!vazia(p1)) {
        empilhar(&temp1, desempilhar(p1));
    }
    while (!vazia(p2)) {
        empilhar(&temp2, desempilhar(p2));
    }

    // Intercala os elementos de temp1 e temp2 em p3
    while (!vazia(&temp1) && !vazia(&temp2)) {
        empilhar(&p3, desempilhar(&temp1)); // Elemento de p1
        empilhar(&p3, desempilhar(&temp2)); // Elemento de p2
    }

    return p3;
}

void exibir(Pilha *p) {
    Pilha temp;
    inicializar(&temp);

    // Desempilha os elementos para exibição e armazena na pilha temporária
    while (!vazia(p)) {
        int elemento = desempilhar(p);
        printf("%d ", elemento);
        empilhar(&temp, elemento);
    }
    printf("\n");

    // Reconstrói a pilha original
    while (!vazia(&temp)) {
        empilhar(p, desempilhar(&temp));
    }
}

int main() {
    Pilha p1, p2, p3;
    inicializar(&p1);
    inicializar(&p2);

    // Preenche p1
    empilhar(&p1, 1);
    empilhar(&p1, 3);
    empilhar(&p1, 5);

    // Preenche p2
    empilhar(&p2, 2);
    empilhar(&p2, 4);
    empilhar(&p2, 6);

    printf("Pilha 1: ");
    exibir(&p1);
    printf("Pilha 2: ");
    exibir(&p2);

    // Intercala as pilhas
    p3 = intercalaPilha(&p1, &p2);

    printf("Pilha intercalada: ");
    exibir(&p3);

    return 0;
}
