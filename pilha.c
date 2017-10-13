#include "pilha.h"
struct dados{
	int num;
	char carac;
};
//typedef struct dados Data
struct node{
	Data dados;
	struct node *prox;
};
/*
 *	Funções com retorno INT:
 *	1 = sucesso
 *	0 = falha
 *	-1 = problema na pilha
 */
Pilha **novaPilha(){
	Pilha **novo;
	novo = (Pilha**)malloc(sizeof(Pilha*)*1);
	if(novo==NULL){ return -1; }
	*novo=NULL;
	return novo;
}
int empilhaTopo(Pilha **stack, Data elem){
	Pilha *newNode;
	if(stack==NULL){ return -1; } //-1 = pilha não existe
	newNode = (Pilha*)malloc(sizeof(Pilha)*1);
	newNode->dados = elem;
	newNode->prox = *stack;
	*stack = newNode;
	return 1;
}
int desempilhaTopo(Pilha **stack, Data *elem){
	Pilha *aux;
	if(stack==NULL){ return -1; }//-1 = pilha não existe
	else if(*stack==NULL){ return 0; }//0 = pilha vazia
	aux = *stack;
	*elem = aux->data;
	*stack = (*stack)->prox;
	free(aux);
	return 1;
}
int imprimePilha(Pilha **stack){
	Pilha **aux;
	Data print
	if(stack==NULL){ return -1; }
	aux = novaPilha();
	while(*stack!=NULL){
		desempilhaTopo(stack, &print);
		if(print.carac == ''){ printf("%d", print.num); }
		else{ printf("%c", print.carac); }
		empilhaTopo(aux, print);
	}
	while(*aux!=null){
		desempilhaTopo(aux, &print);
		empilhaTopo(stack, print);
	}
	free(aux);
	return 1;
}
int pilha_vazia(Pilha **stack){
	if(stack == NULL){ return -1; }
	if(*stack == NULL){ return 1; }
	else{ return 0; }
}
