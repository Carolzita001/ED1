#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, char c) {
    if (!cheia(p)) {
        p->topo++;
        p->itens[p->topo] = c;
    }
}

char desempilhar(Pilha *p) {
    if (!vazia(p)) {
        char c = p->itens[p->topo];
        p->topo--;
        return c;
    }
    return '\0'; // Retorna nulo se a pilha estiver vazia
}

// Função que verifica se a string segue o formato WcM
int verificaFormato(const char *str) {
    Pilha pilha;
    inicializar(&pilha);

    int n = strlen(str);
    int i = 0;

    // Percorre a string até encontrar o caractere 'c'
    while (i < n && str[i] != 'c') {
        if (str[i] != 'a' && str[i] != 'b') {
            return 0; // Caractere inválido antes de 'c'
        }
        empilhar(&pilha, str[i]);
        i++;
    }

    // Verifica se o caractere 'c' existe
    if (i == n || str[i] != 'c') {
        return 0; // Não encontrou o 'c'
    }
    i++; // Avança para o próximo caractere após 'c'

    // Verifica se os caracteres após 'c' correspondem ao inverso de W
    while (i < n) {
        if (vazia(&pilha) || str[i] != desempilhar(&pilha)) {
            return 0; // Sequência não corresponde ao inverso
        }
        i++;
    }

    return vazia(&pilha);
}

int main() {
    char string[MAX];

    printf("Digite uma string contendo apenas as letras 'a', 'b', 'c': ");
    scanf("%s", string);

    if (verificaFormato(string)) {
        printf("A string pertence ao formato WcM.\n");
    } else {
        printf("A string NÃO pertence ao formato WcM.\n");
    }

    return 0;
}
