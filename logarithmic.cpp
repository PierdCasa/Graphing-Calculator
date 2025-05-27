#include "logarithmic.h"
#include <cmath>

Logarithmic::Logarithmic(AppSettings W,std::string InfixExpression):Function(W),InfixExpression(InfixExpression){
    CheckLogarithmicType();
}
//la culori as fi putut sa fac ceva clasa care randomizeaza
//da tocmai ce am stat 3 ore sa ma uit pe unicode-uri sa vad de ce nu mi deseneaza si sa fac debugging cu cout<<ok ok++
//si eu ii dadeam draw fara sa fac plot 

void Logarithmic::CheckLogarithmicType()
{
    if(InfixExpression=="LN")
    {
        Functie=[](float x){return std::log(x);};
        plotFunction(sf::Color (193,249,0),Functie);
    }
    else if(InfixExpression=="LG")
    {
        Functie=[](float x){return std::log10(x);};
        plotFunction(sf::Color (193, 167, 248),Functie);
    }
}
Logarithmic::~Logarithmic(){}