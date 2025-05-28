#pragma once
#include "rpn.h"

class Evaluate:public Rpn 
{
  private:
    //float evaluation_answear;
    //optional ca nu o sa il folosesc momentan
  public:
    Evaluate();
    //void SetValueOfX(std::string x_value);
    float ApplyOperator(float left,float right,const std::string& op);
    float ApplyFunction(const std::string& func,float val);
    bool IsNumber(const std::string& s);
    float EvaluatePostifx(float x_value);
    //void PrintEvaluationAnswear(); 
    virtual ~Evaluate();

};