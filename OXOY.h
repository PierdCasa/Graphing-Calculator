#include "drawable.h"
#include <SFML/Graphics.hpp>

class OxOy:public virtual Drawable
{   
    private:
        sf::VertexArray OX;
        sf::VertexArray OY;
        sf::VertexArray arrowOx;
        sf::VertexArray arrowOy;
        const float arrowSz=20.0f;

    public:
        OxOy();
        void Resize(sf::VertexArray& OX,sf::VertexArray& OY,sf::VertexArray& arrowOx,sf::VertexArray& arrowOy);
        void SetPosition(unsigned int width,unsigned int height);
        void SetColor();
        void Draw(sf::RenderWindow* window);
        virtual ~OxOy();
};

sf::RenderWindow& operator>>(sf::RenderWindow& window, OxOy& obj);