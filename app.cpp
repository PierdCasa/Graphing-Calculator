#include "app.h"


App::App()
    : width(1200), height(800), winwidth(1800),
      FontAddress("/home/mario/Desktop/Proiect_POO_SFML/arial.TTF"),
      zoom(FontAddress),
      legenda(FontAddress, width, height, winwidth)
{
    initWindow();
    initTexts();
    initAxes();
}


void App::initWindow(){
    width=1200;
    height=800;
    winwidth=1800;
    title="Graphing Calculator";
    vm=sf::VideoMode({winwidth,height});
    window=new sf::RenderWindow(vm,title);
    window->setFramerateLimit(60);
    view=sf::View(sf::FloatRect({{0,0},{float(winwidth),float(height)}}));
}

void App::initTexts(){
    X=new Texts("x",FontAddress);
    O=new Texts("o",FontAddress);
    Y=new Texts("y",FontAddress);
    input=new Texts("",FontAddress);

    X->setOrigin(X->getGlobalBounds().size/2.0f);
    O->setOrigin(O->getGlobalBounds().size/2.0f);
    Y->setOrigin(X->getGlobalBounds().size/2.0f);

    X->setPosition({width/1.03f,height/2.0f});
    O->setPosition({width/1.95f,height/1.95f});
    Y->setPosition({width/1.95f,0.0f});
    input->setPosition({width/1.0f,0.0f});

    X->setFillColor(sf::Color (255,192,203,255));
    O->setFillColor(sf::Color (255,192,203,255));
    Y->setFillColor(sf::Color (255,192,203,255));
    input->setFillColor(sf::Color::White);
    
}

void App::initAxes(){
    axes.SetPosition(width,height);
    axes.SetColor();
}




void App::pollEvents(){
    while(const std::optional event=window->pollEvent())
    {
        if(event->is<sf::Event::Closed>())
        {
            window->close();
        }
        else if(const auto* textEntered=event->getIf<sf::Event::TextEntered>())
        {
            checkTextEntered(textEntered);
        }
        if(const auto* resiz=event->getIf<sf::Event::Resized>())
        {
            view=getView(view,resiz->size);
        }
        if(const auto *keyPressed=event->getIf<sf::Event::KeyPressed>()) {
           checkZoomOrEsc(keyPressed);
        }
        

    }
}
void App::updating(){
    pollEvents();
}
void App::rendering(){
    window->setView(view);
    window->clear(sf::Color::Black);

    //Draw here!! 
    legenda.Draw(window);
    axes.Draw(window);
    zoom.setZoom(SCALE_X);
    zoom.Draw(window);
    window->draw(*X);
    window->draw(*O);
    window->draw(*Y);
    window->draw(*input);
   
    window->display();
}

App::~App(){
    delete X,O,Y;
    delete window;
}

void App::running(){
    while(window->isOpen()){
        updating();
        rendering();
    }
}

void App::checkZoomOrEsc(const sf::Event::KeyPressed *KeyPressed)
{
    if(KeyPressed->scancode==sf::Keyboard::Scancode::Escape)
    {
     window->close();
    }
    else if(KeyPressed->scancode==sf::Keyboard::Scancode::NumpadPlus){
      SCALE_X*=1.1f;
      SCALE_Y*=1.1f;
    }
    else if(KeyPressed->scancode==sf::Keyboard::Scancode::NumpadMinus){
      SCALE_X*=0.9f;
      SCALE_Y*=0.9f;
      X_MIN -= 10.0f;
      X_MAX += 10.0f;
    }
}

void App::checkTextEntered(const sf::Event::TextEntered *textEntered)
{
     if(textEntered->unicode !=43 && textEntered->unicode!=45)
        {
        if(textEntered->unicode<128 && textEntered->unicode!=8 && !error)
        {
         sStream+=static_cast<char>(textEntered->unicode);
         input->streamText(sStream);
        }
        else if(textEntered->unicode==8 && sStream!="" && !error)
        {
            sStream.erase(sStream.size()-1,1);
            input->streamText(sStream);
        }
        else 
        {   //aicea verificam daca este o eroare activa
            //si se apasa orice alta litera sa treaca la urm
            //si sa nu mai poata primi input/sterge carac
            //pana nu apasa alta tasta
            error=0;
            sStream.clear();
            input->streamText(sStream);
        }
        //am bagat si sStream!="" ca inainte stergeam mai mult decat trebuia
        //si dadea segfault

        if(textEntered->unicode==13 && !error && sStream!="")
        {   
            //aicea o sa fie o funct check function sa vada daca str e o functie
            //si o sa le tratez cum sunt descrise in legenda

            sStream.erase(sStream.size()-1,1);
            if(sStream=="SIN")
            {
            //bool1=1;
            sStream.clear();
            }
            else if(sStream=="COS")
            {
            //bool2=1;
             sStream.clear();
            }
            else if(sStream=="del")
            {
            //bool1=0;
            //bool2=0;
            sStream.clear();
            }
            else 
            {
                sStream.clear();
                sStream="ERROR";
                error=1;
            }
            input->streamText(sStream);
        }
    }
}

void App::checkView(const sf::Event::Resized* resiz)
{
    view=getView(view,resiz->size);
}

sf::View App::getView(sf::View view, sf::Vector2u size) {
    //variab. acestea sunt redunante
    //functia face resizing la imagine setand-o in timpul render-ului
    int windWidth=size.x;
    int windHeight=size.y;
    float windRatio=windWidth/static_cast<float>(windHeight);
    float viewRatio=view.getSize().x/view.getSize().y;
    float sizeX=1.0f, sizeY=1.0f, posX=0.0f,posY=0.0f;

    bool horizSpacing=true;// pt a verifica daca avem stretch pe oriz

    if(windRatio<viewRatio)
        horizSpacing = false;

    if(horizSpacing) {
        sizeX=viewRatio/windRatio;
        posX=(1.0f-sizeX)/2.0f;
    } else {
        sizeY=windRatio/viewRatio;
        posY=(1.0f-sizeY)/2.0f;
    }
    view.setViewport(sf::FloatRect({{posX,posY},{sizeX,sizeY}}));

    return view;
}