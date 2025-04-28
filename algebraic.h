#include "function.h"

class Algebraic:public Function 
{
  private:
    double value_of_x;
    double evaluation;
  public:
    void SetX(double x)
    {
      value_of_x=x;
    }

};