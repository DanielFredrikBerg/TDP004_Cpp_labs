#include <iostream>
#include <string>
using namespace std;

int main()
{
   cout << "Skriv in ett ord och ett nummer: ";
   //Detta f�r att flush:a och f� cursorn
                  //att stanna kvar p� samma rad
   string line{};
   string word{};
   int number{};
   char letter{};
   cin >> word;
   cin >> number;
   cin >> letter;
   cout << word << number << letter << endl;
   cout << "skriv in din rad h�r: ";
   string s;
   getline(cin, s);
   line = std::stoi(s);
   cout << "Din rad var f�ljande: " << line << endl;
   int i = {3.5};
   return 0;
}


