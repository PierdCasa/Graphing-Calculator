#include "OXOY.h"

OxOy::OxOy(){
    this->OX.setPrimitiveType(sf::PrimitiveType::Lines);
    this->OY.setPrimitiveType(sf::PrimitiveType::Lines);
    this->arrowOx.setPrimitiveType(sf::PrimitiveType::Triangles);
    this->arrowOy.setPrimitiveType(sf::PrimitiveType::Triangles);
    Resize(OX,OY,arrowOx,arrowOy);
}

void OxOy::Resize(sf::VertexArray& OX,sf::VertexArray& OY,sf::VertexArray& arrowOx,sf::VertexArray& arrowOy){
    OX.resize(2);
    OY.resize(2);
    arrowOx.resize(3);
    arrowOy.resize(3);
}
void OxOy::SetPosition(unsigned int width,unsigned int height){
    OX[0].position={width/2.0f,0.0f};
    OX[1].position={width/2.0f,height/1.0f};
    OY[0].position={0.0f,height/2.0f};
    OY[1].position={width/1.0f,height/2.0f};

    arrowOx[0].position={width/1.0f,height/2.0f};
    arrowOx[1].position={width-1*arrowSz,height/2.0f+1*arrowSz/2};
    arrowOx[2].position={width-1*arrowSz,height/2.0f-1*arrowSz/2};

    arrowOy[0].position={width/2.0f,0.0f};
    arrowOy[1].position={width/2.0f+1*arrowSz/2,1*arrowSz};
    arrowOy[2].position={width/2.0f-1*arrowSz/2,1*arrowSz};

}
// aici am folosit o formula matematica 
// arrow(float x,float y,float dx,float dy,float arrowSz)

// arrow[0].pos={x,y};
// arrow[1].pos={x-dy*arrowSz/2-dx*arrowSz,y+dx*arrowSz/2-dy*arrowsz};
// arrow[2].pos={x+dy*arrowSz/2-dx*arrowSz,y-dx*arrowSz/2-dy*arrowsz};

// iar pt. sagetile mele am folosit

// OX- arrow(width/2.0f,0,0,-1,20,0f);
// OY- arrow(width,height/2.0f,1,0,20.0f);

//as fi putut sa fac functia asta da am
//preferat sa calculez pe foaie cu pixu:)

void OxOy::SetColor(){ 
    OX[0].color=OX[1].color=sf::Color::White;
    OY[0].color=OY[1].color=sf::Color::White;
    arrowOx[0].color=arrowOx[1].color=arrowOx[2].color=sf::Color::White;
    arrowOy[0].color=arrowOy[1].color=arrowOy[2].color=sf::Color::White;
}

void OxOy::Draw(sf::RenderWindow* window)
{   window->draw(arrowOx);
    window->draw(OX);
    window->draw(OY);
    window->draw(arrowOy);
   
}

OxOy::~OxOy(){
}

sf::RenderWindow& operator>>(sf::RenderWindow& window, OxOy& obj) {
    obj.Draw(&window);
    return window;
}