# Graphing-Calculator
OOP Project- Pislariu Mario-Catalin 


The project includes an Object-Oriented Programming (OOP) implementation of an application designed to plot mathematical function graphs. For simplicity, the functions are categorized as: Algebraic, Logarithmic, Trigonometric, and Mixed.

Conventions:

Trigonometric: SIN COS TG CTG ARCSIN ARCCOS ARCTG ARCCTG

--written in uppercase letters, without variables (e.g X) -> plots the graphs of the corresponding basic trigonometric functions.

Logarithmic: LN LG

--written in uppercase letters, without variables (e.g X) -> plots the graphs of the corresponding basic logarithmic functions.

Algebraic: (X^2+3X+1)

--written in uppercase letters (i.e. every occurence of variable "X" is uppercase) -> plots the graphs of the corresponding algebraic functions.

Mixed:

--written in lowercase (i.e. every occurence of variable "X" is lowercase) -> plots the graphs of the corresponding mixed function. 

Failure to follow these conventions will generate errors.( "ERROR" message in the corresponding input box + terminal message for following the convention )

Commands: 

Type 'del' - delete all functions
Type 'enter' - draw function
Press 'NumPad +' - zoom in
Press 'NumPad -' - zoom out

Graph plotting is implemented using SFML 3.O, and input  is taken from keyboard(via SFML).

Algebraic and mixed mathematical functions are stored using RPN (Reverse Polish Notation) and Shunting Yard Algorithm, transforming the input string (INFIX) into a vector od tokens (POSTFIX).
