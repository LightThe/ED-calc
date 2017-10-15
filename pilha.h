#include<stdio.h>
#include<stdlib.h>
struct dados{
    int num;
	char carac;
};
typedef struct dados Data;
typedef struct node Pilha;
//cria e inicializa uma nova pilha
Pilha **novaPilha();
//empilha um item no topo
int empilhaTopo(Pilha **stack, Data elem);
//desempilha um item do topo
int desempilhaTopo(Pilha **stack, Data *elem);
//imprime todo o conteúdo da pilha
int imprimePilha(Pilha **stack);
//verifica se a pilha é vazia
int pilha_vazia(Pilha **stack);
//libera toda a pilha
int liberaPilha(Pilha **stack);