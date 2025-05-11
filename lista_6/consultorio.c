#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 3

int quant_pacient = 0;
int paciente_priorit = 0;

typedef struct Paciente
{
    char nome[50];
    int idade;
}Paciente;

typedef struct Fila
{
    int inicio;
    int fim;
    struct Paciente itens[TAM];
}Fila;

void iniciar(Fila *fila){
    fila->inicio = 0;
    fila->fim = -1;
}

int vazia(Fila *fila){
    if(fila->fim < fila->inicio){
        printf("\n\n[Vazia!]\n\n");
        return 1;
    }else return 0;
}

void enfileirar(Fila *fila, Paciente p){
    if(fila->fim == TAM - 1){
        printf("\n\n[Cheia!]\n\n");
    }else{
        fila->fim ++;
        fila->itens[fila->fim] = p;
        quant_pacient ++;
    }
}

void enfileira_prioritario(Fila *fila, Paciente p){
    if (fila->fim == TAM - 1)
    {
        printf("\n\n[Cheia!]\n\n");
    }else
    {
        if (vazia(fila))
        {
            fila->fim ++;
            fila->itens[fila->fim] = p;
            quant_pacient ++;
        }else
        {
            for (int i = fila->fim; i >= fila->inicio; i--)
            {
                fila->itens[i+1] = fila->itens[i];
            }

            fila->itens[fila->inicio] = p;
            fila->fim ++;
            quant_pacient ++;
        }
        
        
    }
    
    
}

void desenfileirar(Fila *fila, Paciente *p){
    if (!vazia(fila))
    {
        if (fila->itens[fila->inicio].idade >= 60)
        {
            paciente_priorit --;
            *p = fila->itens[fila->inicio];
            fila->inicio ++;
            quant_pacient --;
        }else{
            *p = fila->itens[fila->inicio];
            fila->inicio ++;
            quant_pacient --;
        }
        if (fila->inicio > fila->fim)
        {
            iniciar(fila);
        }
        
    }else printf("\n\nFila vazia, não há passientes esperando!\n\n");
}

void exibir(Fila *fila){
    if(vazia(fila)){
        printf("[vazia!]\n");
    }else
    {
        printf("\n------Fila atual------:\n");
        for (int i = fila->inicio; i <= fila->fim; i++)
        {
            printf("\nNome: %s Idade: %d\n\n", fila->itens[i].nome, fila->itens[i].idade);
        }
    }
}
    

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    Fila fila, aux;
    Paciente p, p_aux;

    iniciar(&fila);
    iniciar(&aux);

    int caso;

    do
    {
        printf("0) Sair\n");
        printf("1) Adicionar paciente a fila de espera\n");
        printf("2) Chamar o paciente para ser atendido\n");
        printf("3) Verificar número de pacientes na fila\n");
        printf("4) Verificar o próximo paciente a ser atendido\n");
        printf("5) Verificar quantidade de pacientes do atendimento prioritário\n");
        scanf("%d", &caso);
        switch (caso)
        {
        case 1:
            for(int i = 0; i<TAM; i++){
                printf("Insira o nome e a idade do paciente %d:\n", i+1);
                scanf("%s %d", p.nome, &p.idade);
                if (p.idade >= 60)
                {
                    enfileira_prioritario(&fila, p);
                    paciente_priorit ++;
                    printf("Adicionando paciente prioritário no começo da fila!\n");
                    exibir(&fila);
                }else
                {
                    enfileirar(&fila, p);
                    printf("Adicionando paciente a fila de espera!\n");
                }
            }
            break;
        case 2:
            desenfileirar(&fila, &p_aux);
            printf("\n------Fila atual------:\n");
            exibir(&fila);
            break;
        case 3:
            printf("Quantidade de Pacientes: %d\n", quant_pacient);
            break;
        case 4:
            if(!vazia(&fila)){
                printf("\n\nPróximo paciente: \n[Nome]: %s [Idade]: %d\n\n", fila.itens[fila.inicio].nome, fila.itens[fila.inicio].idade);
            }else printf("A fila está vazia!\n");
            break;
        case 5:
            printf("Quantidade de Pacientes prioritários: %d\n", paciente_priorit);
            printf("\n\n------Fila atual------:\n\n");
            exibir(&fila);
            break;
        default:
            break;
        }
     
    } while (caso != 0);
}