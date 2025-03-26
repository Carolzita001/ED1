#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
} Aluno;

int main() {
    int quantidade;
    Aluno *alunos;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quantidade);

    alunos = (Aluno *)malloc(quantidade * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nCadastro do aluno %d:\n", i + 1);

        getchar();

        printf("Digite o nome do aluno: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Digite a idade do aluno: ");
        scanf("%d", &alunos[i].idade);
    }

    printf("\nLista de alunos cadastrados:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Aluno %d: Nome: %s, Idade: %d\n", i + 1, alunos[i].nome, alunos[i].idade);
    }

    free(alunos);

    printf("\nMemória liberada. Programa encerrado.\n");
    return 0;
}
