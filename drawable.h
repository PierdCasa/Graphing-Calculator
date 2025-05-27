#pragma once
#include <SFML/Graphics.hpp>

class Drawable 
{
    private:

    public:
        Drawable()=default;
        virtual void Draw(sf::RenderWindow* window)=0;
        virtual ~Drawable(){};
        //toate clasele care vor mosteni interfata drawable vor avea in plus
        //operator overload la >>(sf::Render* window,cons Class& class)
        //pt a apela class.Draw(window);
        //stiu ca e cam neconventional da chiar nu stiam unde sa adaug
};
//o interfata frumoasa

