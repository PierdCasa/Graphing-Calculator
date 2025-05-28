#include "function.h"
#include "evaluate.h"

class Algebraic: public Function 
{
    private:
          std::vector<std::string> postfix_expression;
          Evaluate expr;
    public:
        Algebraic(AppSettings W);
        Evaluate& GetEvaluate();
        void plotFunction(sf::Color color);
        void Replot();
        virtual ~Algebraic();
};