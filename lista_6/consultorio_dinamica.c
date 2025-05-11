#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int quant_paciente = 0;
int paciente_prioritario = 0;

typedef struct Paciente
{
    char nome[50];
    int idade;
    struct Paciente *proximo;
}Paciente;

typedef struct Fila
{
    Paciente *primeiro;
    Paciente *ultimo;
}Fila;


void iniciar(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int vazia(Fila *fila){
    if(fila->primeiro == NULL){
        printf("\n[Vazia!]\n");
        return 1;
    }else return 0;
}

void enfileirar(Fila *fila, Paciente p){
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if(!novo){
        printf("Erro na alocação de memória\n");
    }

    *novo = p;
    novo->proximo = NULL;
    if(fila->ultimo == NULL){
        fila->primeiro = novo;
    }else fila->ultimo->proximo = novo;

    fila->ultimo = novo;
    quant_paciente ++;
}

void enfilera_prioritario(Fila *fila, Paciente p) {
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if (!novo) {
        printf("Erro na alocação de memória\n");
        return;
    }

    // Copia os dados do paciente para o novo nó
    *novo = p;
    novo->proximo = NULL;

    if (vazia(fila)) {
        // Se a fila estiver vazia, o novo nó será o único elemento
        fila->primeiro = novo;
        fila->ultimo = novo;
    } else {
        // Insere o novo nó no início da fila
        novo->proximo = fila->primeiro;
        fila->primeiro = novo;
    }

    // Atualiza os contadores
    quant_paciente++;
    paciente_prioritario++;
}

void desenfileirar(Fila *fila, Paciente *p){
    if(!vazia(fila)){
        Paciente *temp = fila->primeiro;
        *p = *temp;
        fila->primeiro = temp->proximo;

        if(fila->primeiro == NULL){
            fila->ultimo = NULL;
        }
        quant_paciente --;
        free(temp);
    }
}

void exibir(Fila *fila){
    if(!vazia(fila)){
        Paciente *atual = fila->primeiro;
        while (atual != NULL)
        {
            printf("[Nome]: %s [Idade]: %d\n", atual->nome, atual->idade);
            atual = atual->proximo;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    Fila fila;
    Paciente p;

    iniciar(&fila);

    int caso, num;

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
            printf("Quantos pacientes deseja inserir?\n");
            scanf("%d", &num);
            for(int i = 0; i<num; i++){
                printf("Insira o nome e a idade do paciente %d:\n", i+1);
                scanf("%s %d", p.nome, &p.idade);
                if (p.idade >= 60)
                {
                    enfilera_prioritario(&fila, p);
                    paciente_prioritario ++;
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
            desenfileirar(&fila, &p);
            printf("\n------Fila atual------:\n");
            exibir(&fila);
            break;
        case 3:
            printf("Quantidade de Pacientes: %d\n", quant_paciente);
            break;
        case 4:
            if(!vazia(&fila)){
                printf("\n\nPróximo paciente: \n[Nome]: %s [Idade]: %d\n\n", fila.primeiro->nome, fila.primeiro->idade);
            }else printf("A fila está vazia!\n");
            break;
        case 5:
            printf("Quantidade de Pacientes prioritários: %d\n", paciente_prioritario);
            printf("\n\n------Fila atual------:\n\n");
            exibir(&fila);
            break;
        default:
            break;
        }
     
    } while (caso != 0);
}