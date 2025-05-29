#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct ITEM{
    int item;
    struct ITEM *proximo;
}*tipoLista;

tipoLista criarItem(int valor){
    tipoLista novoItem = (tipoLista)malloc(sizeof(tipoLista));
    if (novoItem == NULL)
    {
        printf("\nErro!");
        return NULL;
    }else{
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

tipoLista inserirEsquerda(int valor, tipoLista lista){
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }else
    {
        novoItem->proximo = lista;
        return novoItem;
    }
}

tipoLista inserirDireita(int valor, tipoLista lista){
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }else
    {
        tipoLista listaAuxiliar = lista;
        while (listaAuxiliar->proximo!=NULL)
        {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoItem;
        novoItem->proximo = NULL;
        return lista;
    } 
}

tipoLista inserirMeio(int valor, tipoLista lista, noReferencia){
    if (noReferencia==NULL)
    {
        printf("\nNó de referência é nulo!");
        return NULL;
    }

    tipoLista novoItem = criarItem(valor);
    if (novoItem==NULL)
    {
        return NULL;
    }

    listaAuxiliar = lista;

    while (listaAuxiliar != NULL && listaAuxiliar->item != noReferencia) {
        ListaAuxiliar = listaAuxiliar->proximo;
        }
        if (noReferencia == NULL) {
        printf("Nó de referência não encontrado!\n");
        }
    }
    novoItem->proximo = noReferencia->proximo;
    noReferencia->proximo = novoItem;

    return novoItem;
}

tipoLista removerEsquerda(tipoLista lista){
    if (lista==NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }else
    {
        tipoLista listaAuxiliar;
        listaAuxiliar = lista;
        lista = lista->proximo;
        free(listaAuxiliar);
        listaAuxiliar = NULL;
    }
    return lista;
}

tipoLista removerDireita(tipoLista lista){
    if (lista==NULL)
    {
        printf("Lista vazia!\n");
    }else
    {
        tipoLista listaAuxiliar;
        listaAuxiliar = lista;
        
        if (lista->proximo==NULL)
        {
            free(lista);
            lista = NULL;
        }else
        {
            while (listaAuxiliar->proximo->proximo!=NULL)
            {
                listaAuxiliar = listaAuxiliar->proximo;
            }
        }
        tipoLista itemDescartar;
        itemDescartar = listaAuxiliar->proximo;
        free(itemDescartar);
        itemDescartar = NULL;
        listaAuxiliar->proximo = NULL;
    }
    return lista;
}

tipoLista removerMeio(tipoLista lista, tipoLista noReferencia){
    if (lista==NULL || noReferencia==NULL) {
        printf("Lista ou nó de referência inválidos!\n");
        return lista;
    }

    tipoLista itemDescartar = noReferencia->proximo;
    if (itemDescartar==NULL) {
        printf("Nó de referência é o último nó!\n");
        return lista;
    }

    noReferencia->proximo = itemDescartar->proximo;
    free(itemDescartar);
    itemDescartar = NULL;

    return lista;
}

void exibir(tipoLista lista){
    printf("\n---Lista atual---\n");
    if (lista==NULL)
    {
        printf("\nVazia!\n");
    }else
    {
        tipoLista listaAuxiliar = lista;
        while (listaAuxiliar!=NULL)
        {
            printf("[%d] ", listaAuxiliar->item);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao=-1;
    int valor=0, valorReferencia=0;
    tipoLista noReferencia;
    tipoLista lista = NULL;

    while (opcao!=0)
    {
        exibir(lista);
        valor=0;
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Inserir no meio\n");
        printf("4: Remover no inicio\n");
        printf("5: Remover no final\n");
        printf("6: Remover no meio\n");
        /*printf("7: Exibir lista\n");*/

        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista = inserirEsquerda(valor,lista);
            break;

        case 2:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista = inserirDireita(valor,lista);
            break;
        case 3:
            printf("Insira o valor para servir como referência para adicionar o novo valor:\n");
            scanf("%d", &valorReferencia);
            
            printf("Digite um valor\n");
            scanf("%d", &valor);

            inserirMeio(valor, lista, noReferencia);
            break;
        case 4:
            lista = removerEsquerda(lista);
            break;

        case 5:
            lista = removerDireita(lista);
            break;

        case 6:
            printf("Insira o valor para servir como referência para remover o nó:\n");
            scanf("%d", &valorReferencia);
            noReferencia = lista;
            while (noReferencia != NULL && noReferencia->item != valorReferencia) {
                noReferencia = noReferencia->proximo;
            }
            if (noReferencia == NULL) {
                printf("Nó de referência não encontrado!\n");
            } else {
                lista = removerMeio(lista, noReferencia);
            }
            break;
        /*
        case 7:
            exibir(lista);
            break;*/

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}