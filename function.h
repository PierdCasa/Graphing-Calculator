
#include <vector>
#include <string>
#include "rpn.h"


class Function
{
  protected:
    std::vector<std::string> postfix_expression;
    Rpn expr;

  public:
    
    // Function(std::string infix_expression):infix_expression(infix_expression){};
    //lista de intializare a constructorilor
    
    Function()=default;
    Rpn& GetRpn();
    //compunere
    virtual ~Function()=default;

};