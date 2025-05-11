#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int quant_avioes = 0;

typedef struct Aviao
{
    char nome[50];
    int cod_id;
    struct Aviao *proximo;
}Aviao;

typedef struct Fila
{
    Aviao *primeiro;
    Aviao *ultimo;
}Fila;

void iniciar(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int vazia(Fila *fila){
    if(fila->primeiro == NULL){
        printf("[Vazia!]\n");
        return 1;
    }else return 0;
}

void enfileirar(Fila *fila, Aviao a){
    Aviao *novo = (Aviao *)malloc(sizeof(Aviao));
    if(!novo){
        printf("Erro na aloca��o de mem�ria!\n");
        return;
    }

    *novo = a;
    novo->proximo = NULL;
    if (fila->ultimo == NULL)
    {
        fila->primeiro = novo;
    }else fila->ultimo->proximo = novo;

    fila->ultimo = novo;

    quant_avioes ++;
}

int desenfileirar(Fila *fila, Aviao *a){
    if(vazia(fila)){
        printf("[Vazia!]\n");
        return 0;
    }else
    {
        Aviao *temp = fila->primeiro;
        *a = *temp;
        fila->primeiro = temp->proximo;

        if(fila->primeiro == NULL){
            fila->ultimo = NULL;
        }
        quant_avioes --;
        free(temp);
        return 1;
    }
}

void exibir(Fila *fila){
    if(vazia(fila)){
        printf("[Vazia!]\n");
    }else{
        Aviao *atual = fila->primeiro;
        while (atual != NULL)
        {
            printf("[Nome]: %s [ID]: %d\n\n", atual->nome, atual->cod_id);
            atual = atual->proximo;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portugues_Brazil");

    Aviao a;
    Fila fila;

    char opcao = 'n';
    int num, caso;

    do
    {
        printf("0) Sair\n");
        printf("1) Adicionar avi�o a fila de espera\n");
        printf("2) Autorizar decolagem\n");
        printf("3) Listar todos os avi�es na fila de espera\n");
        printf("4) Listar caracteristicas do primeiro avi�o da fila\n");
        printf("5) Listar o n�mero de avi�es aguardando na fila de decolagem\n");
        scanf("%d", &caso);
        switch (caso)
        {
        case 1:
            printf("Quantos avi�es deseja inserir? ");
            scanf("%d", &num);

            for (int i = 0; i < num; i++) {
                printf("Insira o nome e o ID do avi�o %d: \n", i + 1);
                scanf("%s %d", a.nome, &a.cod_id);
                enfileirar(&fila, a);
            }
            break;

        case 2:
            printf("Autorizar decolagem?(s/n)\n");
            scanf(" %c", &opcao);
            if (opcao == 's') {
                if (desenfileirar(&fila, &a)) {
                    printf("Avi�o autorizado para decolagem:\n");
                    printf("[Nome]: %s\n[ID]: %d\n", a.nome, a.cod_id);
                    printf("\n\n------Fila atual------:\n\n");
                    exibir(&fila);
                } else {
                    printf("A fila est� vazia, n�o h� avi�es para decolar.\n");
                }
            }
            break;

        case 3:
        printf("\n------Fila atual------:\n\n");
            exibir(&fila);
            break;
        case 4:
            if(!vazia(&fila)){
                printf("Caracterstica do primeiro avi�o:\n\n[Nome]: %s [ID]: %d\n\n", fila.primeiro->nome, fila.primeiro->cod_id);
            }else printf("A fila est� vazia!\n");
            break;
        case 5:
            printf("Quantidade de aiv�es: %d\n", quant_avioes);
            break;
        default:
            break;
        }
     
    } while (caso != 0);
}