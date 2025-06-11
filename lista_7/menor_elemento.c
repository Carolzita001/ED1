#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct ITEM{
    int item;
    struct ITEM *anterior;
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
        novoItem->anterior = NULL;
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
        lista->anterior = novoItem;
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
        novoItem->anterior = listaAuxiliar;
        novoItem->proximo = NULL;
        return lista;
    } 
}

tipoLista inserirMeio(int valor, tipoLista lista, int valorReferencia)
{
    tipoLista novoItem = criarItem(valor);

    tipoLista noReferencia = lista;

    while (noReferencia != NULL && noReferencia->item != valorReferencia)
    {
        noReferencia = noReferencia->proximo;
    }
    noReferencia->proximo->anterior = novoItem;
    novoItem->anterior = noReferencia;
    novoItem->proximo = noReferencia->proximo;
    noReferencia->proximo = novoItem;

    return lista;
}

tipoLista removerEsquerda(tipoLista lista){
    if (lista==NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }else
    {  
        tipoLista noRemover = lista;
        if (noRemover->proximo == NULL)
        {
            free(noRemover);
            noRemover = NULL;
        }else
        {
            
            lista = lista->proximo;
            lista->anterior = NULL;
        }  
        free(noRemover);
        noRemover = NULL;
    }
    return lista;
}

tipoLista removerDireita(tipoLista lista){
    if (lista==NULL)
    {
        printf("Lista vazia!\n");
    }else
    {   
        if (lista->proximo==NULL)
        {
            free(lista);
            return NULL;
        }else
        {
            tipoLista listaAuxiliar = lista;
            while (listaAuxiliar->proximo->proximo!=NULL)
            {
                listaAuxiliar = listaAuxiliar->proximo;
            }
        
            tipoLista noRemover = listaAuxiliar->proximo;
            noRemover->anterior = NULL;
            listaAuxiliar->proximo = NULL;

            free(noRemover);
            noRemover = NULL;
            }
    }
    return lista;
}

tipoLista removerMeio(tipoLista lista, int valorReferencia)
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }
    else
    {
        if (lista->proximo == NULL)
        {
            free(lista);
            lista = NULL;
            return lista;
        }
        else
        {
            tipoLista noReferencia = lista;
            while (noReferencia->proximo != NULL && noReferencia->item != valorReferencia)
            {
                noReferencia = noReferencia->proximo;
            }
            noReferencia->proximo->anterior = noReferencia->anterior;
            noReferencia->anterior->proximo = noReferencia->proximo;
            free(noReferencia);
            noReferencia = NULL;

            return lista;
        }
    }
}

void MoveMenor(tipoLista* lista) {
    if (*lista == NULL || (*lista)->proximo == NULL) {
        // Lista vazia ou com apenas um elemento, nada a fazer
        return;
    }

    tipoLista menor = *lista;
    tipoLista atual = *lista;

    // Encontrar o menor elemento na lista
    while (atual != NULL) {
        if (atual->item < menor->item) {
            menor = atual;
        }
        atual = atual->proximo;
    }

    // Verificar se o menor já está no início
    if (menor == *lista) {
        return;
    }

    // Desconectar o menor nó de sua posição atual
    if (menor->anterior != NULL) {
        menor->anterior->proximo = menor->proximo;
    }
    if (menor->proximo != NULL) {
        menor->proximo->anterior = menor->anterior;
    }

    // Conectar o menor nó no início da lista
    menor->proximo = *lista;
    menor->anterior = NULL;

    if (*lista != NULL) {
        (*lista)->anterior = menor;
    }

    // Atualizar o ponteiro da lista
    *lista = menor;
}

void exibir(tipoLista lista)
{
    printf("\n---Lista atual---\n");
    if (lista == NULL)
    {
        printf("\nVazia!\n");
    }
    else
    {
        tipoLista listaAuxiliar = lista;
        while (listaAuxiliar != NULL)
        {
            printf("[%d] ", listaAuxiliar->item);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao = -1;
    int valor = 0, valorReferencia = 0;
    tipoLista lista = NULL;

    while (opcao != 0)
    {
        exibir(lista);
        valor = 0;

        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Inserir no meio\n");
        printf("4: Remover no inicio\n");
        printf("5: Remover no final\n");
        printf("6: Remover no meio\n");
        printf("7: Mover o menor item da lista\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            lista = inserirEsquerda(valor, lista);
            break;

        case 2:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            lista = inserirDireita(valor, lista);
            break;
        case 3:
            printf("Insira o valor para servir como referência para adicionar o novo valor:\n");
            scanf("%d", &valorReferencia);

            printf("Digite um valor\n");
            scanf("%d", &valor);

            inserirMeio(valor, lista, valorReferencia);
            break;
        case 4:
            lista = removerEsquerda(lista);
            break;

        case 5:
            lista = removerDireita(lista);
            break;

        case 6:
            printf("Insira o valor para remover no meio:\n");
            scanf("%d", &valorReferencia);
            lista = removerMeio(lista, valorReferencia);
            break;
        case 7:
            MoveMenor(&lista);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}