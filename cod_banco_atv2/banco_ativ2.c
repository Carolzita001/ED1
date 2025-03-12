#include <stdio.h>
#include <string.h>
#include <locale.h>

struct CONTA
{

    char nome[20];
    float saldo;
    int numero;
};

struct CONTA editar() {
    struct CONTA c;

    printf("\nDigite o novo nome: ");
    fgets(c.nome, sizeof(c.nome), stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0'; 

    printf("Digite o número da conta: ");
    scanf("%d", &c.numero);
    getchar(); 

    printf("\nDados atualizados:\n");
    printf("Nome: %s\n", c.nome);
    printf("Conta: %d\n", c.numero);

    return c;
}

struct CONTA criarConta()
{

    struct CONTA c;
    printf("Insira o primeiro nome do titular: ");
    scanf("%s", c.nome);
    printf("Insira o número da conta: ");
    scanf("%d", &c.numero);
    c.saldo = 0.0;
    return c;
}

struct CONTA depositar(struct CONTA c, float valor)
{

    if (valor > 0)
    {

        c.saldo = c.saldo + valor;
        printf("Depósito realizado com sucesso! Novo Saldo: %.2f\n", c.saldo);
    }
    else
    {

        printf("Valor inválido para depósito!\n");
    }
    return c;
}

struct CONTA sacar(struct CONTA c, float valor)
{

    if (valor > 0 && valor <= c.saldo)
    {
        c.saldo = c.saldo - valor;
        printf("Saque realizado com sucesso! Novo saldo: %.2f\n", c.saldo);
    }
    else
    {
        printf("Saque não permitido! Saldo insulficiente ou valor inválido.\n");
    }
    return c;
}

void consultarSaldo(struct CONTA c)
{
    printf("Titular: %s\nNúmero da Conta: %d\nSaldo: %.2f\n", c.nome, c.numero, c.saldo);
}

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");
    struct CONTA minhaConta;
    minhaConta = criarConta();
    int opcao;
    float valor;

    do
    {
        printf("\nMenu\n");
        printf("1) Editar a conta\n");
        printf("2) Depositar\n");
        printf("3) Realizar retirada\n");
        printf("4) Consultar Saldo\n");
        printf("0) Sair\n");
        printf("Ecolha um opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            minhaConta = editar();
            printf("Dados iniciais:\n");
            printf("Nome: %s\n", minhaConta.nome);
            printf("conta: %d\n", minhaConta.numero);
            minhaConta = editar();
            break;
        case 2:
            printf("Digitar o valor do depósito: ");
            scanf("%f", &valor);
            minhaConta = depositar(minhaConta, valor);
            break;
        case 3:
            printf("Digite o valor do saque: ");
            scanf("%f", &valor);
            minhaConta = sacar(minhaConta, valor);
            break;
        case 4:
            consultarSaldo(minhaConta);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Operação inválida!\n");
        }

    } while (opcao != 0);
    return 0;
}