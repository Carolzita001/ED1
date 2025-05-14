#include <stdlib.h>
#include <stdio.h>

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

int vazia(Fila *fila){
    if (fila->ultimo < fila->primeiro)
    {
        return 1;
    }else return 0;
}

int cheia(Fila *fila){
    if(fila->ultimo == TAM - 1){
        return 1;
    }else return 0;
}

void inserir(Fila *fila, int valor){
    if (cheia(fila) == 1)
    {
        printf("\nCheia!\n");
    }else
    {
        fila->ultimo ++;
        fila->itens[fila->ultimo] = valor;
    }
}
/*
void remover(Fila *fila){
    int aux = 0;
    if (vazia(fila) == 1)
    {
        printf("\nVazia!\n");
    }else
    {
        aux = fila->itens[fila->primeiro];
        fila->primeiro ++;
    }
}*/

void exibir(Fila *fila){
    if (vazia(fila) == 1)
    {
        printf("\nVazia!\n");
    }else
    {
        for (int i = fila->primeiro; i <= fila->ultimo; i++)
        {
            printf("\n%d\n", fila->itens[i]);
        }
    }
}

int main(){
    Fila filaA, filaB;
    iniciar(&filaA);
    iniciar(&filaB);

    int valor;

    for (int i = 0; i < 20; i++)
    {
        printf("Insira 20 números inteiros:\n");
        scanf("%d", &valor);
        if (valor % 2 == 0)
        {
            inserir(&filaA, valor);
        }else
        {
            inserir(&filaB, valor);
        }
    }
    printf("\nFila A de números pares:\n");
    exibir(&filaA);
    printf("\nFila B de números impares:\n");
    exibir(&filaB);

    return 0;
}