#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Estrutura do nó da árvore binária
typedef struct No {
    int dado;                  // Valor armazenado no nó
    struct No* esquerda;       // Ponteiro para o filho esquerdo
    struct No* direita;        // Ponteiro para o filho direito
} No;

// Cria um novo nó com o valor fornecido
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Conta o número de nós na árvore recursivamente
int contarNos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

// Verifica se a árvore é completa
bool eCompleta(No* raiz, int indice, int contagemNos) {
    if (raiz == NULL) return true; // Árvore vazia ou subárvore vazia é considerada completa
    if (indice >= contagemNos) return false; /*Se o índice do nó atual for maior ou igual ao 
    número total de nós, não é completa*/

    // Verifica recursivamente se os filhos esquerdo e direito também são completos
    return (eCompleta(raiz->esquerda, 2*indice + 1, contagemNos) && 
            eCompleta(raiz->direita, 2*indice + 2, contagemNos));
}

// Insere um nó mantendo a árvore binária completa (BFS)
No* inserirCompleto(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor); // Se vazia, cria o primeiro nó

    int contagemNos = contarNos(raiz); // Conta nós existentes
    No* temp = raiz;
    No** fila = (No**)malloc(contagemNos * sizeof(No*)); /* Fila que armazena nós para BFS 
    (algoritmo de percurso em árvores que visita todos os nós de um nível antes de passar 
    para o próximo nível) */
    int frente = 0, tras = 0;
    fila[tras++] = temp; // Adiciona raiz na fila

    while (frente < tras) {//enquanto houver nós na fila
        No* atual = fila[frente++]; // Pega próximo nó da fila

        if (atual->esquerda == NULL) {
            atual->esquerda = criarNo(valor); // Insere à esquerda se vazio
            free(fila);
            return raiz;
        } else {
            fila[tras++] = atual->esquerda; // Adiciona filho esquerdo na fila
        }

        if (atual->direita == NULL) {
            atual->direita = criarNo(valor); // Insere à direita se vazio
            free(fila);
            return raiz;
        } else {
            fila[tras++] = atual->direita; // Adiciona filho direito na fila
        }
    }
    free(fila);
    return raiz;
}

// Encontra o último nó e seu pai (usado para deletar o último nó)
void encontrarUltimoNo(No* raiz, No** ultimoNo, No** pai, bool* eEsquerda) {
    if (raiz == NULL) return; // Se a árvore está vazia, não faz nada

    No* temp = raiz;
    No** fila = (No**)malloc(contarNos(raiz) * sizeof(No*)); // Cria uma fila para BFS
    int frente = 0, // indica o índice do próximo elemento a ser removido da fila (o próximo nó a ser processado).
    tras = 0;//indica o índice onde o próximo elemento será inserido na fila (o final da fila).

    fila[tras++] = temp; // Adiciona a raiz na fila

    *ultimoNo = raiz; // Inicializa o último nó como a raiz
    *pai = NULL;      // Inicializa o pai como NULL

    while (frente < tras) { // Percorre a árvore em largura (BFS)
        No* atual = fila[frente++]; // Pega o próximo nó da fila

        if (atual->esquerda != NULL) {
            *pai = atual;                // Atualiza o pai
            *eEsquerda = true;           // Marca que o último nó é filho esquerdo
            *ultimoNo = atual->esquerda; // Atualiza o último nó
            fila[tras++] = atual->esquerda; // Adiciona o filho esquerdo na fila
        }

        if (atual->direita != NULL) {
            *pai = atual;                // Atualiza o pai
            *eEsquerda = false;          // Marca que o último nó é filho direito
            *ultimoNo = atual->direita;  // Atualiza o último nó
            fila[tras++] = atual->direita; // Adiciona o filho direito na fila
        }
    }
    free(fila); // Libera a memória da fila
}

// Deleta o último nó da árvore mantendo a completude
No* deletarUltimo(No* raiz) {
    if (raiz == NULL) return NULL;
    
    No* ultimoNo = NULL;
    No* pai = NULL;
    bool eEsquerda = false;
    encontrarUltimoNo(raiz, &ultimoNo, &pai, &eEsquerda);
    
    if (pai == NULL) {
        // Só existe um nó na árvore
        free(raiz);
        return NULL;
    }
    
    if (eEsquerda) {
        free(pai->esquerda);
        pai->esquerda = NULL;
    } else {
        free(pai->direita);
        pai->direita = NULL;
    }
    
    return raiz;
}

// Busca um valor na árvore usando BFS
bool buscar(No* raiz, int valor) {
    if (raiz == NULL) return false;
    
    No** fila = (No**)malloc(contarNos(raiz) * sizeof(No*));
    int frente = 0, tras = 0;
    fila[tras++] = raiz;
    
    while (frente < tras) {
        No* atual = fila[frente++];
        
        if (atual->dado == valor) {
            free(fila);
            return true;
        }
        
        if (atual->esquerda != NULL) {
            fila[tras++] = atual->esquerda;
        }
        
        if (atual->direita != NULL) {
            fila[tras++] = atual->direita;
        }
    }
    
    free(fila);
    return false;
}

