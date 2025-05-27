#include "trigonometric.h"
#include <cmath>
Trigonometric::Trigonometric(AppSettings W,std::string InfixExpression):Function(W),InfixExpression(InfixExpression){
    CheckTrigonometricType();
}

void Trigonometric::CheckTrigonometricType()
{
    if(InfixExpression=="SIN")
    {
        Functie=[](float x){return std::sin(x);};
        plotFunction(sf::Color (159, 255, 255),Functie);
        //din C++ 11 s-a introdus functional care permite memorarea functiilor de toate tipurile in variabile
    }
    else if(InfixExpression=="COS")
    {
        Functie=[](float x){return std::cos(x);};
        plotFunction(sf::Color (217, 247, 1),Functie);
    }
    else if(InfixExpression=="TG")
    {
        Functie=[](float x){return std::tan(x);};
        //aici as fi putut face o aproximatie mai buna
        //mai exact cu std::sin(x)/std::cos(x)
        //but it's ok asa

        plotFunction(sf::Color::Magenta,Functie);
    }
    else if(InfixExpression=="CTG")
    {
        Functie=[](float x){return 1.0f/std::tan(x);};
        plotFunction(sf::Color::Yellow,Functie);
        //inversul cotangentei
    }
    else if(InfixExpression=="ARCSIN")
    {
        Functie=[](float x){return std::asin(x);};
        plotFunction(sf::Color::Blue,Functie);
    }
    else if(InfixExpression=="ARCCOS")
    {
        Functie=[](float x){return std::acos(x);};
        plotFunction(sf::Color::Green,Functie);
    }
    else if(InfixExpression=="ARCTG")
    {
        Functie=[](float x){return std::atan(x);};
        plotFunction(sf::Color::Cyan,Functie);
    }
    else if(InfixExpression=="ARCCTG")
    {
        Functie=[](float x){return 1.0f/std::atan(x);};
        plotFunction(sf::Color::Red,Functie);
    }

    

}
Trigonometric::~Trigonometric(){}