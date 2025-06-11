#include <stdio.h>
#include<stdlib.h>

typedef struct Lista{
    int item;
    struct Lista *proximo;
}*TipoLista;

//Ciração de item 
TipoLista criarItem (int valor){
    TipoLista criarItem = (TipoLista)malloc(sizeof(TipoLista));
    if (criarItem == NULL){
        printf("Deu ruim a criação do troço ai viu ");
    }else{
        criarItem -> item = valor;
        criarItem -> proximo = NULL;
        return criarItem;
    }  
}

//Iserir no começo
TipoLista inserirComeco (int valor, TipoLista Lista){
    TipoLista novoItem = criarItem(valor);
    if (Lista == NULL){
        return novoItem;
    }else{
        novoItem->proximo = Lista;
        return novoItem;
    } 
}

//Inserir no final 
TipoLista inserirFinal (int valor, TipoLista Lista){
    TipoLista novoItem = criarItem(valor);
    if (Lista == NULL){
        return novoItem;
    }else{
        TipoLista aux = Lista;
        while (aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novoItem;
        novoItem->proximo=NULL;
        return Lista;
        
    } 
}

//Remover no começo
TipoLista removerInicio(TipoLista lista){
    if (lista == NULL){
       printf("Essa listinha aqui ta vazia pai");
    }else{
        TipoLista aux=lista;
        lista = lista->proximo;

        free(aux);
        aux = NULL;

        return lista;
    }
}

//Remover no final
TipoLista removerFinal(TipoLista lista){
    if (lista == NULL){
       printf("Essa listinha aqui ta vazia pai");
    }if (lista->proximo == NULL){
        free(lista);
        lista=NULL;
    }else{
        TipoLista aux = lista;
        while (aux->proximo->proximo != NULL){
            aux = aux->proximo;
        }
        TipoLista descarte;
        descarte = aux -> proximo;

        free(descarte);
        descarte = NULL;
        aux->proximo = NULL;

        return lista;
    }
}

//Exibir a lista 
void exibir(TipoLista lista){

    printf("\n---Lista atual---\n");

    if(lista==NULL){
        printf("\nVazia!\n");
    }else{

    TipoLista listaAuxiliar = lista;

    while(listaAuxiliar != NULL){
        printf("[%d] ",listaAuxiliar->item);
        listaAuxiliar = listaAuxiliar->proximo;
    }

    }

}
//Inserir no meio
TipoLista InserirNoMeio(int valor, TipoLista Lista, int valorReferencia){
    TipoLista novoItem = criarItem(valor);
    if (Lista == NULL){
        return novoItem;
    }else{
        TipoLista noReferencia = Lista;
        while (noReferencia != NULL && noReferencia->item !=valorReferencia){
            noReferencia = noReferencia->proximo;
        }
        novoItem->proximo = noReferencia->proximo;
        noReferencia->proximo = novoItem;

        return Lista;
    } 
}

int main(){

    int opcao=-1;
    int valor=0;
    TipoLista lista = NULL;

    while (opcao!=0)
    {
        valor=0;
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Remover no inicio\n");
        printf("4: Remover no final\n");
        printf("5: Inserir Ordenado\n");

        scanf("%d",&opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista = inserirComeco(valor,lista);
            exibir(lista);
            break;

        case 2:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista = inserirFinal(valor,lista);
            exibir(lista);
            break;

        case 3:
            lista = removerInicio(lista);
            exibir(lista);
            break;

        case 4:
            lista = removerFinal(lista);
            exibir(lista);
            break;

        case 5:
            lista = InserirNoMeio(lista);
            exibir(lista);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}