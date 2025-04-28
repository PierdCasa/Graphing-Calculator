
#include "function.h"


int main()
{  
  Function a;
  a.GetRpn().Tokenize("2+3");
  a.GetRpn().print();
  return 0;
}