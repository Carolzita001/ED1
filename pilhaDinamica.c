#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
	int item;
	struct ITEM *proximo;
}*Pilha;


Pilha criarItem(int valor){

	Pilha novoItem = (Pilha) malloc(sizeof(Pilha));

	if(novoItem == NULL){
        printf("\nErro ao criar item!\n");
        return NULL;
	}else{
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
	}

}

Pilha inserir(int valor, Pilha pilha){
	Pilha novoItem = criarItem(valor);
    novoItem->proximo = pilha;
	return novoItem;
}

Pilha remover(Pilha pilha){
    if(pilha==NULL){
        printf("\nVazia!\n");
        return pilha;
	}else{
	Pilha pilhaAuxiliar = pilha->proximo;
	free(pilha);
	pilha = NULL;
	return pilhaAuxiliar;
	}

}

void exibir(Pilha pilha){

	printf("\n---Pilha atual---\n");

	if(pilha==NULL){
        printf("Vazia!\n");
	}else{

	while(pilha!=NULL){
		printf("\t %d\n",pilha->item);
		pilha = pilha->proximo;
	}

}


}
//não é obrigatória
void exibirTopo(Pilha pilha){

	if(pilha==NULL){
        printf("\nVazia!\n");
	}else{
        printf("\nO valor do topo eh %d\n",pilha->item);
}

}
// não precisa fazer, a professora fez por que tinha que imprimir...
void pesquisar(int valor, Pilha pilha){

	int contador=0;

	while(pilha != NULL){

		if( pilha->item == valor ){
            contador++;
		}
    pilha = pilha->proximo;
	}
        printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);
}

int main(){

	int opcao=-1;
    int valor=0;
    Pilha pilha = NULL;

    while (opcao!=0)
    {
        exibir(pilha);
        valor=0;
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir\n");
        printf("2: Remover\n");
        printf("3: Exibir topo\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pilha = inserir(valor,pilha);
            break;

        case 2:
           pilha = remover(pilha);
            break;

        case 3:
            exibirTopo(pilha);
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