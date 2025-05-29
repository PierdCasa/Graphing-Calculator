#include "app.h"


App::App()
    : m_zoom(m_w.font_address),
      m_legenda(m_w.font_address,m_w.width,m_w.height,m_w.win_width),
m_culori({ 
        sf::Color::Red,
        sf::Color::Cyan,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color (159, 255, 255),
        sf::Color (249, 133, 35),
        sf::Color::Magenta,}),m_index_culoare(0)
{
    InitWindow();
    InitTexts();
    InitAxes();
}


void App::InitWindow(){
    m_w.width=1200;
    m_w.height=800;
    m_w.win_width=1800;
    m_title="Graphing Calculator";
    m_vm=sf::VideoMode({m_w.win_width,m_w.height});
    m_window=new sf::RenderWindow(m_vm,m_title);
    m_window->setFramerateLimit(60);
    m_view=sf::View(sf::FloatRect({{0,0},{float(m_w.win_width),float(m_w.height)}}));
}

void App::InitTexts(){
    m_X=new Texts("x",m_w.font_address);
    m_O=new Texts("o",m_w.font_address);
    m_Y=new Texts("y",m_w.font_address);
    m_input=new Texts("",m_w.font_address);

    m_X->setOrigin(m_X->getGlobalBounds().size/2.0f);
    m_O->setOrigin(m_O->getGlobalBounds().size/2.0f);
    m_Y->setOrigin(m_X->getGlobalBounds().size/2.0f);

    m_X->setPosition({m_w.width/1.03f,m_w.height/2.0f});
    m_O->setPosition({m_w.width/1.95f,m_w.height/1.95f});
    m_Y->setPosition({m_w.width/1.95f,0.0f});
    m_input->setPosition({m_w.width/1.0f,0.0f});

    m_X->setFillColor(sf::Color (255,192,203,255));
    m_O->setFillColor(sf::Color (255,192,203,255));
    m_Y->setFillColor(sf::Color (255,192,203,255));
    m_input->setFillColor(sf::Color::White);
    
}

void App::InitAxes(){
    m_axes.SetPosition(m_w.width,m_w.height);
    m_axes.SetColor();
}


bool App::CheckInputTRIGLOG(std::string str)
{  
    if(str=="SIN")
        {m_functii.push_back(new Trigonometric(m_w,"SIN"));
        return 1;}
    if(str=="COS")
        {m_functii.push_back(new Trigonometric(m_w,"COS"));
        return 1;}
    if(str=="TG")
        {m_functii.push_back(new Trigonometric(m_w,"TG"));
        return 1;}
    if(str=="CTG")
        {m_functii.push_back(new Trigonometric(m_w,"CTG"));
        return 1;}
    if(str=="ARCSIN")
        {m_functii.push_back(new Trigonometric(m_w,"ARCSIN"));
        return 1;}
    if(str=="ARCCOS")
        {m_functii.push_back(new Trigonometric(m_w,"ARCCOS"));
        return 1;}
    if(str=="ARCTG")
        {m_functii.push_back(new Trigonometric(m_w,"ARCTG"));
        return 1;}
    if(str=="ARCCTG")
        {m_functii.push_back(new Trigonometric(m_w,"ARCCTG"));
        return 1;}
    if(str=="LN")
        {m_functii.push_back(new Logarithmic(m_w,"LN"));
        return 1;}
    if(str=="LG")
        {m_functii.push_back(new Logarithmic(m_w,"LG"));
        return 1;}
    return 0;
}

bool App::CheckInputALGMIX(std::string str)
{   
    int type;
    for(auto& i:str)
    {
        if(std::isalpha(char(i)))
        {
            if(std::islower(char(i)))
            {
                type=2;
                break;
            }
            if(std::isupper(char(i)))
            {
                type=1;
                break;
            }
        }
    }

    if(type==1)
    {
        Algebraic *p=new Algebraic(m_w);
        p->GetEvaluate().SetType(1);
        p->GetEvaluate().Tokenize(str);
        if(!p->GetEvaluate().GetSuccesful())
        {   
            delete p;
            return 0;
        }
        p->GetEvaluate().ToPostfix();
        if(m_index_culoare==7)
        {
            this->m_index_culoare=0;
        }
        p->PlotFunction(m_culori[m_index_culoare]);
        m_functii.push_back(p);
        m_index_culoare++;
        return 1;
    }
    else if(type==2)
    {
        Mixt *l=new Mixt(m_w);
        l->GetEvaluate().SetType(2);
        l->GetEvaluate().Tokenize(str);
        if(!l->GetEvaluate().GetSuccesful())
        {
            delete l;
            return 0;
        }
        l->GetEvaluate().ToPostfix();
        if(m_index_culoare==7)
        {
            this->m_index_culoare=0;
        }
        l->PlotFunction(m_culori[m_index_culoare]);
        m_functii.push_back(l);
        m_index_culoare++;
        return 1;
    }
    return 0;
}

void App::DrawFunctii(sf::RenderWindow* window)
{   
    for(auto& i:m_functii)
    {   
        i->Draw(window);
    }
}

void App::UpdateFunctiiSettings(AppSettings w)
{
    for(auto& i:m_functii)
    {
        i->UpdateSettings(w);
        i->Replot();
    }
}


