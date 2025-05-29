#include "function.h"
#include <cmath>
#include <iostream>

int Function::m_function_count=0;

Function::Function(AppSettings w):m_w(w)
{
    bool m_discontinuous=false;
}


void Function::PlotFunction(sf::Color color,std::function <float(float)> Functie)
{   
    float y;
    for(float x=m_w.x_min;x<=m_w.x_max;x+=m_w.step){
        y=Functie(x);
        if(m_discontinuous && (std::abs(y)>50 || std::isnan(y) || std::isinf(y))){
            continue;
        }
        sf::Vertex point;
        point.position={m_w.width/2+x*m_w.scale_x,m_w.height/2-y*m_w.scale_y};
        point.color=color;
        m_graph.append(point);
    }

}

void Function::Draw(sf::RenderWindow* window)
{   
    window->draw(m_graph);
}

void Function::UpdateSettings(AppSettings w_new){
    this->m_w=w_new;
}

void Function::PrintFunctionCount()
{   
    if(m_function_count>1)
    {std::cout<<"Ai desenat "<<m_function_count<<" functii."<<"\n";}
    else if(m_function_count==1)
    {
        std::cout<<"Ai desenat "<<m_function_count<<" functie."<<"\n";
    }
}

//returneaza instanta unei functii

