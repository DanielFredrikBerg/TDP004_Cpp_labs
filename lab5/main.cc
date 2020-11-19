#include <iostream>

#include "less.h"


int main(int argc, char* argv[]) 
{
  
  std::cout << Less<T>::compare(argv[1], argv[2]) << argc << std::endl;
  return 0;
}
