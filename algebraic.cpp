#include "algebraic.h"
#include <cmath>
#include <iostream>

int Algebraic::m_algebraic_count=0;

Algebraic::Algebraic(AppSettings w):Function(w)
{

}
Evaluate& Algebraic::GetEvaluate()
{
  return m_expr;
}

void Algebraic::PlotFunction(sf::Color color)
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

void Algebraic::Replot()
{
     this->m_graph.resize(0);
     PlotFunction(m_color);
}

void Algebraic::PrintAlgebraicCount()
{
    if(m_algebraic_count>1)
    {
        std::cout<<m_algebraic_count<<" "<<" ALGEBRICE"<<"\n";
    }
    else if(m_algebraic_count==1)
    {
        std::cout<<m_algebraic_count<<" "<<" ALGEBRICA"<<"\n";
    }
}
Algebraic::~Algebraic()
{   
    if(m_expr.GetSuccesful())
    {
        m_function_count++;
        m_algebraic_count++;
    }

}