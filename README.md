# RPN Expression Calculator

This program was developed as an essay for Data Structures class at Universidade de Brasília, it converts single digit infix math expression to postfix, showing the expression and the result of its calculation.

## How to use

The idea behind this project is to use a stack data structure to read all of the elements of the input and rearrange them in the correct order for the calculation to take place. The command line interface has two main modes. 

### Expression conversion

Under the name of "Resolução de expressão", this mode takes a math expression with infixed operators (2+2) and returns its Reverse Polish Notation conversion (2 2 +) along with the result.

### Calculator

The calculator (calculadora) mode uses the RPN notation to perform basic arithmetic operations on single digit integers. Numbers are stacked and every operation uses the top two numbers of the stack to compute the result before putting it back on the stack.

## Dependencies and Building

You will need some C compiler (GCC works just fine), compile All the C files into an executable and you're good to go.
