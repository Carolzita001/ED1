#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    struct Pessoa *proximo;
}Pessoa;

typedef struct Fila{
    Pessoa *primeiro;
    Pessoa *ultimo;
}Fila;

int vazia(Fila *fila){
    return fila->primeiro == NULL;
}

void iniciar(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

void enfileirar(Fila *fila, Pessoa p){
    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    if(!novo){
        printf("Erro ao alicar a memória!\n");
        return;
    }

    *novo = p;
    novo->proximo = NULL;

    if (fila->ultimo == NULL)
    {
        fila->primeiro = novo;
    
    }else{
        fila->ultimo->proximo = novo;
    }
    fila->ultimo = novo;
}

int desenfileirar(Fila *fila, Pessoa *p){
    if (vazia(fila))
    {
        printf("\t[vazia!]\n");
        return 0;
    }
    Pessoa *temp = fila->primeiro;
    *p = *temp;
    fila->primeiro = temp->proximo;

    if(fila->primeiro == NULL){
        fila->ultimo = NULL;
    }
    
    free(temp);
    return 1;
}

void exibir(Fila *fila){
    if (vazia(fila) == 1)
    {
        printf("\t[vazia]\n");
        return;
    }

    Pessoa *atual = fila->primeiro;
    while (atual != NULL)
    {
        printf("Nome: %s, Idade: %d\n", atual->nome, atual->idade);
        atual = atual->proximo;
    }
}

int main(){
    char nome[50];
    Pessoa p;
    Fila fila, aux;

    iniciar(&fila);
    iniciar(&aux);

    for (int i = 0; i < 3; i++)
    {
        printf("Digite o nome e a idade da pessoa %d:\n", i + 1);
        scanf("%s %d", p.nome, &p.idade);
        enfileirar(&fila, p);
    }

    printf("\n------Fila inicial------:\n");
    exibir(&fila);

    printf("\nQual pessoa deseja desenfileirar?\n");
    scanf("%s", nome);

    while(!vazia(&fila)){
        desenfileirar(&fila, &p);

        if (strcmp(p.nome, nome) == 0)
        {
            printf("\nNOME ENCONTRADO: %s\n", p.nome);
            printf("\n------Fila atual------:\n");
            exibir(&fila);
        }else{
            enfileirar(&aux, p);
        }
    }

    printf("\n------Fila auxiliar------:\n");
    exibir(&aux);

    return 0;
}