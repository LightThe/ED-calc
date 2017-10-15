/*
 *	TODO: Comentar funções da calculadora
 *	TODO: Implementar tad da pilha
 *	TODO: comentar funcionamento de menus, validação e execução de expressões
*/
#include "pilha.h"
#include "expressao.h"
int main(){
  int opc, cnt, ret; 					//opc = opção, cnt = contagem , ret = retorno
  float res;							//res = resultado
  char exEnt[50] = "", exPos[50] = "";	//exEnt = Entrada do usuario, exPos = convertida posfixada
	do{
		opc = menuMain(); //recebe a opção selecionada do menu;
		switch(opc){
		/**********************Opcao 1: Resolver Expressão********************/
			case 1:
				system("clear"); 												 //limpa os menus anteriores da tela
				printf("\t\tOpção selecionada: Resolver Expressão.\n");
				printf("Digite a expressão na forma infixa -> "); 
				scanf("%[^\n]s", exEnt); 									   	 //lê a expressão digitada, até o \n (enter)
				ret = validaExpressão(exEnt);									 //usa a função validaExpressão e armazena seu retorno em ret
				if(ret){ 														 //se o retorno for diferente de zero, a função é inválida
					printf("A Expressão é inválida!\n\nRetornando ao menu...\n");
					break;
				}
				else{
					printf("A expressão %s é válida!\n", exEnt);
					//transforma pra forma posfixa
					printf("A expressão em sua forma posfixa é -> %s\n", exPos);
					//avaliar?? a expressao posfixada
					printf("O resultado dessa expressão é -> %f\nPessoine qualquer tecla para continuar.\n", res);
					getchar();
				}
			break;
		/**********************Opcao 2: Calculadora********************/
			case 2:
				system("clear"); 												 //limpa os menus anteriores da tela
				printf("Opção selecionada: Calculadora.\n");
				printf("Para usar a calculadora, digite os valores, depois digite a operação\nque deseja realizar com os dois ultimos valores inseridos.\nDigite S a qualquer momento para Sair.\n\n");
				printf("Pressione alguma tecla para iniciar...");
				getchar();
				calc();
			break;
		/**************ERRO****************/
			default:
				printf("A opção selecionada não existe!!\n");
			break;
		}
		system("clear"); 					//limpa a tela antes de refazer o menu ou finalizar o programa;
	}while (opc!=1 && opc!=2); 				//enquanto a opção selecionada for incorreta, repete o menu;

	return 0;
}
