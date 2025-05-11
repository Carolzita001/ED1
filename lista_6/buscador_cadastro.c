#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3 

typedef struct pessoa {
    char nome[50]; // Add a name field
    int idade;
} pessoa;

typedef struct {
    int primeiro;
    int ultimo;
    struct pessoa itens[TAM];
} Fila;

void iniciar(Fila *fila) {
    fila->primeiro = 0;
    fila->ultimo = -1;
}

int vazia(Fila *fila){

    if(fila->primeiro > fila->ultimo){
        return 1;
    }else {
        return 0;
    }
}

int enfileirar(Fila *fila, pessoa p) {
    if (fila->ultimo == TAM - 1) {
        printf("\t[cheia!]");
        return 0; // Indica falha ao enfileirar
    } else {
        fila->ultimo++;
        fila->itens[fila->ultimo] = p;
        return 1; // Indica sucesso ao enfileirar
    }
}

void desenfileirar(Fila *fila, pessoa *valor) {
    if (fila->primeiro > fila->ultimo) {
        printf("\t[vazia!]\n");
    } else {
        *valor = fila->itens[fila->primeiro];
        fila->primeiro++;
    }
}

void exibir(Fila *fila) {
    if (vazia(fila) == 1) {
        printf("\t[vazia]\n");
        return;
    } else
    {
        for (int i = fila->primeiro; i <= fila->ultimo; i++) {
            printf("Nome: %s, Idade: %d\n", fila->itens[i].nome, fila->itens[i].idade);
        }
    }
}

int main() {
    char nome[50];

    struct pessoa p, p_aux;
    Fila fila;
    Fila aux;

    iniciar(&fila);
    iniciar(&aux);

    for (int i = 0; i < TAM; i++) {
        printf("Digite o nome e a idade da pessoa %d:\n", i + 1);
        scanf("%s %d", p.nome, &p.idade);
        enfileirar(&fila, p);
    }

    exibir(&fila);

    printf("\nQual pessoa deseja desenfileirar?\n");
    scanf("%s", nome);

    for (int i = 0; i <= fila.ultimo; i++) {
        if (strcmp(fila.itens[i].nome, nome) == 0) {
            printf("\nNOME ENCONTRADO: %s\n", fila.itens[i].nome);
            desenfileirar(&fila, &p_aux);
            printf("\n------Fila atual------:\n");
            exibir(&fila);
        } else {
            desenfileirar(&fila, &p_aux);
            printf("\nDESENFILEIRANDO: %s, %d\n", fila.itens[i].nome, fila.itens[i].idade);
            printf("\n------Fila atual------:\n");
            exibir(&fila);
            enfileirar(&aux, p_aux);
            printf("\nENFILEIRANDO NA FILA AUXILIAR: %s, %d\n", fila.itens[i].nome, fila.itens[i].idade);
            printf("\n------Fila auxiliar atual:------\n");
            exibir(&aux);
        }
    }

    return 0;
}


