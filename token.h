
#include <string>
#include <vector>


enum TokenType
{ 
  OPERATOR,
  OPERAND,
  LEFT_PARANTHESIS,
  RIGHT_PARANTHESIS,
  UNKNOWN
};

struct Token 
{   TokenType type;
    std::string value;
};
