#include <stdio.h>
#include <stdlib.h>
#define TAM 3 

typedef struct{
int topo;
int dados[TAM];
}Pilha;

void inicializar(Pilha *pilha){
    pilha->topo = -1;
}

int cheia(Pilha *pilha){
    if(pilha->topo == TAM-1){
        return 1;
    }else{
        return 0;
    }
}

int vazia(Pilha *pilha){
    if(pilha->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

void inserir(Pilha *pilha, int valor){
    if(cheia(pilha)==1){
        printf("\nPilha cheia!\n");
    }else{
        pilha->topo++;
        pilha->dados[pilha->topo] = valor;
        printf("\n%d Inserido com sucesso!\n",valor);
    }
}

void remover(Pilha *pilha){

    if(vazia(pilha)==1){
        printf("\nPilha vazia!\n");
    }else{
        printf("\n%d Removido com sucesso!\n",pilha->dados[pilha->topo]);
        pilha->topo--;
    }
}

void exibir(Pilha *pilha){

    int posicao=pilha->topo;
    printf("\n---Pilha atual---\n");
    if(vazia(pilha)==1){
        printf("\nPilha vazia!\n");
    }else{
        while(posicao!=-1){
            printf("\t%d\n",pilha->dados[posicao]);
            posicao--;
        }
    }
}

void exibirTopo(Pilha *pilha){

    if(vazia(pilha)==1){
        printf("\nPilha vazia!\n");
    }else{
        printf("\nO valor do topo eh %d\n",pilha->dados[pilha->topo]);
    }
}

int main()
{
    Pilha pilha;
    int opcao=-1;
    int valor=0;

    inicializar(&pilha);

    while (opcao!=0){
    valor=0;
    exibir(&pilha);

    printf("\nDIGITE 0 PARA SAIR\n");
    printf("1: Inserir\n");
    printf("2: Remover\n");
    printf("3: Visualizar topo\n");
    scanf("%d",&opcao);

    switch(opcao){
    case 1:
    printf("Digite um valor\n");
    scanf("%d",&valor);
    inserir(&pilha, valor);
    break;

    case 2:
    remover(&pilha);
    break;

    case 3:
    exibirTopo(&pilha);
    break;

    case 0:
    printf("\nTchau! Ate a proxima\n");
    break;

    default:
    printf("Opcao invalida!\n");
    break;
    }
    }


    return 0;
}