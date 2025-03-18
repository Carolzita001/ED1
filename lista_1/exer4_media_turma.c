#include <stdio.h>
#include <locale.h>

#define MAX_ALUNOS 100

struct aluno {
    char nome[80];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
    float mediaAluno;
};

// Função para calcular a média de um aluno
void calcularMediaAluno(struct aluno *a) {
    a->mediaAluno = (a->p1 + a->p2 + a->p3) / 3.0;
}

// Função para criar o cadastro de um grupo de alunos
void criarCadastro(struct aluno alunos[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\nCadastro do aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Matrícula: ");
        scanf("%s", alunos[i].matricula);
        printf("Turma (A, B ou C): ");
        scanf(" %c", &alunos[i].turma);
        printf("Nota P1: ");
        scanf("%f", &alunos[i].p1);
        printf("Nota P2: ");
        scanf("%f", &alunos[i].p2);
        printf("Nota P3: ");
        scanf("%f", &alunos[i].p3);

        // Calcula a média do aluno
        calcularMediaAluno(&alunos[i]);
    }
}

// Função para imprimir o cadastro de um grupo de alunos
void imprimirCadastro(struct aluno alunos[], int qtd) {
    printf("\n--- Cadastro dos Alunos ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matrícula: %s\n", alunos[i].matricula);
        printf("Turma: %c\n", alunos[i].turma);
        printf("Nota P1: %.2f\n", alunos[i].p1);
        printf("Nota P2: %.2f\n", alunos[i].p2);
        printf("Nota P3: %.2f\n", alunos[i].p3);
        printf("Média Final: %.2f\n", alunos[i].mediaAluno);
    }
}

// Função para calcular e imprimir a média de uma turma específica
void imprimirMediaTurma(struct aluno alunos[], int qtd, char turma) {
    float somaMedias = 0.0;
    int count = 0;

    for (int i = 0; i < qtd; i++) {
        if (alunos[i].turma == turma) {
            somaMedias += alunos[i].mediaAluno;
            count++;
        }
    }

    if (count > 0) {
        float mediaTurma = somaMedias / count;
        printf("\nA média da turma %c é: %.2f\n", turma, mediaTurma);
    } else {
        printf("\nNenhum aluno encontrado na turma %c.\n", turma);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct aluno alunos[MAX_ALUNOS];
    int qtd;

    // Solicita o número de alunos a serem cadastrados
    printf("Quantos alunos deseja cadastrar? (máximo %d): ", MAX_ALUNOS);
    scanf("%d", &qtd);

    if (qtd > 0 && qtd <= MAX_ALUNOS) {
        // Cria e imprime o cadastro dos alunos
        criarCadastro(alunos, qtd);
        imprimirCadastro(alunos, qtd);

        // Permite calcular a média de uma turma
        char turma;
        printf("\nInforme a turma para calcular a média (A, B ou C): ");
        scanf(" %c", &turma);
        imprimirMediaTurma(alunos, qtd, turma);

    } else {
        printf("Quantidade inválida! O número deve estar entre 1 e %d.\n", MAX_ALUNOS);
    }

    return 0;
}
