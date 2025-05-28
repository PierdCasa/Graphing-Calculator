#pragma once

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
//aici am declarat TokenType urile
//la afisearea in terminal de Token::...type Token::.. value enum-ul va afisa la type index-ul type-ul
//ex. OPERATOR=> 0 OPERAND => 1 urmat de caracterul value 0 ("+","-") , 1 ("1","2",,"x")
//



struct Token 
{   //tot publice
    public:
        TokenType type;
        std::string value;
        Token(TokenType type,std::string value);
        ~Token();
};

//struct versus class (am evidentiati prin public, chiar dace e default)
//scop- in contextul dat orice Token este membru privat al unei clase=> este automat inaccessible din exterior
//deci putem folosi struct pentru a stoca datele de tip Token, chiar daca acesta nu "ascunde" datele