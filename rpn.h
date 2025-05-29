
#pragma once
#include "token.h"
#include "type_check.h"
#include <string>
#include <vector>
// #include <unordered_map>


class Rpn
{ 
  protected:

    std::vector<Token> m_tokenized_expression;
    std::vector<Token> m_tokens;
    std::vector<std::string> m_postfix_expression;
    TypeCheck m_check;
    bool m_succesful=1;
    int m_type;// am folosit Type ca sa vad ce tip este setez 1 pt algebrice 2 pentru mixe
    std::string m_x;//e fie "X" mare fie "x"
    bool m_existsfunction=0;

    
    
  public:

    Rpn();
    void Tokenize(const std::string& infix_expression);
    void ToPostfix();
    // void print(); //pentru debugging
    // void prinsuccesful();//pentru debugging
    // void print_postfix();//pentru debugging
    bool GetSuccesful();
    void SetType(int type);
    ~Rpn();
};
