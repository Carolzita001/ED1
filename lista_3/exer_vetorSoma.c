#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int n;
    int *vetor = NULL;
    int soma = 0;

    printf("Insira o número de elementos:\n");
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Erro na alocação£o de memória!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Insira o %d° número:\n", i+1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < n; i++)
    {
        soma += vetor[i];
    }
    
    printf("A soma dos números inseridos: %d\n", soma);

    free(vetor);
    return 0;
}