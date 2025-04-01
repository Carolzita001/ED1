#include <stdio.h>
#include <locale.h>

int main(){
    int vetor[6];
    int *ptr = vetor;

    printf("Digite seis números inteiros:\n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", ptr + 1);
    }
    
    printf("Valores e seus endereços de memória:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Valor: %d (Endereço: %p)\n", *(ptr + 1), (void*)(ptr + i));
    }

    return 0;
}