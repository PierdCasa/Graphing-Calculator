#include "texts.h"

 void Texts::initFont(std::string font_address){
    fonts=new Fonts(font_address);
    this->setFont(*fonts);
 }
 void Texts::initString(std::string str){
    originalStr=str;
    this->setString(originalStr);
 }
 Texts::Texts(std::string str,std::string font_address):sf::Text(*fonts){
    initFont(font_address);
    initString(str);
 }
 Texts::~Texts(){
    delete fonts;
 }

 void Texts::streamText(std::string str){
    std::stringstream sStream;
    sStream<<str;
    this->setString(sStream.str());
 }