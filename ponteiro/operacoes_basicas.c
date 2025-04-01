#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int num1, num2;
    int *ptr1, *ptr2;

    *ptr1 = &num1;
    *ptr2 = &num2;

    printf("Digite dois números inteiros: ");
    scanf("%d %d", ptr1, ptr2);

    printf("Números digitados: %d e %d\n", ptr1, ptr2);
    printf("Soma: %d\n", (*ptr1 + *ptr2));
    printf("Subtração: %d\n", (*ptr1 - *ptr2));
    printf("Multiplicação: %d\n", (*ptr1 * *ptr2));

    if (*ptr2 != 0)
    {
        //(float)*ptr1 serve para converter o valor armazenado por ptr1 para ponto flutuante
        printf("Divisão: %.2f\n", ((float)*ptr1 / *ptr2));
    }else{
        printf("Divisão: Não é possivel dividir por zero.\n");
    }
    

    return 0;
}