#include "type_check.h"
#include <string>
#include <cmath>

bool TypeCheck::_IsOperator(char c){

    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
    
}

//verific daca e op.

bool TypeCheck::_IsOperand(char c,int type){

    if(type==1)
        return isdigit(c) || c=='X' || c=='.';
    if(type==2)
        return isdigit(c) || c=='x' || c=='.';
    return 0;

}

//de asemnea "." intra si el ca operand pentru a accepta nr cu zec.
// verific daca e nr. sau necunoscuta "x"
// pentru simplitate n̶u̶ d̶i̶n̶ l̶e̶n̶e̶ am ales o singura necunosuta denumita "x"


bool TypeCheck::_IsFunction(const std::string& s,int type){

    if(type==2)
       return s=="sin"|| s=="cos"|| s=="tan"|| s=="ctg"|| s=="arcsin"|| s=="arccos"|| s=="arctg"|| s=="arcctg" || s=="ln" || s=="lg";
    if(type==1)
       return 0;
    return 0;
    //functiile se iau in considerare doar daca inputul este de tipul 2(mixte)(i.e litera mica)
    
}
//verific daca str-ul s este o functie

int TypeCheck::_Precedence(const std::string& op,int type){

    if(op=="+" || op=="-")
        return 1;
    if(op=="*" || op=="/")
        return 2;
    if(op=="^")
        return 3;
    if(_IsFunction(op,type))
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

TypeCheck::TypeCheck()=default;

TypeCheck::~TypeCheck(){}