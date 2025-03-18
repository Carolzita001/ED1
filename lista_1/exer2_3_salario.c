#include <stdio.h>
#include <locale.h>

struct registro {
    char nome[20];
    double salario;
    int idade;
    char sexo;
};

struct registro adicionaSalario(struct registro r) {
    printf("Insira o seu salário atual: ");
    scanf("%lf", &r.salario);
    return r;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct registro meuRegistro;

    meuRegistro.salario = 0.0;

    meuRegistro = adicionaSalario(meuRegistro);

    if (meuRegistro.salario >= 5000) {
        printf("Salário Alto!\n");
    } else {
        printf("Salário baixo! Melhore\n");
    }

    return 0;
}
