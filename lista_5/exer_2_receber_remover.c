#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int idade;
} Pessoa;

typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, Pessoa pessoa) {
    if (!cheia(p)) {
        p->topo++;
        p->itens[p->topo] = pessoa;
    } else {
        printf("Pilha cheia! Não é possível empilhar mais itens.\n");
    }
}

Pessoa desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo--];
    }
    Pessoa pessoaVazia = {"", -1}; // Pessoa vazia para indicar erro
    return pessoaVazia;
}

// Remove um item da pilha pelo nome
void removerPorNome(Pilha *p, const char *nome) {
    Pilha temp;
    inicializar(&temp);
    int encontrado = 0;

    // Desempilha todos os elementos da pilha original
    // e verifica se o nome corresponde ao item a ser removido
    while (!vazia(p)) {
        Pessoa pessoa = desempilhar(p);
        if (strcmp(pessoa.nome, nome) == 0) {
            encontrado = 1; // Item encontrado, não o empilha na pilha temporária
        } else {
            empilhar(&temp, pessoa);
        }
    }

    // Reconstrói a pilha original a partir da pilha temporária
    while (!vazia(&temp)) {
        empilhar(p, desempilhar(&temp));
    }

    if (encontrado) {
        printf("Pessoa '%s' removida da pilha.\n", nome);
    } else {
        printf("Pessoa '%s' não encontrada na pilha.\n", nome);
    }
}

void exibir(Pilha *p) {
    Pilha temp;
    inicializar(&temp);

    // Desempilha os itens para exibição e armazena na pilha temporária
    while (!vazia(p)) {
        Pessoa pessoa = desempilhar(p);
        printf("Nome: %s, Idade: %d\n", pessoa.nome, pessoa.idade);
        empilhar(&temp, pessoa);
    }

    // Reconstrói a pilha original
    while (!vazia(&temp)) {
        empilhar(p, desempilhar(&temp));
    }
}

int main() {
    Pilha pilha;
    inicializar(&pilha);

    int opcao;
    char nome[MAX_NOME];
    Pessoa pessoa;

    do {
        printf("\n1. Adicionar pessoa\n");
        printf("2. Remover pessoa pelo nome\n");
        printf("3. Exibir pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!cheia(&pilha)) {
                    printf("Digite o nome: ");
                    scanf("%s", pessoa.nome);
                    printf("Digite a idade: ");
                    scanf("%d", &pessoa.idade);
                    empilhar(&pilha, pessoa);
                } else {
                    printf("Pilha cheia! Não é possível adicionar mais pessoas.\n");
                }
                break;

            case 2:
                printf("Digite o nome da pessoa a ser removida: ");
                scanf("%s", nome);
                removerPorNome(&pilha, nome);
                break;

            case 3:
                printf("\n--- Pilha atual ---\n");
                exibir(&pilha);
                break;

            case 4:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
