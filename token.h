
#include <string>
#include <vector>


enum TokenType
{ 
  OPERATOR,
  OPERAND,
  FUNCTION,
  LEFT_PARANTHESIS,
  RIGHT_PARANTHESIS,
  UNKNOWN
};

struct Token 
{   //tot publice
    public:
        TokenType type;
        std::string value;
        Token(TokenType type,std::string value);
        ~Token();
};