#include "mixt.h"
#include <cmath>
#include <iostream>

int Mixt::m_mixt_count=0;

Mixt::Mixt(AppSettings w):Function(w)
{

}

Evaluate& Mixt::GetEvaluate()
{
    return m_expr;
}

void Mixt::PlotFunction(sf::Color color)
{
    float y;
    this->m_color=color;
    for(float x=m_w.x_min;x<=m_w.x_max;x+=m_w.step){
        y=m_expr.EvaluatePostifx(x);
        if(m_discontinuous && (std::abs(y)>50 || std::isnan(y) || std::isinf(y))){
            continue;
        }
        sf::Vertex point;
        point.position={m_w.width/2+x*m_w.scale_x,m_w.height/2-y*m_w.scale_y};
        point.color=color;
        m_graph.append(point);
    }
}
void Mixt::Replot()
{
     this->m_graph.resize(0);
     PlotFunction(m_color);
}

void Mixt::PrintMixtCount()
{   
    if(m_mixt_count>1)
    {std::cout<<m_mixt_count<<" MIXTE"<<"\n";}
    else if(m_mixt_count)
    {
     std::cout<<m_mixt_count<<" MIXTA"<<"\n";
    }
}
    
Mixt::~Mixt()
{
    if(m_expr.GetSuccesful())
    {
        m_function_count++;
        m_mixt_count++;
    }
}

