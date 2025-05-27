#include "rpn.h"

class Evaluate:public Rpn 
{
  private:
    std::string x_value;
    double evaluation_answear;
  public:
    void SetValueOfX(std::string x_value);
    double ApplyOperator(double left,double right,const std::string& op);
    double ApplyFunction(const std::string& func,double val);
    bool IsNumber(const std::string& s);
    void EvaluatePostifx();
    void PrintEvaluationAnswear();

};