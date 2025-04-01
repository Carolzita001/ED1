#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portugues_Brazil");

    int num1, num2, num3;
    int *ptr1 = &num1, *ptr2 = &num2, *ptr3 = &num3;

    printf("Digite três números inteiros: ");
    scanf("%d %d %d", ptr1, ptr2, ptr3);

    if (*ptr1 > *ptr2){

        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;

    }
    if(*ptr2 > *ptr3){

        int temp = *ptr2;
        *ptr2 = *ptr3;
        *ptr3 = temp;

    }
    if(*ptr1 > *ptr2){

        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
    }

    printf("Números em ordem crescente:\n");
    printf("%d (Endereço: %p)\n", *ptr1, (void*)ptr1);
    printf("%d (Endereço: %p)\n", *ptr2, (void*)ptr2);
    printf("%d (Endereço: %p)\n", *ptr3, (void*)ptr3);

    return 0;
}