// Percurso pré-ordem: raiz, esquerda, direita
void percursoPreOrdem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->dado);
    percursoPreOrdem(raiz->esquerda);
    percursoPreOrdem(raiz->direita);
}

// Percurso em ordem: esquerda, raiz, direita
void percursoInOrdem(No* raiz) {
    if (raiz == NULL) return;
    percursoInOrdem(raiz->esquerda);
    printf("%d ", raiz->dado);
    percursoInOrdem(raiz->direita);
}

// Percurso pós-ordem: esquerda, direita, raiz
void percursoPosOrdem(No* raiz) {
    if (raiz == NULL) return;
    percursoPosOrdem(raiz->esquerda);
    percursoPosOrdem(raiz->direita);
    printf("%d ", raiz->dado);
}

// Percurso em nível (BFS)
void percursoNivel(No* raiz) {
    if (raiz == NULL) return;
    int n = contarNos(raiz);
    No** fila = (No**)malloc(n * sizeof(No*));
    int frente = 0, tras = 0;
    fila[tras++] = raiz;
    while (frente < tras) {
        No* atual = fila[frente++];
        printf("%d ", atual->dado);
        if (atual->esquerda) fila[tras++] = atual->esquerda;
        if (atual->direita) fila[tras++] = atual->direita;
    }
    free(fila);
}

// Exibe o percurso escolhido pelo usuário
void exibirPercurso(No* raiz, const char* tipoPercurso) {
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        return;
    }

    printf("Percurso escolhido (%s): ", tipoPercurso);

    if (strcmp(tipoPercurso, "pre_ordem") == 0) {
        percursoPreOrdem(raiz);
    } else if (strcmp(tipoPercurso, "in_ordem") == 0) {
        percursoInOrdem(raiz);
    } else if (strcmp(tipoPercurso, "pos_ordem") == 0) {
        percursoPosOrdem(raiz);
    } else if (strcmp(tipoPercurso, "nivel") == 0) {
        percursoNivel(raiz);
    } else {
        printf("Modo de percurso não reconhecido.\n");
    }
    printf("\n");
}

// Libera toda a memória da árvore recursivamente
void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

// Calcula a altura da árvore
int alturaArvore(No* raiz) {//É o maior número de arestas do caminho da raiz até uma folha.
    if (raiz == NULL) return -1; // Árvore vazia tem altura -1
    int altEsq = alturaArvore(raiz->esquerda); // Calcula altura da subárvore esquerda
    int altDir = alturaArvore(raiz->direita);  // Calcula altura da subárvore direita
    return 1 + (altEsq > altDir ? altEsq : altDir); /* Retorna 1 + maior altura dos filhos 
    (Se altEsq for maior que altDir, retorna altEsq. Senão, retorna altDir.)*/
}

// Função principal com menu de operações
int main() {
    No* raiz = NULL;
    int escolha, valor;
    
    printf("Operacoes na Arvore Binaria Completa:\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir noh\n");
        printf("2. Deletar ultimo noh\n");
        printf("3. Buscar um valor\n");
        printf("4. Percurso em nivel\n");
        printf("5. Exibir a aultura da arvore\n");
        printf("6. Verificar se a arvore e completa\n");
        printf("7. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                raiz = inserirCompleto(raiz, valor); // Insere mantendo a completude
                printf("No inserido com sucesso.\n");
                break;
                
            case 2:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    raiz = deletarUltimo(raiz); // Remove o último nó
                    printf("Ultimo no deletado com sucesso.\n");
                }
                break;
                
            case 3:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                if (buscar(raiz, valor)) {
                    printf("Valor %d encontrado na arvore.\n", valor);
                } else {
                    printf("Valor %d nao encontrado na arvore.\n", valor);
                }
                break;
                
            case 4:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    char tipo[20];
                    printf("Escolha o tipo de percurso (pre_ordem, in_ordem, pos_ordem, nivel): ");
                    scanf("%s", tipo);
                    exibirPercurso(raiz, tipo); // Exibe o percurso escolhido
                }
                break;
                
            case 5:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    int altura = alturaArvore(raiz);
                    printf("A altura da arvore eh: %d\n", altura);
                }
                break;
                
            case 6:
                if (eCompleta(raiz, 0, contarNos(raiz))) {
                    printf("A arvore e uma arvore binaria completa.\n");
                } else {
                    printf("A arvore NAO e uma arvore binaria completa.\n");
                }
                break;
                
            case 7:
                liberarArvore(raiz); // Libera toda a memória
                printf("Programa encerrado. Memoria liberada.\n");
                exit(0);
                
            default:
                printf("Escolha invalida. Tente novamente.\n");
        }
    }
    
    return 0;
}
