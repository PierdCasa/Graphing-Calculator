#include "texts.h"

 void Texts::_InitFont(std::string font_address){
    m_fonts=new Fonts(font_address);
    this->setFont(*m_fonts);
 }
 void Texts::_InitString(std::string str){
    m_original_str=str;
    this->setString(m_original_str);
 }
 Texts::Texts(std::string str,std::string font_address):sf::Text(*m_fonts){
    _InitFont(font_address);
    _InitString(str);
 }
 Texts::~Texts(){
    delete m_fonts;
 }

 void Texts::StreamText(std::string str){
    std::stringstream sStream;
    sStream<<str;
    this->setString(sStream.str());
 }