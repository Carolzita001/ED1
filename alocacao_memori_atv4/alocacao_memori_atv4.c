#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *vetor = NULL;
int n = 0;

void alocar_preencher() {
    printf("Digite o número de elementos:\n");
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    printf("Preenchendo com zeros:\n");
    for (int i = 0; i < n; i++) {
        vetor[i] = 0;
    }

    printf("Vetor preenchido com zeros:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void preenchendo() {
    for (int i = 0; i < n; i++) {
        printf("Insira o %d° número:\n", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void imprimindo() {
    printf("Valores armazenados no vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    alocar_preencher();
    preenchendo();
    imprimindo();

    free(vetor);
    return 0;
}
