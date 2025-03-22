#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_MAX_NOME 50

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;
    char **vetor;

    printf("Insira o número de nomes que deseja inserir:\n");
    scanf("%d", &n);

    vetor = (char **)malloc(n * sizeof(char *));
    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = (char *)malloc(TAM_MAX_NOME * sizeof(char));
        if (vetor[i] == NULL) {
            printf("Erro ao alocar memória para o nome %d.\n", i + 1);
            exit(1);
        }
    }

    getchar();

    for (int i = 0; i < n; i++) {
        printf("Insira o %d° nome:\n", i + 1);
        fgets(vetor[i], TAM_MAX_NOME, stdin);

        size_t len = strlen(vetor[i]);
        if (len > 0 && vetor[i][len - 1] == '\n') {
            vetor[i][len - 1] = '\0';
        }
    }

    printf("\nNomes armazenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i + 1, vetor[i]);
    }

    for (int i = 0; i < n; i++) {
        free(vetor[i]);
    }
    free(vetor);

    return 0;
}
