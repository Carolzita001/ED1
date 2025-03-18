#include <stdio.h>
#include <string.h>

#define MAX_ESTUDANTES 100
#define MAX_FUNCIONARIOS 100

typedef struct {
    char ultimoNome[50];
    char primeiroNome[50];
    float indiceGraduacao;
} Estudante;

typedef struct {
    char ultimoNome[50];
    char primeiroNome[50];
    float salario;
} Funcionario;

void concederAumento(Estudante estudantes[], int numEstudantes, Funcionario funcionarios[], int numFuncionarios) {
    for (int i = 0; i < numEstudantes; i++) {
        if (estudantes[i].indiceGraduacao > 3.0) {
            for (int j = 0; j < numFuncionarios; j++) {
                if (strcmp(estudantes[i].ultimoNome, funcionarios[j].ultimoNome) == 0 &&
                    strcmp(estudantes[i].primeiroNome, funcionarios[j].primeiroNome) == 0) {
                    funcionarios[j].salario *= 1.10;
                }
            }
        }
    }
}

int main() {
    Estudante estudantes[MAX_ESTUDANTES];
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numEstudantes, numFuncionarios;

    printf("Quantos estudantes deseja cadastrar? ");
    scanf("%d", &numEstudantes);
    for (int i = 0; i < numEstudantes; i++) {
        printf("\nEstudante %d:\n", i + 1);
        printf("último nome: ");
        scanf("%s", estudantes[i].ultimoNome);
        printf("Primeiro nome: ");
        scanf("%s", estudantes[i].primeiroNome);
        printf("Índice de graduação: ");
        scanf("%f", &estudantes[i].indiceGraduacao);
    }

    printf("\nQuantos funcionários deseja cadastrar? ");
    scanf("%d", &numFuncionarios);
    for (int i = 0; i < numFuncionarios; i++) {
        printf("\nFuncionário %d:\n", i + 1);
        printf("último nome: ");
        scanf("%s", funcionarios[i].ultimoNome);
        printf("Primeiro nome: ");
        scanf("%s", funcionarios[i].primeiroNome);
        printf("Salário: ");
        scanf("%f", &funcionarios[i].salario);
    }

    concederAumento(estudantes, numEstudantes, funcionarios, numFuncionarios);

    printf("\nFuncionários após aumento:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("%s %s: Salário = %.2f\n", funcionarios[i].primeiroNome, funcionarios[i].ultimoNome, funcionarios[i].salario);
    }

    return 0;
}