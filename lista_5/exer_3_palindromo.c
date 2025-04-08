#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char itens[MAX];
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

void empilhar(Pilha *p, char c) {
    if (!cheia(p)) {
        p->topo++;
        p->itens[p->topo] = c;
    }
}

char desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[p->topo--];
    }
    return '\0'; // Retorna nulo se a pilha estiver vazia
}

int verificaPalindromo(const char *str) {
    Pilha pilha;
    inicializar(&pilha);

    int n = strlen(str);

    // Empilha os caracteres da string na pilha
    for (int i = 0; i < n; i++) {
        empilhar(&pilha, toupper(str[i])); // Converte para maiúsculas para ignorar case
    }

    // Percorre a string novamente e compara com os caracteres desempilhados
    for (int i = 0; i < n; i++) {
        char c = desempilhar(&pilha);
        if (toupper(str[i]) != c) {
            return 0; // Não é palíndroma
        }
    }

    return 1; // É palíndroma
}

int main() {
    char cadeia[MAX];

    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    if (verificaPalindromo(cadeia)) {
        printf("A cadeia '%s' é palíndroma.\n", cadeia);
    } else {
        printf("A cadeia '%s' NÃO é palíndroma.\n", cadeia);
    }

    return 0;
}
