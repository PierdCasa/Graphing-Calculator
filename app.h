#include <SFML/Graphics.hpp>
#include <string>
#include "texts.h"
#include "OXOY.h"
#include "zoom.h"
#include "legenda.h"
#include "trigonometric.h"
#include "logarithmic.h"
#include "algebraic.h"
#include "mixt.h"
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
        
        AppSettings m_w;
        std::string m_title;
        sf::VideoMode m_vm;
        sf::RenderWindow *m_window;
        sf::View m_view;
        
        //W-- am denumit asa setarile aplicatiei pt a apela mai usor constructorii la alocare dinamica
        //appsettings.h struct care contine toate setarile(font,width,height,winwidth,x_max,x_min,scale_x,scale_y)

        //!!!!change AppSettings::FontAddress("...")  TO YOUR specific PATH or arial.TTF
        
        std::vector<Function*> m_functii;
        Zoom m_zoom;
        Legenda m_legenda;
        std::vector<sf::Color> m_culori;
        int m_index_culoare;
        
        std::string m_sStream;
        Texts  *m_X,*m_O,*m_Y,*m_input;
        OxOy m_axes;
        bool m_error=0;
        bool m_check_plus_minus=0; //bool care diferentiaza dintre numpad '+' '-' si cel normal cu ctrl inainte faceam pe unicode-uri si nu mergea ca au acelasi
        

    public:
         App();
        ~App();
        void InitWindow();
        void InitTexts();
        void InitAxes();
        void InitAxesLabels();
        void PollEvents();
        void Updating();
        void Rendering();
        void CheckZoomOrEsc(const sf::Event::KeyPressed *KeyPressed);
        void CheckTextEntered(const sf::Event::TextEntered *textEntered);
        void CheckView(const sf::Event::Resized* resiz);
        sf::View GetView(sf::View view,sf::Vector2u size);//sa faca resizing si sa nu se strice textu
        void Running();
        bool CheckInputTRIGLOG(std::string str);//face si alocare dinamica
        bool CheckInputALGMIX(std::string str);
        void DrawFunctii(sf::RenderWindow* window);
        void UpdateFunctiiSettings(AppSettings W);//face replot in momentul in care se face zoom in/out
};

//  std::cout<<"Introdu valoarea lui x:"<<"\n";
//  std::getline(std::cin,c);
//  a.GetEvaluate().SetValueOfX(c);
//  a.GetEvaluate().EvaluatePostifx();
//  std::cout<<"Rezultatul evaluarii:"<<"\n";
//  a.GetEvaluate().PrintEvaluationAnswear();