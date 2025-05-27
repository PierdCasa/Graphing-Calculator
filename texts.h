#pragma once
#include <sstream>
#include "fonts.h"

class Texts:public sf::Text {
    private:
        std::string originalStr;
        Fonts *fonts;

        void initFont(std::string font_address);
        void initString(std::string str);

    public:
        Texts(std::string str,std::string font_address);
        ~Texts();

        void streamText(std::string str="");

};