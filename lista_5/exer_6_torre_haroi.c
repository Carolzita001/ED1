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
        p->itens[++p->topo] = elemento;
    }
}

int desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo--];
    }
    return -1; // Retorna -1 se a pilha estiver vazia
}

// Função para exibir os movimentos
void moverDisco(char origem, char destino, int disco, int *contador) {
    printf("Movimento %d: Mover disco %d da haste %c para a haste %c\n", ++(*contador), disco, origem, destino);
}

// Função recursiva para resolver a Torre de Hanói
void resolverTorreHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar, char nomeOrigem, char nomeDestino, char nomeAuxiliar, int *contador) {
    if (n == 1) {
        int disco = desempilhar(origem);
        empilhar(destino, disco);
        moverDisco(nomeOrigem, nomeDestino, disco, contador);
        return;
    }

    // Move n-1 discos da origem para a auxiliar
    resolverTorreHanoi(n - 1, origem, auxiliar, destino, nomeOrigem, nomeAuxiliar, nomeDestino, contador);

    // Move o disco restante da origem para o destino
    int disco = desempilhar(origem);
    empilhar(destino, disco);
    moverDisco(nomeOrigem, nomeDestino, disco, contador);

    // Move n-1 discos da auxiliar para o destino
    resolverTorreHanoi(n - 1, auxiliar, destino, origem, nomeAuxiliar, nomeDestino,
                       nomeOrigem, contador);
}

int main() {
    int numDiscos;
    Pilha hasteA, hasteB, hasteC;
    inicializar(&hasteA);
    inicializar(&hasteB);
    inicializar(&hasteC);

    printf("Número de discos: ");
    scanf("%d", &numDiscos);

    // Empilha os discos na haste A
    for (int i = numDiscos; i >= 1; i--) {
        empilhar(&hasteA, i);
    }

    printf("Resolvendo a Torre de Hanói com %d discos:\n", numDiscos);

    int contadorMovimentos = 0;
    resolverTorreHanoi(numDiscos, &hasteA, &hasteC, &hasteB, 'A', 'C', 'B',
                       &contadorMovimentos);

    return 0;
}
