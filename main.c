#include<stdio.h>
int menuMain(){
  int opcao = -1;
  printf("\t\t\t----------------------------\n");
  printf("\t\t\t  SELECIONE O MODO DE USO.\n");
  printf("\t\t\t----------------------------\n");
	printf("\t1- Resolver Expressão.\n\t2- Calculadora.\nSelecione a opção inserindo seu número: \n");
	scanf("%d", &opcao);
  return opcao;
}
int validaExpressão(char express[];){
	//pilha nova
	int cnt;
	for(cnt=0; express[cnt] != '\0'; cnt++;){
		if(express[cnt] == '('){
			//empilha
		}
		else if(express[cnt] == ')'){
			if(pilha_vazia(/*pilha*/)){
				return 1
			}
			else{
				//desempilha
			}
		}
	}
	if(pilha_vazia(/*pilha*/)){ return 0; }
	else { return 1; }
	return 0; //retorna 0 se for válida
	return 1; //retorna 1 se for inválida
}
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
				printf("Digite a expressão na forma infixa -> \n"); 
				scanf("%[^\n]*c", exEnt); 									   	 //lê a expressão digitada, até o \n (enter)
				ret = validaExpressão(exEnt);									 //usa a função validaExpressão e armazena seu retorno em ret
				if(ret){ 														 //se o retorno for diferente de zero, a função é inválida
					printf("A Expressão é inválida!\n\nRetornando ao menu...\n");
					break;
				}
				else{
					prinf("A expressão %s é válida!", exEnt);
					//transforma pra forma posfixa
					printf("A expressão em sua forma posfixa é: %s", exPos);
					//avaliar?? a expressao posfixada
					printf("%s = %f", exPos, res);
				}
			break;
		/**********************Opcao 2: Calculadora********************/
			case 2:
				printf("Opção selecionada: Calculadora.\n");
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
