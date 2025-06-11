#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
	int item;// armazena o valor do nó
	struct ITEM *proximo;// ponteiro para o próximo nó da fila
}*tipoFila;//tipoFila é um ponteiro para a estrutura fila que facilita a manipulação da fila


tipoFila criarItem(int valor){//aloca dinamicamente a memória para um novo nó

	tipoFila novoItem = (tipoFila) malloc(sizeof(tipoFila));//novoItem é um ponnteiro para o novo nó

	if(novoItem == NULL){
        printf("\nErro ao criar item!\n");//verifica se a memória fi alocada corretamente
        return NULL;
	}else{
        novoItem->item = valor;//inicializa o campo item com o valor fornecido
        novoItem->proximo = NULL;//define próximo como NULL (indicando que o nó é o último da fila)
        return novoItem;//retorna o ponteiro para o novo nó
	}

}

tipoFila inserir(int valor, tipoFila fila){
	   
    tipoFila novoItem = criarItem(valor);//cria um novo nó com o valor fornecido
    if (fila == NULL)
    {
        //novoItem->proximo = fila;
        return novoItem;//se a fila estiver vazia o novo nó se torna o primeiro elemento da fila
    }else{
    
        tipoFila filaAuxiliar = fila;

        while(filaAuxiliar->proximo != NULL){
            filaAuxiliar = filaAuxiliar->proximo;//caso a fila esteja cheia percorre a fila até encontrar o último nó (onde proximo == NULL)
        }

        filaAuxiliar->proximo = novoItem;//adiciona o novo nó ao final da fila e retorna o ponteiro para o início da fila
    
        return fila;
    }

    
}

tipoFila remover(tipoFila fila){
    
    if(fila==NULL){
        printf("\nVazia!\n");
	}else{

        tipoFila filaAuxiliar;
        filaAuxiliar = fila;//armazena o ponteiro para o primeiro nó em filaAuxiliar
        fila = fila->proximo;//atualiza o ponteiro fila para o próximo nó

        free(filaAuxiliar);//fibera a memória do nó removido
        filaAuxiliar = NULL;
	}
    return fila;//retorna o novo ponteiro para o início da fila
}

void exibir(tipoFila fila){

	printf("\n---Fila atual---\n");

	if(fila==NULL){
        printf("\nVazia!\n");
    }else{

        tipoFila filaAuxiliar = fila;

        while(filaAuxiliar != NULL){//percorre a fila e imprime os valores de cada nó
            printf("[%d] ",filaAuxiliar->item);
            filaAuxiliar = filaAuxiliar->proximo;//atualiza o próximo
        }

    }

}

void exibirPrimeiro(tipoFila fila){

	if(fila==NULL){
        printf("\nVazia!\n");
    }else{

    printf("\nO valor do primeiro eh %d\n",fila->item);

    }

}

void pesquisar(int valor, tipoFila fila){

	int contador=0;
    tipoFila filaAuxiliar = fila;
	while(filaAuxiliar != NULL){

		if( filaAuxiliar->item == valor ){
            contador++;
		}
        filaAuxiliar = filaAuxiliar->proximo;
	}
    printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);
}

int main(){

	int opcao=-1;
    int valor=0;
    tipoFila fila = NULL;//inicializa a fila

    while (opcao!=0)
    {
        exibir(fila);
        valor=0;
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir\n");
        printf("2: Remover\n");
        printf("3: Pesquisar\n");
        printf("4: Exibir primeiro\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            fila = inserir(valor,fila);
            break;

        case 2:
           fila = remover(fila);
            break;

        case 3:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pesquisar(valor,fila);
            break;

        case 4:
            exibirPrimeiro(fila);
            break;

        case 0:
            printf("Tchau! Ate a proxima\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
	return 0;
}