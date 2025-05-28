#include "app.h"


App::App()
    : zoom(W.FontAddress),
      legenda(W.FontAddress,W.width,W.height,W.winwidth),
Culori({ 
        sf::Color::Red,
        sf::Color::Cyan,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color (159, 255, 255),
        sf::Color (249, 133, 35),
        sf::Color::Magenta,}),indexculoare(0)
{
    initWindow();
    initTexts();
    initAxes();
}


void App::initWindow(){
    W.width=1200;
    W.height=800;
    W.winwidth=1800;
    title="Graphing Calculator";
    vm=sf::VideoMode({W.winwidth,W.height});
    window=new sf::RenderWindow(vm,title);
    window->setFramerateLimit(60);
    view=sf::View(sf::FloatRect({{0,0},{float(W.winwidth),float(W.height)}}));
}

void App::initTexts(){
    X=new Texts("x",W.FontAddress);
    O=new Texts("o",W.FontAddress);
    Y=new Texts("y",W.FontAddress);
    input=new Texts("",W.FontAddress);

    X->setOrigin(X->getGlobalBounds().size/2.0f);
    O->setOrigin(O->getGlobalBounds().size/2.0f);
    Y->setOrigin(X->getGlobalBounds().size/2.0f);

    X->setPosition({W.width/1.03f,W.height/2.0f});
    O->setPosition({W.width/1.95f,W.height/1.95f});
    Y->setPosition({W.width/1.95f,0.0f});
    input->setPosition({W.width/1.0f,0.0f});

    X->setFillColor(sf::Color (255,192,203,255));
    O->setFillColor(sf::Color (255,192,203,255));
    Y->setFillColor(sf::Color (255,192,203,255));
    input->setFillColor(sf::Color::White);
    
}

void App::initAxes(){
    axes.SetPosition(W.width,W.height);
    axes.SetColor();
}


bool App::checkinputTRIGLOG(std::string str)
{  
    if(str=="SIN")
        {Functii.push_back(new Trigonometric(W,"SIN"));
        return 1;}
    if(str=="COS")
        {Functii.push_back(new Trigonometric(W,"COS"));
        return 1;}
    if(str=="TG")
        {Functii.push_back(new Trigonometric(W,"TG"));
        return 1;}
    if(str=="CTG")
        {Functii.push_back(new Trigonometric(W,"CTG"));
        return 1;}
    if(str=="ARCSIN")
        {Functii.push_back(new Trigonometric(W,"ARCSIN"));
        return 1;}
    if(str=="ARCCOS")
        {Functii.push_back(new Trigonometric(W,"ARCCOS"));
        return 1;}
    if(str=="ARCTG")
        {Functii.push_back(new Trigonometric(W,"ARCTG"));
        return 1;}
    if(str=="ARCCTG")
        {Functii.push_back(new Trigonometric(W,"ARCCTG"));
        return 1;}
    if(str=="LN")
        {Functii.push_back(new Logarithmic(W,"LN"));
        return 1;}
    if(str=="LG")
        {Functii.push_back(new Logarithmic(W,"LG"));
        return 1;}
    return 0;
}

bool App::checkinputALGMIX(std::string str)
{   
    int Type;
    for(auto& i:str)
    {
        if(std::isalpha(char(i)))
        {
            if(std::islower(char(i)))
            {
                Type=2;
                break;
            }
            if(std::isupper(char(i)))
            {
                Type=1;
                break;
            }
        }
    }

    if(Type==1)
    {
        Algebraic *p=new Algebraic(W);
        p->GetEvaluate().setType(1);
        p->GetEvaluate().Tokenize(str);
        if(!p->GetEvaluate().getsuccesful())
        {   
            delete p;
            return 0;
        }
        p->GetEvaluate().ToPostfix();
        if(indexculoare==7)
        {
            this->indexculoare=0;
        }
        p->plotFunction(Culori[indexculoare]);
        Functii.push_back(p);
        indexculoare++;
        return 1;
    }
    else if(Type==2)
    {
        Mixt *l=new Mixt(W);
        l->GetEvaluate().setType(2);
        l->GetEvaluate().Tokenize(str);
        if(!l->GetEvaluate().getsuccesful())
        {
            delete l;
            return 0;
        }
        l->GetEvaluate().ToPostfix();
        if(indexculoare==7)
        {
            this->indexculoare=0;
        }
        l->plotFunction(Culori[indexculoare]);
        Functii.push_back(l);
        indexculoare++;
        return 1;
    }
    return 0;
}

void App::drawFunctii(sf::RenderWindow* window)
{   
    for(auto& i:Functii)
    {   
        i->Draw(window);
    }
}

void App::updateFunctiiSettings(AppSettings W)
{
    for(auto& i:Functii)
    {
        i->UpdateSettings(W);
        i->Replot();
    }
}


void App::pollEvents(){
    while(const std::optional event=window->pollEvent())
    {
        if(event->is<sf::Event::Closed>())
        {
            window->close();
        }
        else if(const auto *keyPressed=event->getIf<sf::Event::KeyPressed>()) {
           checkZoomOrEsc(keyPressed);
        }
        
        if(const auto* textEntered=event->getIf<sf::Event::TextEntered>())
        {   
           checkTextEntered(textEntered);
           checkplusminus=0;
        }
        if(const auto* resiz=event->getIf<sf::Event::Resized>())
        {
            view=getView(view,resiz->size);
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
    drawFunctii(window); 
    
    zoom.setZoom(W.SCALE_X);
    (*window)>>zoom;//overloaded
    (*window)>>axes;//overloaded
    window->draw(*X);
    window->draw(*O);
    window->draw(*Y);
    (*window)>>legenda;//overloaded
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
      W.SCALE_X*=1.1f;
      W.SCALE_Y*=1.1f;
      checkplusminus=1;
      updateFunctiiSettings(W);//replot the drawn Functions

    }
    else if(KeyPressed->scancode==sf::Keyboard::Scancode::NumpadMinus){
      W.SCALE_X*=0.9f;
      W.SCALE_Y*=0.9f;
      W.X_MIN -= 10.0f;
      W.X_MAX += 10.0f;
      checkplusminus=1;
      updateFunctiiSettings(W);

    }
}

void App::checkTextEntered(const sf::Event::TextEntered *textEntered)
{
        if(!checkplusminus)
        {
        if(textEntered->unicode<128 && textEntered->unicode!=8 && !error )
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

            //urmeaza sa renunt si la exit(0) urile din algoritmi (RPN,FUNCTION,EVALUATE)
            error=0;
            sStream.clear();
            input->streamText(sStream);
        }
        //am bagat si sStream!="" ca inainte stergeam mai mult decat trebuia
        //si dadea segfault
        if(textEntered->unicode==13 && !error && sStream!="")
        {   
           
            
            sStream.erase(sStream.size()-1,1);
            if(checkinputTRIGLOG(sStream))
            {   
                sStream.clear();
            }
            else if(sStream=="del")
            {
                clearFunctii(Functii);
                sStream.clear();
            }
            else if(checkinputALGMIX(sStream))
            {
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
