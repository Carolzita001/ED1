#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct ITEM
{
    int item;
    struct ITEM *proximo;
} *tipoLista;

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

tipoLista concatenaLista(tipoLista Prim, tipoLista Sec) {
    if (Prim == NULL) {
        // Se Prim está vazia, retorna Sec
        return Sec;
    }
    tipoLista aux = Prim;
    // Percorre até o último elemento de Prim
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    // Liga o final de Prim ao início de Sec
    aux->proximo = Sec;
    return Prim;
}

void exibir(tipoLista lista)
{
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
    int valor = 0;
    tipoLista Prim = NULL, Sec = NULL, Terc = NULL;

    while (opcao != 0)
    {
        printf("\n---Lista Prim---\n");
        exibir(Prim);
        printf("\n---Lista Sec---\n");
        exibir(Sec);
        printf("\n---Lista Terc---\n");
        exibir(Terc);
        valor = 0;

        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir na Prim\n");
        printf("2: Inserir no Sec\n");
        printf("3: Remover no Prim\n");
        printf("4: Remover no Sec\n");
        printf("5: Concaternar Prim e Terc\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
           printf("Digite um valor\n");
            scanf("%d", &valor);
            Prim = inserirDireita(valor, Prim);
            break;

        case 2:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            Sec = inserirDireita(valor, Sec);
            break;
        case 3:
            Prim = removerEsquerda(Prim);
            break;
        case 4:
            Sec = removerEsquerda(Sec);
            break;

        case 5:
            Terc = concatenaLista(Prim, Sec);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}