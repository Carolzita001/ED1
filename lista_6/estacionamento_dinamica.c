#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM
{
    int cod_id;
    int contador;
    struct ITEM *proximo;
}*tipoFila;

tipoFila criarItem(int id){
    tipoFila novoItem = (tipoFila) malloc(sizeof(struct ITEM));

    if (novoItem == NULL)
    {
        printf("\nErro ao criar item!\n");
        return NULL;
    }else
    {
        novoItem->cod_id = id;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

// Corrigir a função inserir para inicializar o contador
tipoFila inserir(int id, int contador, tipoFila fila) {
    tipoFila novoItem = criarItem(id);
    novoItem->contador = contador; // Inicializa o contador de manobras
    if (fila == NULL) {
        return novoItem;
    } else {
        tipoFila filaAuxiliar = fila;
        while (filaAuxiliar->proximo != NULL) {
            filaAuxiliar = filaAuxiliar->proximo;
        }
        filaAuxiliar->proximo = novoItem;
        return fila;
    }
}

// Corrigir a função exibir para mostrar o contador
void exibir(tipoFila fila) {
    printf("\n===Fila atual===\n");

    if (fila == NULL) {
        printf("\nVazia!\n");
    } else {
        tipoFila filaAuxiliar = fila;

        while (filaAuxiliar != NULL) {
            printf("[ID: %d, Manobras: %d] ", filaAuxiliar->cod_id, filaAuxiliar->contador);
            filaAuxiliar = filaAuxiliar->proximo;
        }
    }
}

tipoFila remover(tipoFila fila){
    if (fila == NULL)
    {
        printf("\nVazia!\n");
    }else
    {
        tipoFila filaAuxiliar;
        filaAuxiliar = fila;
        fila = filaAuxiliar->proximo;
        free(filaAuxiliar);
        filaAuxiliar = NULL;
    }
    return fila;
}

int main(){
    int caso = -1, carro, num;

    tipoFila fila = NULL;

    while (caso != 0) 
    {
        printf("\n0) Sair\n");
        printf("1) Estacionar\n");
        printf("2) Retirar carro\n");
        printf("3) Exibir fila\n");
        scanf("%d", &caso);
        switch (caso) 
        {
            case 1:
                printf("Quantos carros deseja estacionar? ");
                scanf("%d", &num);
                for (int i = 0; i < num; i++) {
                    printf("\nInsira o código identificador do carro:\n");
                    scanf("%d", &carro);
                    fila = inserir(carro, 0, fila);
                }
                break;
            // Corrigir o caso 2 no switch
            case 2:
                exibir(fila);
                printf("\nQual carro deseja desenfileirar?\n");
                scanf("%d", &carro);

                int encontrado = 0;

                // Processa a fila principal
                tipoFila aux = NULL; // Fila auxiliar
                while (fila != NULL) {
                    if (fila->cod_id == carro) {
                        // Carro encontrado, remove da fila
                        fila = remover(fila);
                        printf("\nCarro %d removido do estacionamento!\n", carro);
                        encontrado = 1;
                    } else {
                        // Carro não é o procurado, move para a fila auxiliar
                        tipoFila temp = fila;
                        aux = inserir(temp->cod_id, 0, aux); // Cria um novo nó na fila auxiliar
                        fila = remover(fila);
                    }
                }

                if (!encontrado) {
                    printf("\nCarro não encontrado no estacionamento!\n");
                }

                // Retorna os carros da fila auxiliar para a fila principal
                while (aux != NULL) {
                    tipoFila temp = aux;
                    fila = inserir(temp->cod_id, 1, fila);
                    aux = remover(aux);
                }

                printf("\n------Fila de estacionados------:\n");
                exibir(fila);

                break;

            case 3:
                exibir(fila);
                break;

            default:
                if (caso != 0) {
                    printf("\nOpção inválida!\n");
                }
            break;
        }
    }

    return 0;
}