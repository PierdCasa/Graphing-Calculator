#include "rpn.h"
#include <vector>
#include <stack>
#include <cmath>
#include <cctype>
#include <iostream>



bool Rpn::IsOperator(char c)
{
  return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}
//verific daca e op.

bool Rpn::IsOperand(char c)
{ 
  return isdigit(c) || c=='x';
}
// verific daca e nr. sau necunoscuta "x"
// pentru simplitate n̶u̶ d̶i̶n̶ l̶e̶n̶e̶ am ales o singura necunosuta

int Rpn::Precedence(char op)
{
  if(op=='+' || op=='-')
    return 1;
  if(op=='*' || op=='/')
    return 2;
  if(op=='^')
    return 3;
  return 0;
}
//le declar ordinea

//echivalent cu:
//C++ 18
// int precedence(char op) {
//     unordered_map<char, int> prec = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
//     return prec.count(op) ? prec[op] : 0;
// }


/*functia urmatoare transforma stringul expresiei in token-uri.Notatia la care vrem sa ajungem se mai numeste si RPN(Reverse Polish Notation) sau Notatia Poloneza Postfixata.Practic asa functioneaza toate calculatoarele in spate.  Algoritmul care evalueaza expresiile RPN se numeste Shunting Yard Algorithm(javidx9 l-a implementat si el folosind clase, insa doar pe cifre si fara pow(_)) si in mod traditional este implementat cu o stiva, functioneaza pe principiul ordinii operatiilor pe care l-am redefinit mai sus. Pentru ca ar fi avut mai multe clase decat probabil am eu(si nu am multe) voi folosi implementarile din STL pt. structuri.
Codul pt. tokenizare cu un for si multe else if-uri, nu ceva foarte special , ci doar memoreaza caracterele in obiecte struct de tip token. (type,value) si NU le schimba(inca) ordinea din expresia infixata*/
void Rpn::Tokenize(const std::string& infix_expression)
{ 
  bool expect_operand=true;//intial asteptam operanzi
  std::vector<Token> tokens;
  std::string curntToken;
  for(int i=0;i<infix_expression.size();++i)
  { 
    char c=infix_expression[i];
    if(isspace(c))
      continue;
    if(isalpha(c) && c!='x')
    {
      std::cout<<"Wrong input!!!"<<"\n";
      exit(0);
    }
    if(c=='-' && expect_operand)
    {
      curntToken="-";
      ++i;
      //sa mearga si alea negative
      
      //acuma citim pana dam de alt semn

      while(i<infix_expression.size() && (isdigit(infix_expression[i])|| infix_expression[i]=='.' || infix_expression[i]=='x'))
      {
        curntToken+=infix_expression[i];
        ++i;
      }
      --i;
      //merg in spate
    }
    else if(IsOperand(c))
    {
      curntToken.clear();
      while(i<infix_expression.size() && (isdigit(infix_expression[i]) || infix_expression[i]=='.' || infix_expression[i]=='x'))
      {
        curntToken+=infix_expression[i];
        ++i;
      }
      //analog si pentru cand primul numar nu e < 0
      --i;
    }
    else 
    {
      curntToken.clear();
      curntToken+=c;
    }
    
    if(!curntToken.empty())
    {
      if(isdigit(curntToken[0]) || curntToken[0]=='-' || curntToken[0]=='x')
      {
        int poz=curntToken.find('x');
        if(poz!=-1 && curntToken.size()>1)
        {
          std::string leftPart=curntToken.substr(0,poz);
          tokens.push_back({OPERAND, leftPart});
          tokens.push_back({OPERAND,"x"});
          tokens.push_back({OPERATOR,"*"});
        }
        //vedem daca x este in expresie
        else 
        {
          tokens.push_back({OPERAND,curntToken});
        }
        expect_operand=false;
      }
    }
    else if(IsOperator(curntToken[0]))
    {
      tokens.push_back({OPERATOR,curntToken});
      expect_operand=true;
    }
    else if(curntToken=="(")
    {
      tokens.push_back({LEFT_PARANTHESIS,"("});
      expect_operand=true;
    }
    else if(curntToken==")")
    {
      tokens.push_back({RIGHT_PARANTHESIS,")"});
      expect_operand=false;
    }
    else
    {
      std::cout<<"Uknown character "<<curntToken<<"\n";
      exit(0);
      //poate fi actualizat sa nu termine programu eventual
      //oricum se ajunge aici doar daca baga cnv. caractere
      //chinezesti(sau &)
      
    }
    
  }
  if(expect_operand==true)
  {
    std::cout<<"Incomplete expression!"<<"\n";
    exit(0);
  }
  //cu expect_operand verificam daca expresia a fost scrisa complet sau nu si afisam un msj. coresp.
  
  this->tokens=tokens;
  //acuatlizam tokens-urile pentru RPN

}

/*functia urmatoare transforma notatia infixata in cea posfixata. practic avem o stiva si o coada(string-ul numit output aici).
 daca simbolul este un operand il pune in stiva, iar daca acesta este un numar(sau x) il pune in coada.
in momentul in care in coada sunt 2 simboluri verificam ordinea operatiilor de pe stiva(daca simbolul adaugat are o precedenta mai mica decat cel din varful stivei ii dam pop si il punem in coada si punem simbolul nou in stiva,in caz contrar ordinea efectuarii operatiilor nu e incalcata, deci ii dam push operandului in stiva si adaugam numarul in coada). 
parantezele se trateaza astfel in momentul in care dam de "("
ii dam push pe stiva, iar cand cand dam de ")" dam pop tuturor operanzilor de pe stiva si le punem in coada.
pentru ultimul numar acesta va fi pus in coada si el, urmat de ceilalti(sau celalalt daca e doar unul) operanzi.
*/
void Rpn::ToPostfix(const std::vector<Token>&tokens)
{
  std::stack<char>operators;
  std::vector<std::string> output;

  //ma iertati ca nu e c++11 da am strecurat si un i sa fie mai autentic
  for(const auto& token_i:tokens)
  { 
    if(token_i.type==OPERAND)
    {
      output.push_back(token_i.value);
    }
    else if(token_i.type==OPERATOR)
    {
        while(!operators.empty() && Precedence(operators.top())>=Precedence(token_i.value[0]))
        {
          output.push_back(std::string(1,operators.top()));
          operators.pop();
        }
        operators.push(token_i.value[0]);
    }
    else if(token_i.type==LEFT_PARANTHESIS)
    {
      while(!operators.empty() && operators.top()!='(')
      {
        output.push_back(std::string(1,operators.top()));
        operators.pop();
      }
      if(!operators.empty())
      operators.pop();
    }
  }
  
  while(!operators.empty())
  {
    output.push_back(std::string(1,operators.top()));
    operators.pop();
  }

  this->postfix_expression=output;
  //actualizam postfix_exp pentru RPN  
}

void Rpn::print()
{
  for(auto&i:tokens)
      {
        std::cout<<i.value<<" "<<i.type<<"\n";
      }
}
