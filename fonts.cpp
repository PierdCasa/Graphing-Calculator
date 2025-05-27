#include "fonts.h"

void Fonts::initFonts(std::string address){
    if(!this->openFromFile(address))
    {
        std::cerr<<"ERROR::FONT::COULD NOT BE LOADED"<<std::endl;

    }
    this->setSmooth(false);
}

Fonts::Fonts(std::string address){
    initFonts(address);
}

Fonts::~Fonts(){}