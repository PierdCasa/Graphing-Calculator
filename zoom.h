#pragma once
#include <SFML/Graphics.hpp>
#include "drawable.h"
#include "texts.h"
#include <string>


class Zoom:public virtual Drawable{
    private:
        int m_zoom;
        Texts *m_zoom_pr;
        std::string m_font_address;
    public:
        Zoom(std::string font_address);
        void Draw(sf::RenderWindow* window);
        void SetZoom(float scale_x);
        virtual ~Zoom();
};

sf::RenderWindow& operator>>(sf::RenderWindow& window, Zoom& obj);



