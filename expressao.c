#include"pilha.h"
#include<string.h>
int menuMain(){
    int opcao = -1;
    printf("\t\t\t----------------------------\n");
    printf("\t\t\t  SELECIONE O MODO DE USO.\n");
    printf("\t\t\t----------------------------\n");
      printf("\t1- Resolver Expressão.\n\t2- Calculadora.\nSelecione a opção inserindo seu número: \n");
      scanf("%d", &opcao);
    return opcao;
  }
  int validaExpressão(char Expr[]){
      //pilha nova
      Pilha **stack;
      Data elem;
      int cnt;
      for(cnt=0; Expr[cnt] != '\0'; cnt++){
          if(Expr[cnt] == '('){
              //sprintf(elem.valor, "(");
              empilhaTopo(stack, elem);
          }
          else if(Expr[cnt] == ')'){
              if(pilha_vazia(stack)){
                  return 1;
              }
              else{
                  desempilhaTopo(stack, &elem);
              }
          }
      }
      if(pilha_vazia(stack)){ return 0; }
      else { return 1; }
      return 0; //retorna 0 se for válida
      return 1; //retorna 1 se for inválida
  }
  void posfixaExpressao(char Expr[]){
  
  }
void calc(){
    char in;
    Pilha **stack;
    Data element;
    int n1, n2, res;
    stack = novaPilha();
    do{
        //system("clear");
        printf("CALCULADORA:\n");
        if(pilha_vazia(stack)){ printf("Pilha Vazia!\n"); }
        else{ imprimePilha(stack); }
        scanf("%c", &in);
        if(in>=48 && in<=57){
            element.num = atoi(&in);
            empilhaTopo(stack, element);
            //NUMERO
        }
        else{
            if(in=='+') {
                desempilhaTopo(stack, &element);
                n1 = element.num;
                if(pilha_vazia(stack)){
                    printf("Não há operandos suficientes para realizar a operação.\n");
                    empilhaTopo(stack, element);
                }
                else{
                    desempilhaTopo(stack, &element);
                    n2 = element.num;
                    res=n2+n1;
                    element.num = res;
                    empilhaTopo(stack, element);
                }
            }
            else if(in=='-') { /*subtrac*/ 
                desempilhaTopo(stack, &element);
                n1 = element.num;
                if(pilha_vazia(stack)){
                    printf("Não há operandos suficientes para realizar a operação.\n");
                    empilhaTopo(stack, element);
                }
                else{
                    desempilhaTopo(stack, &element);
                    n2 = element.num;
                    res=n2-n1;
                    element.num = res;
                    empilhaTopo(stack, element);
                }
            }
            else if(in=='*') { /*multiply*/ 
                desempilhaTopo(stack, &element);
                n1 = element.num;
                if(pilha_vazia(stack)){
                    printf("Não há operandos suficientes para realizar a operação.\n");
                    empilhaTopo(stack, element);
                }
                else{
                    desempilhaTopo(stack, &element);
                    n2 = element.num;
                    res=n2*n1;
                    element.num = res;
                    empilhaTopo(stack, element);
                }
            }
            else if(in=='/') { /*divisao*/
                desempilhaTopo(stack, &element);
                n1 = element.num;
                if(pilha_vazia(stack)){
                    printf("Não há operandos suficientes para realizar a operação.\n");
                    empilhaTopo(stack, element);
                }
                else{
                    desempilhaTopo(stack, &element);
                    n2 = element.num;
                    res=(int)n2/(int)n1;
                    element.num = res;
                    empilhaTopo(stack, element);
                }
            }
        }
        
    }while(in!='s' && in!='S');
    liberaPilha(stack);
}