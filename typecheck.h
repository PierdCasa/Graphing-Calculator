#include <string>

class TypeCheck
{
    private:
        bool IsOperator(char c);
        bool IsOperand(char c);
        bool IsFunction(const std::string& s);
        bool IsNumber(const std::string& s);
        int Precedence(const std::string& op);
        //am considerat aceste  metode private deoarce au sens sa fie accesate doar de catre Rpn/Evaluate
        // acest lucru se va face printr-o instansta a unui ob. de tip TypeCheck share-uita(prin mostenire)
    public:

        TypeCheck();
        ~TypeCheck();
        friend class Rpn;
        friend class Evaluate;
        //am declarat si clasa Evaluate ca "prieten" deoarece , chiar daca aceasta mosteneste din Rpn 
        //TypeCheck nu o considera friend => methods are inaccessible
        
};