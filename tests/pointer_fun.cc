#include <iostream>
#include <stdio.h>

int main() 
{
   std::string* pointer{ new std::string{"A string"} };

   std::cout << pointer << std::endl;
   std::cout << (*pointer).substr(0,3) << "\n";
   std::cout << pointer -> substr(0,3) << std::endl;

   delete pointer;
}
