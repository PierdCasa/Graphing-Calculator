#include "interface.h"
#include <iostream>

UI::UI()
{
    std::cout<<"Introdu tipul de functie:(1-ALGEBRICA 2-TRIGONOMTRICA 3-LOGARITMICA)"<<"\n";
    Switch_Function_Type();
}

void UI::Algebric_Run()
{
    Function a;
    a.GetEvaluate().Tokenize(input2);
    a.GetEvaluate().ToPostfix();
    std::cout<<"Expresia postfix"<<"\n";
    a.GetEvaluate().print_postfix();
    std::cout<<"Introdu valoarea lui x:"<<"\n";
    std::string c;
    std::getline(std::cin,c);
    a.GetEvaluate().SetValueOfX(c);
    a.GetEvaluate().EvaluatePostifx();
    std::cout<<"Rezultatul evaluarii:"<<"\n";
    a.GetEvaluate().PrintEvaluationAnswear();
    
}
void UI::Switch_Function_Type()
{
    std::getline(std::cin,input);
    //urmeaza sa fac acest loop infint pana la apasarea tastei exit
    //si sa adaug un nou switch in care userul sa aleaga ce doreste sa faca
    //sa deseneze graficul(pentru toate) sau sa evalueze expresia(ma gandesc pred.
    //la cele algebrice)
    switch(input[0])
    {
        case '1':
            std::cout<<"Introdu expresia infix:"<<"\n";
            std:getline(std::cin,input2);
            Algebric_Run();
            break;
        case '2':
            std::cout<<"We're sorry..."<<"\n";
            exit(0);
            break;
        case '3':
            std::cout<<"We're sorry..."<<"\n";
            exit(0);
            break;
        default:
            std::cout<<"Wrong input!!"<<"\n";
            exit(0);
    }
}
