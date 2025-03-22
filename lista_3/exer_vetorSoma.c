#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int n;
    int *vetor = NULL;
    int soma = 0;

    printf("Insira o n�mero de elementos:\n");
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Erro na aloca��o�o de mem�ria!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Insira o %d� n�mero:\n", i+1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < n; i++)
    {
        soma += vetor[i];
    }
    
    printf("A soma dos n�meros inseridos: %d\n", soma);

    free(vetor);
    return 0;
}