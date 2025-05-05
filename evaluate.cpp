#include "evaluate.h"
#include <math.h>
#include <stack>
#include <iostream>

double Evaluate::ApplyOperator(double left,double right,char op)
{ 
  //definesc operatiile
  switch(op)
  {
    case '+':return left+right;
    case '-':return left-right;
    case '*':return left*right;
    case '/':return left/right;
    case '^':return pow(left,right);
    default: return 0;
  }
}
bool Evaluate::IsNumber(const std::string& s)
{ 
  //Verific daca e numar
  //daca strigul e gol returneaza eroare
  if(s.empty())
    return false;
  //initial endptr e null
  char* endptr=nullptr;
  //daca conversia a avut loc cu succes endptr va deveni diferit de null
  //altfel va returna 0.0
  if(strtod(s.c_str(),&endptr))
    return true;
  return false;
}
void Evaluate::EvaluatePostifx()
{ 
  //procesul inversat al algoritmului de Transformare RPN
  std::stack<double> operands_aux;
  for(std::string& token_i:postfix_expression)
  { 
    if(token_i=="x")
    {
      operands_aux.push(stod(x_value));
    }
    else if(IsNumber(token_i))
    {
      operands_aux.push(stod(token_i));
    }
    else if(token_i.size()==1 && IsOperator(token_i[0]))
    {
      double right=operands_aux.top();
      operands_aux.pop();
      double left=operands_aux.top();
      operands_aux.pop();

      operands_aux.push(ApplyOperator(left,right,token_i[0]));

    }
  }
  
  evaluation_answear=operands_aux.top();
}

void Evaluate::PrintEvaluationAnswear()
{
  std::cout<<evaluation_answear<<"\n";
}

void Evaluate::SetValueOfX(std::string x_value)
{ 
  //setez valoarea lui x
  if(Evaluate::IsNumber(x_value))
  {
    this->x_value=x_value;
  }
  else
  {
    std::cout<<"Wrong input!!!"<<"\n";
    exit(0);
  }


}