#include "function.h"

class Logarithmic: public Function 
{
    private:
        std::string m_infix_expression;
        std::function<float(float)> m_functie;
        static int m_logarithmic_count;
    public:
        Logarithmic(AppSettings w,std::string infix_expression);
        void CheckLogarithmicType();
        void Replot();
        static void PrintLogarithmicCount();
        virtual ~Logarithmic();
};