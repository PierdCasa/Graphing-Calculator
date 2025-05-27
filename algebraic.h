#include "function.h"
#include "evaluate.h"

class Algebraic: public Function 
{
    private:
          std::vector<std::string> postfix_expression;
          Evaluate expr;
    public:
        Algebraic()=default;
        //Evaluate& Algebraic::GetEvaluate();
        virtual ~Algebraic();
};