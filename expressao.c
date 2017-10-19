#include"pilha.h"
#include<string.h>
int menuMain(){
    int opcao = -1;
    printf("\t\t----------------------------\n");
    printf("\t\t  SELECIONE O MODO DE USO.\n");
    printf("\t\t----------------------------\n");
    printf("\t1- Resolver Expressão.\n\t2- Calculadora.\n\t3- SAIR\n\nSelecione a opção inserindo seu número: \n");
    scanf("%d", &opcao);
    return opcao;
}
int validaExpressao(char Expr[]){
    Pilha **stack;          //pilha nova
    stack = novaPilha();    //inicia a pilha vazia
    Data elem;              //elemento para ajudar a empilhar e desempilhar
    int cnt;                //contador
    if(strcmp(Expr, "") == 0){ return 1; }
    for(cnt=0; Expr[cnt] != '\0'; cnt++){   //enquanto nao chegar no final da expressao
        if(Expr[cnt] == '('){               //se encontrar abertura de escopo
            elem.carac = '(';               //define o caractere a ser empilhado
            empilhaTopo(stack, elem);       //empilha a abertura de escopo na pilha
        }
        else if(Expr[cnt] == ')'){          //se encontrar fechamento de escopo
            if(pilha_vazia(stack)){         //verifica se a pilha é vazia
                return 1;                   //caso a pilha seja vazia, a expressão é inválida
            }
            else{                           //senão
                desempilhaTopo(stack, &elem);//desempilha uma abertura de escopo
            }
        }
    }
    if(pilha_vazia(stack) == 1){ return 0; }    //se ao final a pilha estiver vazia, a expressão é valida
    else { return 1; }                          //se a pilha não estiver vazia, faltou algum fechamento de escopo
}
void posfixaExpressao(char Expr[], char out[]){
    Pilha **stack;
    stack = novaPilha();
    Data element;
    int i;
    element.num = 0;
    char saida[50] = "";
    for(i=0; Expr[i]!='\0'; i++){
        if(Expr[i] >= 48 && Expr[i] <= 57){
            //número
            sprintf(saida, "%s %c", saida, Expr[i]);
        }
        else if(Expr[i] == '('){
            //parentese de abertura
            element.carac = '(';
            empilhaTopo(stack, element);
        }
        else if(Expr[i] == ')'){
            //parentese de fechamento
            do{
                desempilhaTopo(stack, &element);
                if(element.carac != '('){
                    sprintf(saida, "%s %c", saida, element.carac);
                }
            }while(element.carac != '(');

        }
        #pragma region *OPERADORES*                         //diretiva de preprocessamento usada para minimizar essa região de código dentro do esditor de texto
        //um elemento com prioridade 2 tem menos prioridade que um com o mesmo valor em 1
        else if(Expr[i] == '+'){
            //prioridade = 2
            if(pilha_vazia(stack)==0){                      //verifica se a pilha não é vazia
                do{
                    desempilhaTopo(stack, &element);                    //se não for, desempilha  e verifica se a prioridade é igual ou maior
                    if(element.carac == '+'||element.carac == '-'||element.carac == '*'||element.carac == '/'){
                        sprintf(saida, "%s %c", saida, element.carac);  //caso a prioridade seja maior, copia o caractere desempilhado
                    }
                    else{
                        empilhaTopo(stack, element);                    //se a prioridade nao for >=, retorna o caractere para a pilha
                    }
                }while(element.carac == '+'||element.carac == '-'||element.carac == '*'||element.carac == '/');  //repete enquanto houver caracteres de prioridade >=
            }
            element.carac = '+';                //adiciona o caractere analisado
            empilhaTopo(stack, element);        //empilha o caractere analisado
        }
        else if(Expr[i] == '-'){
            //prioridade = 2
            if(pilha_vazia(stack)==0){                      //verifica se a pilha não é vazia
                do{
                    desempilhaTopo(stack, &element);                    //se não for, desempilha  e verifica se a prioridade é igual ou maior
                    if(element.carac == '-'||element.carac == '+'||element.carac == '*'||element.carac == '/'){
                        sprintf(saida, "%s %c", saida, element.carac);  //caso a prioridade seja maior, copia o caractere desempilhado
                    }
                    else{
                        empilhaTopo(stack, element);                    //se a prioridade nao for >=, retorna o caractere para a pilha
                    }
                    if(pilha_vazia(stack)==0){
                        desempilhaTopo(stack, &element);
                        empilhaTopo(stack, element);
                    }
                }while(element.carac == '-'||element.carac == '+'||element.carac == '*'||element.carac == '/');  //repete enquanto houver caracteres de prioridade >=
            }
            element.carac = '-';                //adiciona o caractere analisado
            empilhaTopo(stack, element);        //empilha o caractere analisado
        }
        else if(Expr[i] == '*'){
            //prioridade = 1
            if(pilha_vazia(stack)==0){                      //verifica se a pilha não é vazia
                do{
                    desempilhaTopo(stack, &element);                    //se não for, desempilha  e verifica se a prioridade é igual ou maior
                    if(element.carac == '*'||element.carac == '/'){
                        sprintf(saida, "%s %c", saida, element.carac);  //caso a prioridade seja maior, copia o caractere desempilhado
                    }
                    else{
                        empilhaTopo(stack, element);                    //se a prioridade nao for >=, retorna o caractere para a pilha
                    }
                }while(element.carac == '*'||element.carac == '/');  //repete enquanto houver caracteres de prioridade >=
            }
            element.carac = '*';                //adiciona o caractere analisado
            empilhaTopo(stack, element);        //empilha o caractere analisado
        }
        else if(Expr[i] == '/'){
            //prioridade = 1
            if(pilha_vazia(stack)==0){                      //verifica se a pilha não é vazia
                do{
                    desempilhaTopo(stack, &element);                    //se não for, desempilha  e verifica se a prioridade é igual ou maior
                    if(element.carac == '*'||element.carac == '/'){
                        sprintf(saida, "%s %c", saida, element.carac);  //caso a prioridade seja maior, copia o caractere desempilhado
                    }
                    else{
                        empilhaTopo(stack, element);                    //se a prioridade nao for >=, retorna o caractere para a pilha
                    }
                }while(element.carac == '*'||element.carac == '/');  //repete enquanto houver caracteres de prioridade >=
            }
            element.carac = '/';                //adiciona o caractere analisado
            empilhaTopo(stack, element);        //empilha o caractere analisado
        }
        #pragma endregion
    }
    while(pilha_vazia(stack) == 0){
        desempilhaTopo(stack, &element);
        sprintf(saida, "%s %c", saida, element.carac);
    }
    strcpy(out, saida);
}
int calcPos(char Expr[]){
    int i, n1, n2, res;
    Data element;
    Pilha **stack;
    stack = novaPilha();
    for(i=0; Expr[i]!='\0'; i++){

        if(Expr[i]>=48 && Expr[i]<=57){
            element.num = atoi(&Expr[i]);
            empilhaTopo(stack, element);
        }
        else{
            if(Expr[i]=='+') {
                if(pilha_vazia(stack) == 0){
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
            }
            else if(Expr[i]=='-') {
                if(pilha_vazia(stack)==0){
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
            }
            else if(Expr[i]=='*') {
                if(pilha_vazia(stack)==0){
                    desempilhaTopo(stack, &element);
                    n1 = element.num;
                    if(pilha_vazia(stack)){
                        printf("\n\tNão há operandos suficientes para realizar a operação.\n");
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
            }
            else if(Expr[i]=='/') {
                if(pilha_vazia(stack)==0){
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
        }
    }
    desempilhaTopo(stack, &element);
    res = element.num;
    return res;
}
void calc(){
    char in;                //recebe uma entrada
    Pilha **stack;          //pilha nova
    Data element;           //elemento para ajudar a empilhar/desempilhar
    int n1, n2, res;        //n1, n2 e res. Usados para armazenar os dois numeros e o resultado da operaçao
    stack = novaPilha();    //cria a pilha vazia
    do{                                 //repete as instruções a partir DESTE PONTO
        printf("\n\n\n\nCALCULADORA:\n");
        if(pilha_vazia(stack)){ printf("Pilha Vazia!\n"); }     //assim que iniciar, exibir a pilha
        else{ imprimePilha(stack); }                            //a cada repetição, imprime o conteúdo da pilha na tela
        printf("\n");
        scanf("%c", &in);                                       //recebe o numero/símbolo inserido pelo usuário
        if(in>=48 && in<=57){                                   //se o valor digitado for equivalente a um numero
            element.num = atoi(&in);                            //usa atoi para converter o número para inteiro, e empilha
            empilhaTopo(stack, element);                        //empilha o numero no topo
        }
        else{
                                                        //as operações funcionam de forma parecida
            if(in=='+') {                               //ao detectar um operador na entrada
                if(pilha_vazia(stack) == 0){            //verifica se a pilha não é vazia
                    desempilhaTopo(stack, &element);    //desempilha o primeiro operando
                    n1 = element.num;                   //armazena seu valor em n1
                    if(pilha_vazia(stack)){             //se não existirem mais operandos na pilha...
                        printf("Não há operandos suficientes para realizar a operação.\n");
                        empilhaTopo(stack, element);    //empilha o operando anterior e não executa a operação
                    }
                    else{                               //se existir a quantidade necessária de operandos
                        desempilhaTopo(stack, &element);//desempilha o próximo operando
                        n2 = element.num;               //armazena seu valor em n2
                        res=n2+n1;                      //executa a operação
                        element.num = res;              //armazena o resultado no formato de dados da pilha
                        empilhaTopo(stack, element);    //para depois empilhar o valor obtido novamente
                    }
                }
            }
            else if(in=='-') { /*subtracao*/
                if(pilha_vazia(stack)==0){
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
            }
            else if(in=='*') { /*multiplicacao*/
                if(pilha_vazia(stack)==0){
                    desempilhaTopo(stack, &element);
                    n1 = element.num;
                    if(pilha_vazia(stack)){
                        printf("\n\tNão há operandos suficientes para realizar a operação.\n");
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
            }
            else if(in=='/') { /*divisao*/
                if(pilha_vazia(stack)==0){
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
        }

    }while(in!='s' && in!='S'); //repete enquanto o usuário não digitar 'S' ou 's' (para sair)
    liberaPilha(stack); //assim que sair da calculadora, libera a pilha utilizada
}
