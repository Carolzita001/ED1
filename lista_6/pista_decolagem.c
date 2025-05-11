#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 3
int quant_avioes  = 0;

typedef struct Aviao{
    char nome[50];
    int cod_id;
}Aviao;

typedef struct Fila{
    int primeiro;
    int ultimo;
    struct Aviao itens[TAM];
}Fila;

void iniciar(Fila *fila){
    fila->primeiro = 0;
    fila->ultimo = -1;
}

int vazia(Fila *fila){
    if(fila->primeiro > fila->ultimo){
        return 1;
    }else return 0;
}

int enfileirar(Fila *fila, Aviao a){
    if(fila->ultimo == TAM-1){
        printf("[cheia!]\n");
        return 0;
    }else{
        fila->ultimo ++;
        fila->itens[fila->ultimo] = a;
        quant_avioes ++;
        return 1;
    }
}

void desenfileirar(Fila *fila, Aviao *a){
    if(vazia(fila) == 1){
        printf("[vazia!]\n");
    }else{
        *a = fila->itens[fila->primeiro];
        fila->primeiro ++;
        quant_avioes --;
    }
}

void exibir(Fila *fila){
    if(vazia(fila) == 1){
        printf("[vazia!]\n");
    }else
    {
        for (int i = fila->primeiro; i <= fila->ultimo; i++)
        {
            printf("Nome: %s \nCódigo de identificação: %d\n", fila->itens[i].nome, fila->itens[i].cod_id);
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    Fila fila, aux;
    Aviao a, a_aux;
    
    char opcao = 'n';
    int caso;

    iniciar(&fila);
    iniciar(&aux);

    do
    {
        printf("0) Sair\n");
        printf("1) Adicionar avião a fila de espera\n");
        printf("2) Autorizar decolagem\n");
        printf("3) Listar todos os aviões na fila de espera\n");
        printf("4) Listar caracteristicas do primeiro avião da fila\n");
        printf("5) Listar o número de aviões aguardando na fila de decolagem\n");
        scanf("%d", &caso);
        switch (caso)
        {
        case 1:
            for(int i = 0; i<TAM; i++){
                printf("Insira o nome e o ID do avião %d:\n", i+1);
                scanf("%s %d", a.nome, &a.cod_id);
                enfileirar(&fila, a);
                printf("Adicionando avião a fila de espera!\n");
            }
            break;
        case 2:
            for (int i = 0; i < TAM; i++)
            {
                printf("Autorizar decolagem?(s/n)\n");
                scanf(" %c", &opcao);
                if (opcao == 's')
                {
                    desenfileirar(&fila, &a_aux);
                    printf("\n------Fila atual------:\n");
                    exibir(&fila);
                    break;
                }
            }
            break;
        case 3:
        printf("\n------Fila atual------:\n");
            exibir(&fila);
            break;
        case 4:
            if(!vazia(&fila)){
                printf("Caracterstica do primeiro avião: \n[Nome]: %s\n[ID]: %d\n", fila.itens[fila.primeiro].nome, fila.itens[fila.primeiro].cod_id);
            }else printf("A fila está vazia!\n");
            break;
        case 5:
            printf("Quantidade de aivões: %d\n", quant_avioes);
            break;
        default:
            break;
        }
     
    } while (caso != 0);
}