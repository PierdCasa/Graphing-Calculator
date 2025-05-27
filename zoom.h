#pragma once
#include <SFML/Graphics.hpp>
#include "drawable.h"
#include "texts.h"
#include <string>

class Zoom:public virtual Drawable{
    private:
        int zoom;
        Texts *ZoomPr;
        std::string FontAddress;
    public:
        Zoom(std::string FontAddress);
        void Draw(sf::RenderWindow* window);
        void setZoom(float SCALE_X);
        virtual ~Zoom();
};
