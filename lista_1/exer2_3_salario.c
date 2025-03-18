#include <stdio.h>
#include <locale.h>

// Estrutura de registro
struct registro {
    char nome[20];
    double salario;
    int idade;
    char sexo;
};

// Função para adicionar o salário
struct registro adicionaSalario(struct registro r) {
    printf("Insira o seu salário atual: ");
    scanf("%lf", &r.salario); // Corrigido para usar %lf para double e passar o endereço
    return r;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct registro meuRegistro;

    // Inicializando o registro
    meuRegistro.salario = 0.0;

    // Chamando a função para preencher o salário
    meuRegistro = adicionaSalario(meuRegistro);

    // Verificando o salário
    if (meuRegistro.salario >= 5000) {
        printf("Salário Alto!\n");
    } else {
        printf("Salário baixo! Melhore\n");
    }

    return 0;
}
