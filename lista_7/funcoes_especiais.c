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

int numero(tipoLista L){
    int count = 0;
    if (L==NULL)
    {
        printf("Lista vazia!");
    }else
    {
        tipoLista aux = L;
        while (aux!=NULL)
        {
            count++;
            aux = aux->proximo;
        }
    }
    
    return count;
}

tipoLista troca(int k, tipoLista L, int v){
    tipoLista aux = L;
    while (aux->item != k)
    {
        aux = aux->proximo;
    }

    aux->item = v;
    return L;
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

tipoLista inserirMeioEsquerda(int K, tipoLista L, int v){
    tipoLista novoItem = criarItem(v);
    tipoLista noReferencia = L;
    while (noReferencia != NULL && noReferencia->item != K)
    {
        noReferencia = noReferencia->proximo;
    }
    novoItem->anterior = noReferencia->anterior;
    novoItem->proximo = noReferencia;
    noReferencia->anterior->proximo = novoItem;
    noReferencia->anterior = novoItem;

    return L;
    
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

tipoLista banir(tipoLista L, int v){
    if (L == NULL) {
        printf("Vazia!");
        return NULL;
    }
    tipoLista aux = L;
    while (aux != NULL) {
        if (aux->item == v) {
            tipoLista remover = aux;
            // Atualiza o início da lista se necessário
            if (aux->anterior == NULL) {
                L = aux->proximo;
                if (L != NULL)
                    L->anterior = NULL;
            } else {
                aux->anterior->proximo = aux->proximo;
                if (aux->proximo != NULL)
                    aux->proximo->anterior = aux->anterior;
            }
            aux = aux->proximo;
            free(remover);
        } else {
            aux = aux->proximo;
        }
    }
    return L;
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
    int valor = 0, valorReferencia = 0, count = 0, k, v;
    tipoLista L = NULL;

    while (opcao != 0)
    {
        exibir(L);
        valor = 0;

        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Inserir no meio\n");
        printf("4: Remover no inicio\n");
        printf("5: Remover no final\n");
        printf("6: Remover no meio\n");
        printf("7: Elementos da lista L\n");
        printf("8: Trocar elemento\n");
        printf("9: Inserir no meio a esquerda\n");
        printf("10: Banir\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            L = inserirEsquerda(valor, L);
            break;

        case 2:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            L = inserirDireita(valor, L);
            break;
        case 3:
            printf("Insira o valor para servir como referência para adicionar o novo valor:\n");
            scanf("%d", &valorReferencia);

            printf("Digite um valor\n");
            scanf("%d", &valor);

            inserirMeio(valor, L, valorReferencia);
            break;
        case 4:
            L = removerEsquerda(L);
            break;

        case 5:
            L = removerDireita(L);
            break;

        case 6:
            printf("Insira o valor para remover no meio:\n");
            scanf("%d", &valorReferencia);
            L = removerMeio(L, valorReferencia);
            break;
            
        case 7:
            count = numero(L);
            printf("Numero de elementos: %d", count);
            break;
        case 8:
            printf("Insira o valor do elemento que deseja trocar:\n");
            scanf("%d", &k);
            printf("Insira o valor que deseja inserir no lugar\n");
            scanf("%d", &v);
            L = troca(k,L,v);
            break;
        case 9:
            printf("Insira o valor para servir como referência para adicionar o novo valor a esquerda deste:\n");
            scanf("%d", &valorReferencia);

            printf("Digite um novo valor\n");
            scanf("%d", &valor);

            inserirMeioEsquerda(valorReferencia, L, valor);
            break;
        case 10:
            printf("Digite um valor para banir da lista\n");
            scanf("%d", &valor);
            L = banir(L, valor);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}