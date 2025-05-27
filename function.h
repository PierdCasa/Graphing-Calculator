
#include <vector>
#include <string>
#include "evaluate.h"
#include "drawable.h"
#include <SFML/Graphics.hpp>

class Function:public Drawable
{
  private:
    std::vector<std::string> postfix_expression;
    Evaluate expr;

    sf::VertexArray graph;
    float X_MIN;
    float X_MAX;
    float SCALE_X;
    float SCALE_Y;
    float STEP;
    unsigned int width;
    unsigned int height;
    static sf::Color color;
    bool discontinuous;
    //aici apare doar Evaluate deoarece RPN-ul va fi folosit pentru a 
    //evalua expresiile am ales ca acesta sa inglobat in clasa Evaluate

  public:
    
    // Function(std::string infix_expression):infix_expression(infix_expression){};
    //lista de intializare a constructorilor -- urmeaza...
    
    Function(float X_MIN,float X_MAX,float STEP,unsigned int width,unsigned int height,float SCALE_X,float SCALE_Y);
    void plotFunction(sf::RenderWindow& window,sf::Color color);
    void Draw(sf::RenderWindow* window);
    Evaluate& GetEvaluate();
    //compunere
    
    virtual ~Function()=default;
};