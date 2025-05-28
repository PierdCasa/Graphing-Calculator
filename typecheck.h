#pragma once
#include <string>

class TypeCheck
{
    private:
        bool IsOperator(char c);
        bool IsOperand(char c,int type);
        bool IsFunction(const std::string& s,int type);
        int Precedence(const std::string& op,int type);//sa tina cont si de tip
        
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