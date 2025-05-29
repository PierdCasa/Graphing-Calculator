#include "zoom.h"

// Remove member initializer for ZoomPr, and initialize it in initFont instead

Zoom::Zoom(std::string font_address):m_font_address(font_address){
    m_zoom_pr=new Texts("100%",font_address);
    m_zoom_pr->setPosition({0.0f,0.0f});
    m_zoom_pr->setFillColor(sf::Color::White);
}

void Zoom::Draw(sf::RenderWindow* window){
    window->draw(*m_zoom_pr);
}

Zoom::~Zoom(){
    delete m_zoom_pr;
}
void Zoom::SetZoom(float scale_x)
{   
    m_zoom_pr->StreamText(std::to_string(int(scale_x))+"%");
    //o conversie misto
}

sf::RenderWindow& operator>>(sf::RenderWindow& window, Zoom& obj) {
    obj.Draw(&window);
    return window;
}