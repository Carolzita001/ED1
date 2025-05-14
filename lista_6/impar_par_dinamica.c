#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM
{
    int itens;
    struct ITEM *proximo;
}*tipoFila;

tipoFila criarItem(int valor){
    tipoFila novoItem = (tipoFila)malloc(sizeof(tipoFila));
    if (novoItem == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }else
    {
        novoItem->itens = valor;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

tipoFila inserir(tipoFila fila, int valor){
    tipoFila novoItem = criarItem(valor);
    if (fila == NULL)
    {
        return novoItem;
    }else
    {
        tipoFila aux = fila;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novoItem;
        return fila;
    }
}
/*
void remover(tipoFila fila){
    if (fila == NULL)
    {
        printf("\nVazia!\n");
    }else
    {
        tipoFila aux = fila;
        fila = fila->proximo;
        free(aux);
        aux = NULL;
        return fila;
    }
}*/

void exibir(tipoFila fila){
    if (fila == NULL)
    {
        printf("\nVazia!\n");
    }else
    {
        tipoFila aux = fila;
        while (aux->proximo != NULL)
        {
            printf("\n%d\n", aux->itens);
            aux = aux->proximo;
        }
    }
}

int main(){
    tipoFila filaA, filaB;
    filaA = NULL;
    filaB = NULL;

    int valor;

    for (int i = 0; i < 20; i++)
    {
        printf("Insira 20 números inteiros:\n");
        scanf("%d", &valor);

        if (valor % 2 == 0)
        {
            filaA = inserir(filaA, valor);
        }else
        {
            filaB = inserir(filaB, valor);
        }
    }
    printf("\nFila A de números pares:\n");
    exibir(filaA);
    printf("\nFila B de números impares:\n");
    exibir(filaB);
    return 0;
}