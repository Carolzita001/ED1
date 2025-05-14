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
        printf("\nErro ao alocar memória!\n");
    }else
    {
        novoItem->itens = valor;
        novoItem->proximo = NULL;
    }
    return novoItem;
}

tipoFila inserir(tipoFila fila, int valor){
    tipoFila novoItem = criarItem(valor);
    if (fila==NULL)
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
    }
    return fila;
}

tipoFila remover(tipoFila fila){
    if (fila==NULL)
    {
        printf("\nVazia!\n");
    }else
    {
        tipoFila aux = fila;
        fila = fila->proximo;
        free(aux);
        aux = NULL;
    }
    return fila;
}

void exibir(tipoFila fila){
    if (fila==NULL)
    {
        printf("\nVazia!\n");
    }else
    {
        tipoFila aux = fila;
        while (aux!=NULL)
        {
            printf("%d\n", aux->itens);
            aux = aux->proximo;
        }
    }
}

int main(){
    tipoFila fila = NULL;

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
                fila = inserir(fila, valor);
            }
            break;
        case 2:
            fila = remover(fila);
            break;
        case 3:
            exibir(fila);
            break;
        default:
            break;
        }
    }
    return 0;
}