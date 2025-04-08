#include <stdio.h>
#include <locale.h>

#define MAX 20

typedef struct Pilha
{
    int topo;
    int itens[MAX];
}Pilha;

void inicializarPilha(Pilha *p){
    p->topo = -1;
}

int cheia(Pilha *p){
    return p->topo == MAX -1;
}

int vazia(Pilha *p){
    return p->topo == -1;
}

void empilhar(Pilha *p, int valor){
    if (!cheia(p))
    {
        p->topo++;
        p->itens[p->topo] = valor;
    }else
    {
        printf("Pilha cheia! Não é possível empilhar %d.\n", valor);
    }
    
    
}

void exibir(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia!\n");
    } else {
        for (int i = p->topo; i >= 0; i--) {
            printf("%d\n", p->itens[i]);
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese-Brazil");
  
    Pilha pA, pB;

    inicializarPilha(&pA);
    inicializarPilha(&pB);

    int num;

    printf("Digite 20 números inteiros:\n");
    for (int i = 0; i < 20; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &num);

        if (num % 2 == 0) {
            empilhar(&pA, num); 
        } else {
            empilhar(&pB, num); 
        }
    }

    printf("\n--- Pilha A (Números Pares) ---\n");
    exibir(&pA);

    printf("\n--- Pilha B (Números ímpares) ---\n");
    exibir(&pB);

    return 0;
}