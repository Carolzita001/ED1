#include <stdio.h>
#include <locale.h>

#define MAX_DISCOS 3

typedef struct Pilha {
    int topo;
    int discos[MAX_DISCOS];
} Pilha;

Pilha p1 = {MAX_DISCOS - 1, {3, 2, 1}};
Pilha p2 = {-1, {0, 0, 0}};
Pilha p3 = {-1, {0, 0, 0}};

void mostrarPilha(Pilha *p, int numPilha) {
    printf("|Haste %d: ", numPilha);
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->discos[i]);
    }
    printf("\n");
}

int tirarDisco(Pilha *p) {
    if (p->topo == -1) {
        printf("Erro: Haste vazia!\n");
        return -1;
    }
    return p->discos[p->topo--];
}

void colocarDisco(Pilha *p, int disco) {
    if (p->topo == MAX_DISCOS - 1) {
        printf("Erro: Haste cheia!\n");
        return;
    }
    if (p->topo >= 0 && p->discos[p->topo] < disco) {
        printf("Erro: Movimento inválido!\n");
        return;
    }
    p->discos[++p->topo] = disco;
}

Pilha* selecionarPilha(int num) {
    switch (num) {
        case 1: return &p1;
        case 2: return &p2;
        case 3: return &p3;
        default: return NULL;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcaoTirar, opcaoColocar, disco;
    while (1) {
        printf("\n[    TORRE DE RANÓI    ]\n");
        mostrarPilha(&p1, 1);
        mostrarPilha(&p2, 2);
        mostrarPilha(&p3, 3);

        printf("Digite o número da haste para tirar um disco. Ou digite 0 para saur: ");
        scanf("%d", &opcaoTirar);
        if (opcaoTirar == 0) break;

        Pilha *origem = selecionarPilha(opcaoTirar);
        if (!origem) continue;
        
        disco = tirarDisco(origem);
        if (disco == -1) continue;

        printf("Digite o número da haste para colocar o disco: ");
        scanf("%d", &opcaoColocar);

        Pilha *destino = selecionarPilha(opcaoColocar);
        if (!destino) continue;

        colocarDisco(destino, disco);
    }
    return 0;
}
