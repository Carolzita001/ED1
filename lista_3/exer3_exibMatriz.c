#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int m, n;
    int *matriz = NULL;

    printf("Insira o número de linhas:\n");
    scanf("%d", &m);
    printf("Insira o número de colunas:\n");
    scanf("%d", &n);

    matriz = (int *)malloc(m * n * sizeof(int));
    if (matriz == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Insira o elemento [%d][%d]:\n", i, j);
            scanf("%d", &matriz[i * n + j]);
        }
    }

    printf("\nMatriz inserida:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento na posição [%d][%d]: %d\n", i, j, matriz[i * n + j]);
        }
    }

    free(matriz);
    return 0;
}
