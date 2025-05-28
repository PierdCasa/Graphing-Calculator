#pragma once

#include <vector>
#include <string>
#include "drawable.h"
#include <SFML/Graphics.hpp>
#include "appsettings.h"
#include <functional>

class Function:public Drawable
{ 
  //sa nu fac getters//setters
  protected:

    sf::VertexArray graph;
    AppSettings W;
    sf::Color color;
    bool discontinuous;
    //aici apare doar Evaluate deoarece RPN-ul va fi folosit pentru a 
    //evalua expresiile am ales ca acesta sa inglobat in clasa Evaluate

  public:
    
    // Function(std::string infix_expression):infix_expression(infix_expression){};
    //lista de intializare a constructorilor -- urmeaza...
    
    Function(AppSettings W);
    //cele algebrice si mixte vor avea o implementare a lor spearata cu RPN :(
    virtual void plotFunction(sf::Color color,std::function <float(float)> Functie); //base derived

    void Draw(sf::RenderWindow* window);
    //Evaluate& GetEvaluate();
    //compunere
    virtual void Replot()=0; //pt a updata cand se face Zoom in Zoom out
    void UpdateSettings(AppSettings WNew);
    virtual ~Function()=default;
};