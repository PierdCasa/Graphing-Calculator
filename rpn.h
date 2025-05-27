
#include "token.h"
#include "typecheck.h"
#include <string>
#include <vector>
// #include <unordered_map>


class Rpn
{ 
  protected:

    std::string infix_expression;
    std::vector<Token> tokenized_expression;
    std::vector<Token> tokens;
    std::vector<std::string> postfix_expression;
    TypeCheck check;

    
  public:

    Rpn()=default;
    void Tokenize(const std::string& infix_expression);
    void ToPostfix();
    void print(); //pentru exemplu
    void print_postfix();//pentru exemplu
};
