#include "function.h"
#include "evaluate.h"

class Algebraic: public Function 
{
    private:
          std::vector<std::string> m_postfix_expression;
          Evaluate m_expr;
          static int m_algebraic_count;
    public:
        Algebraic(AppSettings W);
        Evaluate& GetEvaluate();
        void PlotFunction(sf::Color color);
        void Replot();
        static void PrintAlgebraicCount();
        virtual ~Algebraic();
};