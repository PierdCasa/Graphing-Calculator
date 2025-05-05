
#include <vector>
#include <string>
#include "evaluate.h"


class Function
{
  private:
    std::vector<std::string> postfix_expression;
    Evaluate expr;
    //aici apare doar Evaluate deoarece RPN-ul va fi folosit pentru a 
    //evalua expresiile am ales ca acesta sa inglobat in clasa Evaluate

  public:
    
    // Function(std::string infix_expression):infix_expression(infix_expression){};
    //lista de intializare a constructorilor -- urmeaza...
    
    Function()=default;
    Evaluate& GetEvaluate();
    //compunere
    virtual ~Function()=default;

};