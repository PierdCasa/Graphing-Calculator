#pragma once
#include <string>

struct AppSettings
{
    unsigned int width=1200;
    unsigned int height=800;
    unsigned int win_width=1200;
    float scale_x=100.0f;
    float scale_y=100.0f;
    float x_min=-10.0f;
    float x_max=10.0f;
    float step=0.01f;
    std::string font_address="/home/mario/Desktop/Proiect_POO_SFML/arial.TTF";

};