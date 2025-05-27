#pragma once
#include <string>

struct AppSettings
{
    unsigned int width=1200;
    unsigned int height=800;
    unsigned int winwidth=1200;
    float SCALE_X=100.0f;
    float SCALE_Y=100.0f;
    float X_MIN=-10.0f;
    float X_MAX=10.0f;
    float STEP=0.01f;
    std::string FontAddress="/home/mario/Desktop/Proiect_POO_SFML/arial.TTF";

};