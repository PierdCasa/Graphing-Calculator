#include "typecheck.h"
#include <string>
#include <cmath>

bool TypeCheck::IsOperator(char c){

    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
    
}

//verific daca e op.

bool TypeCheck::IsOperand(char c){

    return isdigit(c) || c=='x' || c=='.';

}

//de asemnea "." intra si el ca operand pentru a accepta nr cu zec.
// verific daca e nr. sau necunoscuta "x"
// pentru simplitate n̶u̶ d̶i̶n̶ l̶e̶n̶e̶ am ales o singura necunosuta denumita "x"


bool TypeCheck::IsFunction(const std::string& s){

    if(s=="sin"|| s=="cos"|| s=="tan"|| s=="ctg"|| s=="arcsin"|| s=="arccos"|| s=="arctg"|| s=="arcctg")
        return 1;
    return 0;
}
//verific daca str-ul s este o functie

int TypeCheck::Precedence(const std::string& op){

    if(op=="+" || op=="-")
        return 1;
    if(op=="*" || op=="/")
        return 2;
    if(op=="^")
        return 3;
    if(IsFunction(op))
        return 4;
  return 0;

  //le declar ordinea

//echivalent cu:
//C++ 18
// int precedence(char op) {
//     unordered_map<char, int> prec = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
//     return prec.count(op) ? prec[op] : 0;
// }

}

TypeCheck::TypeCheck(){}

TypeCheck::~TypeCheck(){}