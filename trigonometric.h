#include "function.h"
//#include <functional> --already in "function.h"

class Trigonometric: public Function 
{
    private:
        std::string InfixExpression;
        std::function<float(float)> Functie;
    
    public:
        Trigonometric(AppSettings W,std::string InfixExpression);
        void CheckTrigonometricType();
        virtual ~Trigonometric();
};