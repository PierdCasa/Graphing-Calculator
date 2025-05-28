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
        this->color=sf::Color (159, 255, 255);
        plotFunction(color,Functie);
        //din C++ 11 s-a introdus functional care permite memorarea functiilor de toate tipurile in variabile
    }
    else if(InfixExpression=="COS")
    {
        Functie=[](float x){return std::cos(x);};
        this->color=sf::Color (249, 133, 35);
        plotFunction(color,Functie);
    }
    else if(InfixExpression=="TG")
    {
        Functie=[](float x){return std::tan(x);};
        //aici as fi putut face o aproximatie mai buna
        //mai exact cu std::sin(x)/std::cos(x)
        //but it's ok asa
        this->color=sf::Color::Magenta;
        plotFunction(color,Functie);
    }
    else if(InfixExpression=="CTG")
    {
        Functie=[](float x){return 1.0f/std::tan(x);};
        this->color=sf::Color::Yellow;
        plotFunction(color,Functie);
        //inversa cotangentei
    }
    else if(InfixExpression=="ARCSIN")
    {
        Functie=[](float x){return std::asin(x);};
        this->color=sf::Color::Blue;
        plotFunction(color,Functie);
    }
    else if(InfixExpression=="ARCCOS")
    {
        Functie=[](float x){return std::acos(x);};
        this->color=sf::Color::Green;
        plotFunction(color,Functie);
        
    }
    else if(InfixExpression=="ARCTG")
    {
        Functie=[](float x){return std::atan(x);};
        this->color=sf::Color::Cyan;
        plotFunction(color,Functie);
    }
    else if(InfixExpression=="ARCCTG")
    {   
        Functie=[](float x){return static_cast<float>(M_PI_2) - std::atan(x);}; //am updatat fiindca nu desena bine
        //M_PI_2 implementation of PI in <cmath>
        this->color=sf::Color::Red;
        plotFunction(color,Functie);
    }

    //am scris de 10 ori plotFunction da e ok

}

void Trigonometric::Replot()
{     
      this->graph.resize(0);
     plotFunction(color,Functie);
}

Trigonometric::~Trigonometric(){}