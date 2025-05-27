#include "zoom.h"

// Remove member initializer for ZoomPr, and initialize it in initFont instead

Zoom::Zoom(std::string FontAddress):FontAddress(FontAddress){
    ZoomPr=new Texts("100%",FontAddress);
    ZoomPr->setPosition({0.0f,0.0f});
    ZoomPr->setFillColor(sf::Color::White);
}

void Zoom::Draw(sf::RenderWindow* window){
    window->draw(*ZoomPr);
}

Zoom::~Zoom(){
    delete ZoomPr;
}
void Zoom::setZoom(float SCALE_X)
{   
    ZoomPr->streamText(std::to_string(int(SCALE_X))+"%");
    //o conversie misto
}

sf::RenderWindow& operator>>(sf::RenderWindow& window, Zoom& obj) {
    obj.Draw(&window);
    return window;
}