
#pragma once
#include "token.h"
#include "typecheck.h"
#include <string>
#include <vector>
// #include <unordered_map>


class Rpn
{ 
  protected:

    std::vector<Token> tokenized_expression;
    std::vector<Token> tokens;
    std::vector<std::string> postfix_expression;
    TypeCheck check;
    bool succesful=1;
    int Type;// am folosit Type ca sa vad ce tip este setez 1 pt algebrice 2 pentru mixe
    std::string X;//e fie "X" mare fie "x"
    bool existsfunction=0;

    
    
  public:

    Rpn();
    void Tokenize(const std::string& infix_expression);
    void ToPostfix();
    // void print(); //pentru debugging
    // void prinsuccesful();//pentru debugging
    // void print_postfix();//pentru debugging
    bool getsuccesful();
    void setType(int type);
    ~Rpn();
};
