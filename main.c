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
void validaExpressão(char express[];){
	
}
int main(){
  int opc;
  char exEnt[50];
	do{
		opc = menuMain();
		switch(opc){
			case 1:
			system("clear");
				printf("Opção selecionada: Resolver Expressão.\n");
				printf("Digite a expressão na forma infixa -> \n");
				scanf("%[^\n]*c", exEnt);
				
			break;
			case 2:
				printf("Opção selecionada: Calculadora.\n");
			break;
			default:
				printf("A opção selecionada não existe!!\n");
			break;
		}
	}while (opc!=1 && opc!=2);

	return 0;
}
