#include "evaluate.h"
#include <math.h>
#include <stack>
#include <iostream>

Evaluate::Evaluate()
{

}
float Evaluate::ApplyOperator(float left,float right,const std::string& op)
{ 
  //definesc operatiile
    if(op=="+") return left+right;
    if(op=="-") return left-right;
    if(op=="*") return left*right;
    if(op=="/") return left/right;
    if(op=="^") return pow(left,right);
    
    return 0;
}
float Evaluate::ApplyFunction(const std::string& func,float val)
{   
    //definesc functiile
    if(Type==2) //ca doar acolo avem d astea 
    {
    if(func=="sin") return sin(val);
    if(func=="cos") return cos(val);
    if(func=="tan") return tan(val);
    if(func=="ctg") return 1.0/tan(val);
    if(func=="arcsin") return asin(val);
    if(func=="arccos") return acos(val);
    if(func=="arctg") return atan(val);
    if(func=="arcctg") return static_cast<float>(M_PI_2) - std::atan(val);
    if(func=="ln") return log(val);
    if(func=="lg") return log10(val);
    }

    return 0;
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

float Evaluate::EvaluatePostifx(float x_value)
{ 
  //procesul inversat al algoritmului de Transformare RPN
  std::stack<float> operands_aux;
  for(std::string& token_i:postfix_expression)
  { 
    if(token_i==X)
    {
      operands_aux.push(x_value);
    }
    else if(IsNumber(token_i))
    {
      operands_aux.push(stod(token_i));
    }
    else if(Rpn::check.IsFunction(token_i,Type))
    {
      double val=operands_aux.top();
      operands_aux.pop();
      operands_aux.push(ApplyFunction(token_i,val));
    }
    else if(token_i.size()==1 && check.IsOperator(token_i[0]))
    {
      double right=operands_aux.top();
      operands_aux.pop();
      double left=operands_aux.top();
      operands_aux.pop();
      operands_aux.push(ApplyOperator(left,right,token_i));
    }
  }
  
  //evaluation_answear=operands_aux.top();
  return operands_aux.top();
}


// void Evaluate::PrintEvaluationAnswear()
// {
//   std::cout<<evaluation_answear<<"\n";
// }

// void Evaluate::SetValueOfX(std::string x_value)
// { 
//   //setez valoarea lui x
//   if(Evaluate::IsNumber(x_value) || x_value=="0")
//   {
//     this->x_value=x_value;
//   }
//   else
//   {
//     std::cout<<"Wrong input!!!"<<"\n";
//     exit(0);
//   }

// }

Evaluate::~Evaluate()
{

}
