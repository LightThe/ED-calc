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
              elem.valor = '(';
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
    stack = novaPilha();
    do{
        system("clear");
        printf("CALCULADORA:");
        if(pilha_vazia(stack)){ printf("Pilha Vazia!\n"); }
        else{ imprimePilha(stack); }
        scanf("%c", &in);
        if(in>=48 && in<=57){
            element.valor = in;
            empilhaTopo(stack, element);
            //NUMERO
        }
        else{
            if(in=='+') { /*soma*/ }
            else if(in=='-') { /*subtrac*/ }
            else if(in=='*') { /*multiply*/ }
            else if(in=='/') { /*divisao*/ }
        }
        
    }while(in!='s' && in!='S');
}