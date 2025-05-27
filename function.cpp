#include "function.h"
#include <cmath>
Function::Function(AppSettings W):W(W)
{
    bool discontinuous=false;
}


void Function::plotFunction(sf::Color color,std::function <float(float)> Functie)
{   
    float y;
    for(float x=W.X_MIN;x<=W.X_MAX;x+=W.STEP){
        y=Functie(x);
        if(discontinuous && (std::abs(y)>50 || std::isnan(y) || std::isinf(y))){
            continue;
        }
        sf::Vertex point;
        point.position={W.width/2+x*W.SCALE_X,W.height/2-y*W.SCALE_Y};
        point.color=color;
        graph.append(point);
    }

}

void Function::Draw(sf::RenderWindow* window)
{
    window->draw(graph);
}



//returneaza instanta unei functii

