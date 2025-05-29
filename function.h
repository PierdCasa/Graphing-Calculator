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

    sf::VertexArray m_graph;
    AppSettings m_w;
    sf::Color m_color;
    bool m_discontinuous;
    static int m_function_count;
    //aici apare doar Evaluate deoarece RPN-ul va fi folosit pentru a 
    //evalua expresiile am ales ca acesta sa inglobat in clasa Evaluate

  public:
    
    // Function(std::string infix_expression):infix_expression(infix_expression){};
    //lista de intializare a constructorilor -- urmeaza...
    
    Function(AppSettings w);
    //cele algebrice si mixte vor avea o implementare a lor spearata cu RPN :(
    virtual void PlotFunction(sf::Color color,std::function <float(float)> functie); //base derived

    void Draw(sf::RenderWindow* window);
    //Evaluate& GetEvaluate();
    //compunere
    virtual void Replot()=0; //pt a updata cand se face Zoom in Zoom out
    void UpdateSettings(AppSettings w_new);
    static void PrintFunctionCount();
    virtual ~Function()=default;
};
