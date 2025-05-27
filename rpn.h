
#include "token.h"
#include "typecheck.h"
#include <string>
#include <vector>
#include <unordered_map>


class Rpn:public TypeCheck
{ 
  protected:

    std::string infix_expression;
    std::vector<Token> tokenized_expression;
    std::vector<Token> tokens;
    std::vector<std::string> postfix_expression;

    
  public:

    Rpn()=default;
    void Tokenize(const std::string& infix_expression);
    void ToPostfix();
    void print(); //pentru exemplu
    void print_postfix();//pentru exemplu
};
