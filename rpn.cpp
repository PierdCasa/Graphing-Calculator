#include "rpn.h"
#include <vector>
#include <stack>
#include <cmath>
#include <cctype>
#include <iostream>



/*functia urmatoare transforma stringul expresiei in token-uri.Notatia la care vrem sa ajungem 
se mai numeste si RPN(Reverse Polish Notation) sau Notatia Poloneza Postfixata.Practic asa 
functioneaza toate calculatoarele in spate.  Algoritmul care evalueaza expresiile RPN se numeste
Shunting Yard Algorithm(javidx9 l-a implementat si el folosind clase, insa doar pe cifre si 
fara pow(_)) si in mod traditional este implementat cu o stiva, functioneaza pe principiul
ordinii operatiilor pe care l-am redefinit mai sus. Pentru ca ar fi avut mai multe clase decat 
probabil am eu(si nu am multe) voi folosi implementarile din STL pt. structuri.
Codul pt. tokenizare cu un for si multe else if-uri, nu ceva foarte special , ci doar memoreaza 
caracterele in obiecte struct de tip token. (type,value) si NU le schimba(inca) ordinea din 
expresia infixata*/
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
    if(isalpha(c))
    {
        curntToken.clear();
        while(i<infix_expression.size() && isalpha(infix_expression[i])){
          curntToken+=infix_expression[i];
          ++i;
        }
        --i;
        //adaug toate literele citite consecutive la curntToken
        //pt a vedea daca curntToken este operator trig. UNAR
        if(check.IsFunction(curntToken)){
          tokens.push_back({FUNCTION,curntToken});//il marchez ca fct.
        }
        else if(curntToken=="x"){
          if(i+1<infix_expression.size() && isdigit(infix_expression[i+1])){
          tokens.push_back(Token(OPERAND,"x"));
          tokens.push_back(Token(OPERATOR,"*"));
          }
          else{
            tokens.push_back(Token(OPERAND,"x"));
          }
          expect_operand=false;
        }
        else{
          std::cout<<"Functie sau variabila necunoscuta: "<<curntToken<<std::endl;
          exit(0);
        }
    }
    else if(isdigit(c) || (c=='-' && expect_operand==true))
    {
        curntToken.clear();
        if(c=='-') curntToken+=c,++i;
        while(i<infix_expression.size() && (isdigit(infix_expression[i]) || infix_expression[i]=='.')) {
          curntToken+=infix_expression[i];
          ++i;
        }

        if(i<infix_expression.size() && infix_expression[i]=='x'){
          tokens.push_back(Token(OPERAND,curntToken));
          tokens.push_back(Token(OPERATOR,"*"));
          tokens.push_back(Token(OPERAND,"x"));
        }
        else {
        tokens.push_back(Token(OPERAND,curntToken));
        --i;
        }
        expect_operand=false;
    }
    else if(c=='x')
    {
      tokens.push_back(Token(OPERAND,"x"));
      if(i+1<infix_expression.size() && isdigit(infix_expression[i+1])){
        tokens.push_back(Token(OPERATOR,"*"));
      }
      expect_operand=false;
    }
    else if(check.IsOperator(c))
    {
        tokens.push_back(Token(OPERATOR,std::string(1,c)));
        expect_operand=true;
    }
    else if(c=='(')
    {
        tokens.push_back(Token(LEFT_PARANTHESIS,"("));
        expect_operand=true;
    }
    else if(c==')')
    {
        tokens.push_back(Token(RIGHT_PARANTHESIS,")"));
        expect_operand=false;
    }
    else 
    {
        std::cout<<"Functie sau variabila necunoscuta:"<<c<<std::endl;
        exit(0);
    }
   
        //poate fi actualizat sa nu termine programu eventual
        //oricum se ajunge aici doar daca baga cnv. caractere
        //chinezesti(sau &)
        
  }
    
  if(expect_operand==true)
  {
    std::cout<<"Inchide paranteza bine ba!!!!!!"<<"\n";
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
void Rpn::ToPostfix()
{
  std::stack<std::string>operators;
  std::vector<std::string> output;

  //ma iertati ca nu e c++11 da am strecurat si un i sa fie mai autentic
  for(const auto& token_i:tokens)
  { 
    if(token_i.type==OPERAND)
    {
      output.push_back(token_i.value);
    }
    else if(token_i.type==FUNCTION)
    {
      operators.push(token_i.value);
    }
    else if(token_i.type==OPERATOR)
    {
        while(!operators.empty() && check.Precedence(operators.top())>=check.Precedence(token_i.value))
        {
          output.push_back(operators.top());
          operators.pop();
        }
        operators.push(token_i.value);
    }
    else if(token_i.type==LEFT_PARANTHESIS)
    {
      operators.push("(");
    }
    else if(token_i.type==RIGHT_PARANTHESIS)
    {
      while(!operators.empty() && operators.top()!="(")
      { 
        output.push_back(operators.top());
        operators.pop();
      }
      if(!operators.empty() && operators.top()=="(")
      {
        operators.pop();
      }
      if(!operators.empty() && check.IsFunction(operators.top()))
      {
        output.push_back(operators.top());
        operators.pop();
      }
    }
  }
  
  while(!operators.empty())
  {
    output.push_back(operators.top());
    operators.pop();
  }

  this->postfix_expression=output;
  //actualizam postfix_exp pentru RPN  
}


void Rpn::print()
{
  for(auto&i:tokens)
      {
        std::cout<<i.type<<" "<<i.value<<"\n";
      }
}

void Rpn::print_postfix()
{
  for(auto&i :postfix_expression)
  {
    std::cout<<i<<" ";
  }
  std::cout<<"\n";
}

