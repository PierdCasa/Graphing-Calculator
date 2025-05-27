#include "function.h"
#include <cmath>
Function::Function(float X_MIN,float X_MAX,float STEP,unsigned int width,unsigned int height,float SCALE_X,float SCALE_Y):
                    graph(sf::PrimitiveType::LineStrip),
                    X_MIN(X_MIN),X_MAX(X_MAX),STEP(STEP),
                    SCALE_X(SCALE_X),SCALE_Y(SCALE_Y),
                    width(width),height(height)
{
    bool discontinuous=false;
}

Evaluate& Function::GetEvaluate()
{
  return expr;
}

void Function::plotFunction(sf::RenderWindow& window,sf::Color color)
{   
    float y;
    for(float x=X_MIN;x<=X_MAX;x+=STEP){
        y=0;
        if(discontinuous && (std::abs(y)>50 || std::isnan(y) || std::isinf(y))){
            continue;
        }
        sf::Vertex point;
        point.position={width/2+x*SCALE_X,height/2-y*SCALE_Y};
        point.color=color;
        graph.append(point);
    }

}

void Function::Draw(sf::RenderWindow* window)
{
    window->draw(graph);
}



//returneaza instanta unei functii

