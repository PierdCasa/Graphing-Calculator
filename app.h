#include <SFML/Graphics.hpp>
#include <string>
#include "texts.h"
#include "OXOY.h"
#include "zoom.h"
#include "legenda.h"
#include "trigonometric.h"
#include "logarithmic.h"
#include "appsettings.h"

//voiam sa o fac singleton da google mi a zis ca nu e o idee buna

template<class T>

void clearFunctii(std::vector<T*>&v)
{
    while(!v.empty())
    {
        delete v.back();
        v.pop_back();
    }
}

class App {
    private:
        
        //bug nu citeste + de la tastatura

        AppSettings W;
        std::string title;
        sf::VideoMode vm;
        sf::RenderWindow *window;
        sf::View view;
        
        //W-- am denumit asa setarile aplicatiei pt a apela mai usor constructorii la alocare dinamica
        //appsettings.h struct care contine toate setarile(font,width,height,winwidth,x_max,x_min,scale_x,scale_y)

        //!!!!change AppSettings::FontAddress("...")  TO YOUR specific PATH or arial.TTF
        
        std::vector<Function*> Functii;
        Zoom zoom;
        Legenda legenda;
        
        std::string sStream;
        Texts  *X,*O,*Y,*input;
        OxOy axes;
        bool error=0;
        

    public:
         App();
        ~App();
        void initWindow();
        void initTexts();
        void initAxes();
        void initAxesLabels();
        void pollEvents();
        void updating();
        void rendering();
        void checkZoomOrEsc(const sf::Event::KeyPressed *KeyPressed);
        void checkTextEntered(const sf::Event::TextEntered *textEntered);
        void checkView(const sf::Event::Resized* resiz);
        sf::View getView(sf::View view,sf::Vector2u size);//sa faca resizing si sa nu se strice textu
        void running();
        bool checkinputTRIGLOG(std::string str);//face si alocare dinamica
        void drawFunctii(sf::RenderWindow* window);
};

//  std::cout<<"Introdu valoarea lui x:"<<"\n";
//  std::getline(std::cin,c);
//  a.GetEvaluate().SetValueOfX(c);
//  a.GetEvaluate().EvaluatePostifx();
//  std::cout<<"Rezultatul evaluarii:"<<"\n";
//  a.GetEvaluate().PrintEvaluationAnswear();