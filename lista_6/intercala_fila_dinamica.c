#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM
{
    int itens;
    struct ITEM *proximo;
}*tipoFila;

tipoFila criarItem(int valor){
    tipoFila novoItem = (tipoFila)malloc(sizeof(tipoFila));
    if (novoItem==NULL)
    {
        printf("Erro ao alcar memória!\n");
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
        while (aux->proximo!=NULL)
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

int comparaFila(tipoFila fila1, tipoFila fila2) {
    int tamanho1 = 0, tamanho2 = 0;

    // Calculando o tamanho da fila1
    tipoFila aux = fila1;
    while (aux != NULL) {
        tamanho1++;
        aux = aux->proximo;
    }

    // Calculando o tamanho da fila2
    aux = fila2;
    while (aux != NULL) {
        tamanho2++;
        aux = aux->proximo;
    }

    if (tamanho1 == tamanho2)
    {
        return 1;
    }else return 0;
    
}

void intercalaFila(tipoFila fila1, tipoFila fila2, tipoFila *fila3) {
    if (comparaFila(fila1, fila2)==1)
    {
        while (fila1 != NULL || fila2 != NULL) {
            // Intercalando elementos da fila1
            if (fila1 != NULL) {
                *fila3 = inserir(*fila3, fila1->itens);
                fila1 = fila1->proximo;
            }
    
            // Intercalando elementos da fila2
            if (fila2 != NULL) {
                *fila3 = inserir(*fila3, fila2->itens);
                fila2 = fila2->proximo;
            }
        }
    }
}

int main(){
    tipoFila fila1, fila2, fila3;
    fila1 = NULL;
    fila2 = NULL;
    fila3 = NULL;

    int n1, n2, valor;

    // Inserindo valores na fila1
    printf("Quantos valores deseja inserir na fila 1?\n");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Digite o valor %d para a fila 1: ", i + 1);
        scanf("%d", &valor);
        fila1 = inserir(fila1, valor);
    }

    // Inserindo valores na fila2
    printf("Quantos valores deseja inserir na fila 2?\n");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Digite o valor %d para a fila 2: ", i + 1);
        scanf("%d", &valor);
        fila2 = inserir(fila2, valor);
    }

    // Intercalando as filas
    intercalaFila(fila1, fila2, &fila3);

    // Exibindo a fila intercalada
    printf("\nFila intercalada:\n");
    exibir(fila3);

    return 0;
}