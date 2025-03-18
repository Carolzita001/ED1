#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void cadastrarProdutos(Produto produtos[], int *numProdutos) {
    int n, i;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nCadastro do produto %d:\n", i + 1);

        printf("Código: ");
        scanf("%d", &produtos[*numProdutos].codigo);

        printf("Nome: ");
        scanf(" %s", produtos[*numProdutos].nome);

        printf("Quantidade disponíel: ");
        scanf("%d", &produtos[*numProdutos].quantidade);

        printf("Preço de venda: ");
        scanf("%f", &produtos[*numProdutos].preco);

        (*numProdutos)++;
    }
}

void realizarVenda(Produto produtos[], int numProdutos) {
    int codigo, quantidade, i;
    float valorTotal = 0;

    printf("\nVenda de produtos:\n");

    while (1) {
        printf("\nDigite o código do produto (ou -1 para finalizar): ");
        scanf("%d", &codigo);

        if (codigo == -1) {
            break;
        }

        for (i = 0; i < numProdutos; i++) {
            if (produtos[i].codigo == codigo) {
                printf("Produto encontrado: %s\n", produtos[i].nome);
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);

                if (quantidade <= produtos[i].quantidade) {
                    produtos[i].quantidade -= quantidade;
                    float valorProduto = quantidade * produtos[i].preco;
                    valorTotal += valorProduto;

                    printf("Produto adicionado á nota fiscal: %s | Quantidade: %d | Preçoo unitário: %.2f | Subtotal: %.2f\n",
                           produtos[i].nome, quantidade, produtos[i].preco, valorProduto);
                } else {
                    printf("Quantidade indisponível no estoque.\n");
                }
                break;
            }
        }

        if (i == numProdutos) {
            printf("Produto não encontrado.\n");
        }
    }

    printf("\nValor total da compra: %.2f\n", valorTotal);
}

int main() {
    setlocale(LC_ALL,"Portuguese_Brasil");
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar produtos\n");
        printf("2. Realizar venda\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProdutos(produtos, &numProdutos);
                break;
            case 2:
                realizarVenda(produtos, numProdutos);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