void App::PollEvents(){
    while(const std::optional event=m_window->pollEvent())
    {
        if(event->is<sf::Event::Closed>())
        {
            m_window->close();
        }
        else if(const auto *keyPressed=event->getIf<sf::Event::KeyPressed>()) {
           CheckZoomOrEsc(keyPressed);
        }
        
        if(const auto* textEntered=event->getIf<sf::Event::TextEntered>())
        {   
           CheckTextEntered(textEntered);
           m_check_plus_minus=0;
        }
        if(const auto* resiz=event->getIf<sf::Event::Resized>())
        {
            m_view=GetView(m_view,resiz->size);
        } 

    }
}
void App::Updating(){
    PollEvents();
}
void App::Rendering(){
    m_window->setView(m_view);
    m_window->clear(sf::Color::Black);

    //Draw here!!
    DrawFunctii(m_window); 
    
    m_zoom.SetZoom(m_w.scale_x);
    (*m_window)>>m_zoom;//overloaded
    (*m_window)>>m_axes;//overloaded
    m_window->draw(*m_X);
    m_window->draw(*m_O);
    m_window->draw(*m_Y);
    (*m_window)>>m_legenda;//overloaded
    m_window->draw(*m_input);
    
    
   
    m_window->display();
}

void App::Running(){
    while(m_window->isOpen()){
        Updating();
        Rendering();
    }
}

void App::CheckZoomOrEsc(const sf::Event::KeyPressed *KeyPressed)
{
    if(KeyPressed->scancode==sf::Keyboard::Scancode::Escape)
    {
     m_window->close();
    }
    else if(KeyPressed->scancode==sf::Keyboard::Scancode::NumpadPlus){
      m_w.scale_x*=1.1f;
      m_w.scale_y*=1.1f;
      m_check_plus_minus=1;
      UpdateFunctiiSettings(m_w);//replot the drawn Functions

    }
    else if(KeyPressed->scancode==sf::Keyboard::Scancode::NumpadMinus){
      m_w.scale_x*=0.9f;
      m_w.scale_y*=0.9f;
      m_w.x_min -= 10.0f;
      m_w.x_max += 10.0f;
      m_check_plus_minus=1;
      UpdateFunctiiSettings(m_w);

    }
}

void App::CheckTextEntered(const sf::Event::TextEntered *textEntered)
{
        if(!m_check_plus_minus)
        {
        if(textEntered->unicode<128 && textEntered->unicode!=8 && !m_error )
        {
         m_sStream+=static_cast<char>(textEntered->unicode);
         m_input->StreamText(m_sStream);
        }
        else if(textEntered->unicode==8 && m_sStream!="" && !m_error)
        {
            m_sStream.erase(m_sStream.size()-1,1);
            m_input->StreamText(m_sStream);
        }
        
        else 
        {   //aicea verificam daca este o eroare activa
            //si se apasa orice alta litera sa treaca la urm
            //si sa nu mai poata primi input/sterge carac
            //pana nu apasa alta tasta

            //urmeaza sa renunt si la exit(0) urile din algoritmi (RPN,FUNCTION,EVALUATE)
            m_error=0;
            m_sStream.clear();
            m_input->StreamText(m_sStream);
        }
        //am bagat si sStream!="" ca inainte stergeam mai mult decat trebuia
        //si dadea segfault
        if(textEntered->unicode==13 && !m_error && m_sStream!="")
        {   
           
            
            m_sStream.erase(m_sStream.size()-1,1);
            if(CheckInputTRIGLOG(m_sStream))
            {   
                m_sStream.clear();
            }
            else if(m_sStream=="del")
            {
                clearFunctii(m_functii);
                m_sStream.clear();
            }
            else if(CheckInputALGMIX(m_sStream))
            {
                m_sStream.clear();
            }
            else 
            {
                m_sStream.clear();
                m_sStream="ERROR";
                m_error=1;
            }
            m_input->StreamText(m_sStream);
        }
    }
}

void App::CheckView(const sf::Event::Resized* resiz)
{
    m_view=GetView(m_view,resiz->size);
}

sf::View App::GetView(sf::View view, sf::Vector2u size) {
    //variab. acestea sunt redunante
    //functia face resizing la imagine setand-o in timpul render-ului
    int wind_width=size.x;
    int wind_height=size.y;
    float wind_ratio=wind_width/static_cast<float>(wind_height);
    float view_ratio=view.getSize().x/view.getSize().y;
    float size_x=1.0f, size_y=1.0f, pos_x=0.0f,pos_y=0.0f;

    bool horiz_spacing=true;// pt a verifica daca avem stretch pe oriz

    if(wind_ratio<view_ratio)
        horiz_spacing = false;

    if(horiz_spacing) {
        size_x=view_ratio/wind_ratio;
        pos_x=(1.0f-size_x)/2.0f;
    } else {
        size_x=wind_ratio/view_ratio;
        pos_y=(1.0f-size_y)/2.0f;
    }
    view.setViewport(sf::FloatRect({{pos_x,pos_y},{size_x,size_y}}));

    return view;
}

App::~App(){
    
    Function::PrintFunctionCount();
    Trigonometric::PrintTrigonometricCount();
    Logarithmic::PrintLogarithmicCount();
    Algebraic::PrintAlgebraicCount();
    Mixt::PrintMixtCount();

    delete m_X,m_O,m_Y;
    delete m_window;
}


