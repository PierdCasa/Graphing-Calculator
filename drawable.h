#pragma once
#include <SFML/Graphics.hpp>

class Drawable 
{
    private:

    public:
        Drawable()=default;
        virtual void Draw(sf::RenderWindow* window)=0;
        virtual ~Drawable(){};
};
//o interfata frumoasa

