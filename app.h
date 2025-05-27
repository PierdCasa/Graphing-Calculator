#include <SFML/Graphics.hpp>
#include <string>
#include "texts.h"
#include "OXOY.h"
#include "zoom.h"
#include "legenda.h"
//voiam sa o fac singleton da google mi a zis ca nu e o idee buna

class App {
    private:

        unsigned int width;
        unsigned int height;
        unsigned int winwidth;//asta i aia mai lunga
        float SCALE_X=100.0f;
        float SCALE_Y=100.0f;
        float X_MIN=-10.0f;
        float X_MAX=10.0f;
        // float STEP=0.01f;
        
        std::string title;
        sf::VideoMode vm;
        sf::RenderWindow *window;
        sf::View view;
        std::string FontAddress;
        //!!!!change TO YOUR specific PATH or arial.TTF
        //e in constructorul lui App Path-ul(sus de tot)

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
};