#include "trigonometric.h"
#include <cmath>
#include <iostream>

int Trigonometric::m_trigonometric_count=0;

Trigonometric::Trigonometric(AppSettings w,std::string infix_expression):Function(w),m_infix_expression(infix_expression){
    m_function_count++;
    m_trigonometric_count++;
    CheckTrigonometricType();
}

void Trigonometric::CheckTrigonometricType()
{
    if(m_infix_expression=="SIN")
    {
        m_functie=[](float x){return std::sin(x);};
        this->m_color=sf::Color (159, 255, 255);
        PlotFunction(m_color,m_functie);
        //din C++ 11 s-a introdus functional care permite memorarea functiilor de toate tipurile in variabile
    }
    else if(m_infix_expression=="COS")
    {
        m_functie=[](float x){return std::cos(x);};
        this->m_color=sf::Color (249, 133, 35);
        PlotFunction(m_color,m_functie);
    }
    else if(m_infix_expression=="TG")
    {
        m_functie=[](float x){return std::tan(x);};
        //aici as fi putut face o aproximatie mai buna
        //mai exact cu std::sin(x)/std::cos(x)
        //but it's ok asa
        this->m_color=sf::Color::Magenta;
        PlotFunction(m_color,m_functie);
    }
    else if(m_infix_expression=="CTG")
    {
        m_functie=[](float x){return 1.0f/std::tan(x);};
        this->m_color=sf::Color::Yellow;
        PlotFunction(m_color,m_functie);
        //inversa cotangentei
    }
    else if(m_infix_expression=="ARCSIN")
    {
        m_functie=[](float x){return std::asin(x);};
        this->m_color=sf::Color::Blue;
        PlotFunction(m_color,m_functie);
    }
    else if(m_infix_expression=="ARCCOS")
    {
        m_functie=[](float x){return std::acos(x);};
        this->m_color=sf::Color::Green;
        PlotFunction(m_color,m_functie);
        
    }
    else if(m_infix_expression=="ARCTG")
    {
        m_functie=[](float x){return std::atan(x);};
        this->m_color=sf::Color::Cyan;
        PlotFunction(m_color,m_functie);
    }
    else if(m_infix_expression=="ARCCTG")
    {   
        m_functie=[](float x){return static_cast<float>(M_PI_2) - std::atan(x);}; //am updatat fiindca nu desena bine
        //M_PI_2 implementation of PI in <cmath>
        this->m_color=sf::Color::Red;
        PlotFunction(m_color,m_functie);
    }

    //am scris de 10 ori plotFunction da e ok

}

void Trigonometric::Replot()
{     
      this->m_graph.resize(0);
     PlotFunction(m_color,m_functie);
}

void Trigonometric::PrintTrigonometricCount()
{   
    if(m_trigonometric_count>1)
    {std::cout<<m_trigonometric_count<<" TRIGONOMETRICE"<<"\n";}
    else if(m_trigonometric_count==1)
    {
        std::cout<<m_trigonometric_count<<" TRIGONOMETRICA"<<"\n";
    }
}
Trigonometric::~Trigonometric(){}