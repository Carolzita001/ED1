#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct ITEM
{
    int primeiro;
    int ultimo;
    int itens[TAM];
}Fila;

void iniciar(Fila *fila){
    fila->primeiro = 0;
    fila->ultimo = -1;
}

int cheia(Fila *fila){

    if( fila->ultimo == TAM-1){
        return 1;
    }else {
        return 0;
    }
}

int vazia(Fila *fila){

    if(fila->primeiro > fila->ultimo){
        return 1;
    }else {
        return 0;
    }
}

void inserir(Fila *fila, int valor){
    if (cheia(fila)==1)
    {
        printf("\nCheia!\n");
    }else
    {
        fila->ultimo ++;
        fila->itens[fila->ultimo] = valor;
    }
}

void desenfileirar(Fila *fila){
    int aux = 0;
    if (vazia(fila)==1)
    {
        printf("\nVazia!\n");
    }else
    {
        aux = fila->itens[fila->primeiro];
        fila->primeiro ++;
    }
}

void exibir(Fila *fila){
    if (vazia(fila)==1)
    {
        printf("\nVazia!\n");
    }else
    {
        for (int i = fila->primeiro; i <= fila->ultimo; i++)
        {
            printf("%d\n", fila->itens[i]);
        }
    }
}

void intercalaFila(Fila *fila1, Fila *fila2, Fila *fila3) {
    if (sizeof(fila1)==sizeof(fila2))
    {
        while (!vazia(fila1) || !vazia(fila2)) {
            if (!vazia(fila1)) {
                inserir(fila3, fila1->itens[fila1->primeiro]);
                desenfileirar(fila1);
            }
            if (!vazia(fila2)) {
                inserir(fila3, fila2->itens[fila2->primeiro]);
                desenfileirar(fila2);
            }
        }
    }
    
}

int main(){
    Fila fila1, fila2, fila3;
    iniciar(&fila1);
    iniciar(&fila2);
    iniciar(&fila3);

    int n1, n2, valor;

    // Inserindo valores na fila1
    printf("Quantos valores deseja inserir na fila 1? (de 1 a 5)\n");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Digite o valor %d para a fila 1: ", i + 1);
        scanf("%d", &valor);
        inserir(&fila1, valor);
    }

    // Inserindo valores na fila2
    printf("Quantos valores deseja inserir na fila 2? (de 1 a 5)\n");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Digite o valor %d para a fila 2: ", i + 1);
        scanf("%d", &valor);
        inserir(&fila2, valor);
    }

    // Intercalando as filas
    intercalaFila(&fila1, &fila2, &fila3);

    // Exibindo a fila intercalada
    printf("\nFila intercalada:\n");
    exibir(&fila3);

    return 0;
}