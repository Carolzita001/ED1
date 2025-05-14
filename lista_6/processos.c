#include <stdio.h>
#include <stdlib.h>

#define TAM 3

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
    if (fila->ultimo == TAM -1)
    {
        return 1;
    }else return 0;
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

void remover(Fila *fila){
    int aux = 0;
    if (vazia(fila)==1)
    {
        printf("\nVazia!\n");
    }else
    {
        aux = fila->itens[fila->primeiro];
        fila->primeiro++;
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

int main(){
    Fila fila;
    iniciar(&fila);
    int valor, opcao, num;

    while (opcao!=0)
    {
        printf("0) Sair\n");
        printf("1) Incluir novos processos\n");
        printf("2) Retirar da fila o processo com maior tempo de espera\n");
        printf("3) Imprimir processos da fila de espera\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Quantos processos deseja inserir?\n");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                printf("Insira o numero %d:\n", i+1);
                scanf("%d", &valor);
                inserir(&fila, valor);
            }
            break;
        case 2:
            remover(&fila);
            break;
        case 3:
            exibir(&fila);
            break;
        default:
            break;
        }
    }
    return 0;
}