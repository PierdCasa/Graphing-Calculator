#include "function.h"
#include "evaluate.h"

class Mixt: public Function 
{
    private:
        Evaluate m_expr;
        static int m_mixt_count;
    public:
        Mixt(AppSettings w);
        Evaluate& GetEvaluate();
        void PlotFunction(sf::Color);
        void Replot();
        static void PrintMixtCount();
        virtual ~Mixt();
};