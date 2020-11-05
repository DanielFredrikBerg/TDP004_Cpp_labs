#include <iostream>
#include <iomanip>

using namespace std;

// Static example
int incrementer()
{
   static int integer = 0;
   return integer++;
}

int main()
{
   int ival = 1024;
   int &refVal = ival;
   refVal = 2;
   std::cout << ival << std::endl;
   
   ival = 42;
   int* p = &ival;
   cout << p << endl;
   cout << *p << endl;

   for (int counter = 0; counter != 10; counter++)
   {
      cout << incrementer() << endl;
   }

}
