#include <string>

class TypeCheck
{
    private:

    public:
        TypeCheck();
        bool IsOperator(char c);
        bool IsOperand(char c);
        bool IsFunction(const std::string& s);
        int Precedence(const std::string& op);
        ~TypeCheck();
        
};