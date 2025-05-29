#include "function.h"
//#include <functional> --already in "function.h"

class Trigonometric: public Function 
{
    private:
        std::string m_infix_expression;
        std::function<float(float)> m_functie;
        static int m_trigonometric_count;
    
    public:
        Trigonometric(AppSettings w,std::string infix_expression);
        void CheckTrigonometricType();
        void Replot();
        static void PrintTrigonometricCount();
        virtual ~Trigonometric();
};