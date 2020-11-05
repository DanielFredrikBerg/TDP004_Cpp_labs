#include <iostream>
#include <string>
using namespace std;

int main()
{
   cout << "Skriv in ett ord och ett nummer: ";
   //Detta för att flush:a och få cursorn
                  //att stanna kvar på samma rad
   string line{};
   string word{};
   int number{};
   char letter{};
   cin >> word;
   cin >> number;
   cin >> letter;
   cout << word << number << letter << endl;
   cout << "skriv in din rad här: ";
   string s;
   getline(cin, s);
   line = std::stoi(s);
   cout << "Din rad var följande: " << line << endl;
   int i = {3.5};
   return 0;
}


