#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 3

typedef struct ITEM
{
    int item;
    struct ITEM *proximo;
} *tipoLista;

typedef struct ITEM_ESTATICO
{
    int vetor[TAM];
    int primeiro;
    int ultimo;
} tipoListaEstatica;

tipoLista criarItem(int valor)
{
    tipoLista novoItem = (tipoLista)malloc(sizeof(tipoLista));
    if (novoItem == NULL)
    {
        printf("\nErro!");
        return NULL;
    }
    else
    {
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

void iniciar(tipoListaEstatica *lista)
{
    lista->primeiro = 0;
    lista->ultimo = -1;
}

int cheia(tipoListaEstatica *lista)
{
    return lista->ultimo == TAM - 1;
}

int vazia(tipoListaEstatica *lista)
{
    return lista->primeiro > lista->ultimo;
}

tipoLista inserirEsquerda(int valor, tipoLista lista)
{
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        novoItem->proximo = lista;
        return novoItem;
    }
}

void inserirComeco(tipoListaEstatica *lista, int valor)
{
    if (cheia(lista))
    {
        printf("\nLista cheia!\n");
    }
    /*else if (lista->ultimo > -1)
    {
        printf("\nNao ha espaco no inicio do vetor!\n");
    }*/
    else
    {
        lista->primeiro--;
        lista->vetor[lista->primeiro] = valor;
    }
}

tipoLista inserirDireita(int valor, tipoLista lista)
{
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        tipoLista listaAuxiliar = lista;
        while (listaAuxiliar->proximo != NULL)
        {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoItem;
        novoItem->proximo = NULL;
        return lista;
    }
}

void inserirFim(tipoListaEstatica *lista, int valor)
{
    if (cheia(lista))
    {
        printf("\nLista cheia!\n");
    }
    else
    {
        lista->ultimo++;
        lista->vetor[lista->ultimo] = valor;
    }
}

tipoLista removerEsquerda(tipoLista lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }
    else
    {
        tipoLista listaAuxiliar;
        listaAuxiliar = lista;
        lista = lista->proximo;
        free(listaAuxiliar);
        listaAuxiliar = NULL;
    }
    return lista;
}

void removerComeco(tipoListaEstatica *lista)
{
    if (vazia(lista))
    {
        printf("\nLista vazia!\n");
    }
    else
    {
        lista->primeiro++;
    }
}

tipoLista removerDireita(tipoLista lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        tipoLista listaAuxiliar;
        listaAuxiliar = lista;

        if (lista->proximo == NULL)
        {
            free(lista);
            lista = NULL;
        }
        else
        {
            while (listaAuxiliar->proximo->proximo != NULL)
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

void removerFim(tipoListaEstatica *lista)
{
    if (vazia(lista))
    {
        printf("\nLista vazia!\n");
    }
    else
    {
        lista->ultimo--;
    }
}

void exibir(tipoLista lista)
{
    printf("\n---Lista Dinamica---\n");
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

void exibirEstatica(tipoListaEstatica *lista)
{
    int i = lista->primeiro;
    printf("\n---Lista Estatica---\n");
    if (vazia(lista))
    {
        printf("\nVazia!\n");
    }
    else
    {
        while (i <= lista->ultimo)
        {
            printf("[%d] ", lista->vetor[i]);
            i++;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao = -1;
    int valor = 0;
    tipoLista lista = NULL;
    tipoListaEstatica listaEstatica;
    iniciar(&listaEstatica);

    while (opcao != 0)
    {
        valor = 0;

        exibir(lista);
        exibirEstatica(&listaEstatica);

        printf("\n---Menu---\n");

        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio da lista dinamica\n");
        printf("2: Inserir no final da lista dinamica\n");
        printf("3: Remover no inicio da lista dinamica\n");
        printf("4: Remover no final da lista dinamica\n");
        printf("5: Inserir no inicio da lista estatica\n");
        printf("6: Inserir no final da lista estatica\n");
        printf("7: Remover no inicio da lista estatica\n");
        printf("8: Remover no final da lista estatica\n");

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
            lista = removerEsquerda(lista);
            break;

        case 4:
            lista = removerDireita(lista);
            break;
        case 5:
            printf("Insira ate %d valores\n", TAM);
            printf("Digite um valor\n");
            scanf("%d", &valor);
            inserirComeco(&listaEstatica, valor);
            break;
        case 6:
            printf("Insira ate %d valores\n", TAM);
            printf("Digite um valor\n");
            scanf("%d", &valor);
            inserirFim(&listaEstatica, valor);
            break;
        case 7:
            removerComeco(&listaEstatica);
            break;
        case 8:
            removerFim(&listaEstatica);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}