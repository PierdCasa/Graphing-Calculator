#pragma once
#include <sstream>
#include "fonts.h"

class Texts:public sf::Text {
    private:
        std::string m_original_str;
        Fonts *m_fonts;

        void _InitFont(std::string font_address);
        void _InitString(std::string str);

    public:
        Texts(std::string str,std::string font_address);
        ~Texts();

        void StreamText(std::string str="");

};