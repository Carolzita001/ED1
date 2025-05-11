#include <stdio.h>
#include <stdlib.h>
#define TAM 7

typedef struct Carro {
    int cod_iden;
    int contador;
} Carro;

typedef struct {
    int primeiro;
    int ultimo;
    struct Carro itens[TAM];
} Fila;

void iniciar(Fila *fila) {
    fila->primeiro = 0;
    fila->ultimo = -1;
}

int vazia(Fila *fila) {
    if (fila->ultimo < fila->primeiro) {
        printf("\n[Vazia!]\n");
        return 1;
    } else return 0;
}

void enfileirar(Fila *fila, Carro c) {
    if (fila->ultimo == TAM - 1) {
        printf("\nEstacionamento cheio!\n");
    } else {
        fila->ultimo++;
        fila->itens[fila->ultimo] = c;
    }
}

void desenfileirar(Fila *fila, Carro *c) {
    if (!vazia(fila)) {
        *c = fila->itens[fila->primeiro];
        fila->primeiro++;
        printf("\nCarro %d saiu do estacionamento!\n", c->cod_iden);
    }
}

void exibir(Fila *fila) {
    if (!vazia(fila)) {
        for (int i = fila->primeiro; i <= fila->ultimo; i++) {
            printf("\nCarro: %d Manobras: %d\n", fila->itens[i].cod_iden, fila->itens[i].contador);
        }
    }
}

void reiniciarFila(Fila *fila) {
    iniciar(fila);
}

int main() {
    Fila fila, aux;
    Carro c, c_aux;

    iniciar(&fila);
    iniciar(&aux);

    int caso = -1, carro;

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
                if (fila.ultimo < TAM - 1) {
                    printf("Insira o código identificador do carro:\n");
                    scanf("%d", &(c.cod_iden));
                    c.contador = 0; // Inicializa o contador de manobras
                    enfileirar(&fila, c);
                } else {
                    printf("\nEstacionamento cheio!\n");
                }
            break;
            case 2:
                printf("\nQual carro deseja desenfileirar?\n");
                scanf("%d", &carro);

                int encontrado = 0;

                // Processa a fila principal
                while (!vazia(&fila)) {
                    if (fila.itens[fila.primeiro].cod_iden == carro) {
                        // Carro encontrado, remove da fila
                        desenfileirar(&fila, &c_aux);
                        printf("\nCarro %d removido do estacionamento!\n", c_aux.cod_iden);
                        encontrado = 1;
                    } else {
                        // Carro não é o procurado, move para a fila auxiliar
                        desenfileirar(&fila, &c_aux);
                        c_aux.contador++; // Incrementa o número de manobras
                        enfileirar(&aux, c_aux);
                    }
                }

                if (!encontrado) {
                    printf("\nCarro não encontrado no estacionamento!\n");
                }

                // Retorna os carros da fila auxiliar para a fila principal
                while (!vazia(&aux)) {
                    desenfileirar(&aux, &c_aux);
                    enfileirar(&fila, c_aux);
                }

                reiniciarFila(&aux); // Reinicia a fila auxiliar
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