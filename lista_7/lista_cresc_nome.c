#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct ITEM
{
    char nome[100];
    int matricula;
    struct ITEM *proximo;
} *tipoLista;

tipoLista criarItem(char nome[], int matricula)
{
    tipoLista novoItem = (tipoLista)malloc(sizeof(tipoLista));
    if (novoItem == NULL)
    {
        printf("\nErro!");
        return NULL;
    }
    else
    {
        strcpy(novoItem->nome, nome);
        novoItem->matricula = matricula;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

tipoLista inserirEsquerda(char nome[], int matricula, tipoLista lista)
{
    tipoLista novoItem = criarItem(nome, matricula);
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

tipoLista inserirDireita(char nome[], int matricula, tipoLista lista)
{
    tipoLista novoItem = criarItem(nome, matricula);
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

tipoLista inserirMeio(char nome[], int matricula, tipoLista lista, char nomeReferencia[])
{
    tipoLista novoItem = criarItem(nome, matricula);

    tipoLista noReferencia = lista;

    while (noReferencia != NULL && strcmp(noReferencia->nome, nomeReferencia) != 0)
    {
        noReferencia = noReferencia->proximo;
    }
    if (noReferencia == NULL) {
        // referência não encontrada, inserir no final
        free(novoItem);
        printf("Nome de referência não encontrado!\n");
        return lista;
    }
    novoItem->proximo = noReferencia->proximo;
    noReferencia->proximo = novoItem;

    return lista;
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

tipoLista removerMeio(tipoLista lista, char nomeReferencia[])
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }
    else
    {
        tipoLista noReferencia = lista;

        if (lista->proximo == NULL)
        {
            free(lista);
            lista = NULL;
            return lista;
        }
        else
        {
            while (noReferencia != NULL && strcmp(noReferencia->nome, nomeReferencia) != 0)
            {
                noReferencia = noReferencia->proximo;
            }
            tipoLista itemDescartar = noReferencia->proximo;
            noReferencia->proximo = itemDescartar->proximo;
            free(itemDescartar);
            itemDescartar = NULL;

            return lista;
        }
    }
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
            printf("Nome: %s, Matrícula: %d\n", listaAuxiliar->nome, listaAuxiliar->matricula);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

tipoLista ordenarLista(tipoLista lista)
{
    if (lista == NULL || lista->proximo == NULL)
    {
        return lista; // Lista vazia ou com apenas um elemento
    }

    tipoLista atual, proximo;
    int trocou;

    do
    {
        atual = lista;
        trocou = 0;

        while (atual->proximo != NULL)
        {
            proximo = atual->proximo;

            if (strcmp(atual->nome, proximo->nome) > 0) // Comparação lexicográfica
            {
                // Troca os valores dos nós
                char tempNome[100];
                int tempMatricula;

                strcpy(tempNome, atual->nome);
                tempMatricula = atual->matricula;

                strcpy(atual->nome, proximo->nome);
                atual->matricula = proximo->matricula;

                strcpy(proximo->nome, tempNome);
                proximo->matricula = tempMatricula;

                trocou = 1; // Indica que houve uma troca
            }
            atual = proximo;
        }
    } while (trocou);

    return lista;
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao = -1;
    char nome[100], nomeReferencia[100];
    int matricula = 0;
    tipoLista lista = NULL;

    while (opcao != 0)
    {
        exibir(lista);

        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Inserir no meio\n");
        printf("4: Remover no inicio\n");
        printf("5: Remover no final\n");
        printf("6: Remover no meio\n");
        printf("7: Ordenar lista\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um nome\n");
            scanf("%s", nome);
            printf("Digite a matrícula\n");
            scanf("%d", &matricula);
            lista = inserirDireita(nome, matricula, lista);
            break;

        case 2:
            printf("Digite um nome\n");
            scanf("%s", nome);
            printf("Digite a matrícula\n");
            scanf("%d", &matricula);
            lista = inserirEsquerda(nome, matricula, lista);
            break;
        case 3:
            printf("Insira o nome para servir como referência para adicionar o novo valor:\n");
            scanf("%s", nomeReferencia);

            printf("Digite um nome\n");
            scanf("%s", nome);
            printf("Digite a matrícula\n");
            scanf("%d", &matricula);

            lista = inserirMeio(nome, matricula, lista, nomeReferencia);
            break;
            scanf("%s", nome);
            printf("Digite a matrícula\n");
            scanf("%d", &matricula);

            inserirMeio(nomeReferencia, matricula, lista, nomeReferencia);
            break;
        case 4:
            lista = removerEsquerda(lista);
            break;

        case 5:
            lista = removerDireita(lista);
            break;

        case 6:
            printf("Insira o nome para servir como referência para remover o nó:\n");
            scanf("%s", nomeReferencia);
            lista = removerMeio(lista, nomeReferencia);
            break;
        case 7:
            lista = ordenarLista(lista);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}