#include "legenda.h"

Legenda::Legenda(std::string FontAddress,unsigned int width,unsigned int height,unsigned int winwidth):FontAddress(FontAddress),width(float(width)),height(float(height)),winwidth(float(winwidth)),rectangle({float(winwidth-width),float(height)}),inputbox({float(winwidth-width),float(height)/8.0f})
{   

    Legend=new Texts("LEGENDA:",FontAddress);
       L1=new Texts("Trigonometrice:",FontAddress); 
      L11=new Texts("SIN COS TG CTG ARCSIN ARCCOS ARCTG ARCCTG ",FontAddress); 
       L2=new Texts("Logaritmice:",FontAddress); 
      L22=new Texts("LN LG",FontAddress); 
       L3=new Texts("Algebrice:",FontAddress); 
      L33=new Texts("Example: X^2+2X+1",FontAddress); 
      Obs=new Texts("OBS:",FontAddress); 
     Obs1=new Texts("Toate functiile de mai sus se scriu cu UPPER CASE.",FontAddress); 
       L4=new Texts("Mixte:",FontAddress); 
      L44=new Texts("Example: sin(x^2+3x+1)  , 2*x+cos(x)",FontAddress); 
     Obs2=new Texts("OBS:",FontAddress); 
    Obs22=new Texts("Toate functiile mixte se scriu cu LOWER CASE.",FontAddress); 
      Del=new Texts(" Type 'del' to  delete all",FontAddress); 
     Plus=new Texts(" Press 'Numpad(+)' to zoom in",FontAddress); 
    Minus=new Texts(" Press 'Numpad(-)' to zoom out",FontAddress); 
 

    rectangle.setFillColor(sf::Color (48,48,48,255));

    inputbox.setFillColor(sf::Color (105,105,105,255));

 Legend->setFillColor(sf::Color::White);
     L1->setFillColor(sf::Color::White);
    L11->setFillColor(sf::Color::White);
     L2->setFillColor(sf::Color::White);
    L22->setFillColor(sf::Color::White);
     L3->setFillColor(sf::Color::White);
    L33->setFillColor(sf::Color::White);
     L4->setFillColor(sf::Color::White);
    L44->setFillColor(sf::Color::White);

    Obs->setFillColor(sf::Color (255,204,204,255));   
    Obs1->setFillColor(sf::Color (255,204,204,255));    
     Del->setFillColor(sf::Color (255,204,204,255));
    Plus->setFillColor(sf::Color (255,204,204,255));
   Minus->setFillColor(sf::Color (255,204,204,255));
    Obs2->setFillColor(sf::Color (255,204,204,255));
   Obs22->setFillColor(sf::Color (255,204,204,255));

    L1->setCharacterSize(20.0f);
    L11->setCharacterSize(20.0f);
     L2->setCharacterSize(20.0f);
    L22->setCharacterSize(20.0f);
     L3->setCharacterSize(20.0f);
    L33->setCharacterSize(20.0f);
    Obs->setCharacterSize(20.0f);
     L4->setCharacterSize(20.0f);
    L44->setCharacterSize(20.0f);
    Obs->setCharacterSize(20.0f);    
     Del->setCharacterSize(20.0f);
    Plus->setCharacterSize(20.0f);
   Minus->setCharacterSize(20.0f);
   Obs1->setCharacterSize(20.0f);
    Obs2->setCharacterSize(20.0f);
   Obs22->setCharacterSize(20.0f);
   SetPosition();


}

void Legenda::SetPosition()
{

    rectangle.setPosition({width,0});

    inputbox.setPosition({width,0});

 Legend->setPosition({width,height/8.0f});
     L1->setPosition({width,150});
    L11->setPosition({width,175});
     L2->setPosition({width,215});
    L22->setPosition({width,240});
     L3->setPosition({width,270});
    L33->setPosition({width,290});
    Obs->setPosition({width,340});
   Obs1->setPosition({width,370}); 
     L4->setPosition({width,440});
    L44->setPosition({width,460});
   Obs2->setPosition({width,510});
  Obs22->setPosition({width,540});
    Del->setPosition({width,670});
   Plus->setPosition({width,700});
  Minus->setPosition({width,730});


}

void Legenda::Draw(sf::RenderWindow* window)
{
        window->draw(rectangle);

        window->draw(inputbox);

        window->draw(*Legend);
        window->draw(*L1);
        window->draw(*L11);
        window->draw(*L2);
        window->draw(*L22);
        window->draw(*L3);
        window->draw(*L33);
        window->draw(*Obs);
        window->draw(*Obs1);
        window->draw(*L4);
        window->draw(*L44);
        window->draw(*Obs2);
        window->draw(*Obs22);
        window->draw(*Del);
        window->draw(*Plus);
        window->draw(*Minus);

}
Legenda::~Legenda(){
    delete Legend,L1,L11,L2,L22,L3,L33,Obs,Obs1,L4,L44,Obs2,Obs22,Del,Plus,Minus;
};