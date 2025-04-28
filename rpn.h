
#include "token.h"


#include <string>
#include <vector>

class Rpn
{ 
  private:

    std::string infix_expression;
    std::vector<Token> tokenized_expression;
    std::vector<Token> tokens;
    std::vector<std::string> postfix_expression;

    
  public:

    // void SetInfix(std::string infix_expression)
    // {
    //   this->infix_expression=infix_expression;
    // }
    // void SetPostfix(std::vector<std::string>postfix_expression)
    // {
    //   this->postfix_expression=postfix_expression;
    // }

    Rpn()=default;
    bool IsOperator(char c);
    bool IsOperand(char c);
    int Precedence(char op);//functie statica
    void Tokenize(const std::string& infix_expression);
    void ToPostfix(const std::vector<Token>&tokens);

    void print();
};
