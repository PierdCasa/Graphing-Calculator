#include "function.h"

class Logarithmic: public Function 
{
    private:
        std::string InfixExpression;
        std::function<float(float)> Functie;
    public:
        Logarithmic(AppSettings W,std::string InfixExpression);
        void CheckLogarithmicType();
        virtual ~Logarithmic();
};