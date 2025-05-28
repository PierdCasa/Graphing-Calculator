#include "mixt.h"
#include <cmath>

Mixt::Mixt(AppSettings W):Function(W)
{

}

Evaluate& Mixt::GetEvaluate()
{
    return expr;
}

void Mixt::plotFunction(sf::Color color)
{
    float y;
    this->color=color;
    for(float x=W.X_MIN;x<=W.X_MAX;x+=W.STEP){
        y=expr.EvaluatePostifx(x);
        if(discontinuous && (std::abs(y)>50 || std::isnan(y) || std::isinf(y))){
            continue;
        }
        sf::Vertex point;
        point.position={W.width/2+x*W.SCALE_X,W.height/2-y*W.SCALE_Y};
        point.color=color;
        graph.append(point);
    }
}
void Mixt::Replot()
{
     this->graph.resize(0);
     plotFunction(color);
}
    
Mixt::~Mixt()
{

}
