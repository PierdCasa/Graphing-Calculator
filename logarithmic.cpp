#include "logarithmic.h"
#include <cmath>
#include <iostream>

int Logarithmic::m_logarithmic_count=0;

Logarithmic::Logarithmic(AppSettings w,std::string infix_expression):Function(w),m_infix_expression(infix_expression){
    
    m_function_count++;
    m_logarithmic_count++;
    CheckLogarithmicType();
}
//la culori as fi putut sa fac ceva clasa care randomizeaza
//da tocmai ce am stat 3 ore sa ma uit pe unicode-uri sa vad de ce nu mi deseneaza si sa fac debugging cu cout<<ok ok++
//si eu ii dadeam draw fara sa fac plot 

void Logarithmic::CheckLogarithmicType()
{
    if(m_infix_expression=="LN")
    {
        m_functie=[](float x){return std::log(x);};
        this->m_color=sf::Color (193,249,0);
        PlotFunction(m_color,m_functie);
    }
    else if(m_infix_expression=="LG")
    {
        m_functie=[](float x){return std::log10(x);};
        this->m_color=sf::Color (193, 167, 248);
        PlotFunction(m_color,m_functie);
    }
}
void Logarithmic::Replot()
{   
    this->m_graph.resize(0);
    PlotFunction(m_color,m_functie);
}

void Logarithmic::PrintLogarithmicCount()
{   
    if(m_logarithmic_count>1)
    {std::cout<<m_logarithmic_count<<" LOGARITMICE"<<"\n";}
    else if(m_logarithmic_count==1)
    {
     std::cout<<m_logarithmic_count<<" LOGARITMICA"<<"\n";
    }
}
Logarithmic::~Logarithmic(){}