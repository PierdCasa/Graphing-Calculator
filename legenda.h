#include "texts.h"
#include "drawable.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Legenda:public Drawable
{   
    private:
        Texts *Legend,*L1,*L11,*L2,*L22,*L3,*L33,*Obs,*Obs1,*L4,*L44,*Obs2,*Obs22,*Del,*Plus,*Minus;
        sf::RectangleShape rectangle,inputbox;
        std::string FontAddress;
        float width;
        float height;
        float winwidth;
        
    public:
        Legenda(std::string FontAddress,unsigned int width,unsigned int height,unsigned int winwidth);
        void SetPosition();
        void Draw(sf::RenderWindow* window);
        ~Legenda();


};