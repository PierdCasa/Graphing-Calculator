#include "function.h"
#include "evaluate.h"

class Mixt: public Function 
{
    private:
        Evaluate expr;
    public:
        Mixt(AppSettings W);
        Evaluate& GetEvaluate();
        void plotFunction(sf::Color);
        void Replot();
        virtual ~Mixt();
};