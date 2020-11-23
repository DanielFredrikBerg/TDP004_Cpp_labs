#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

//#include "word_list.h"

int main(int argc, char* argv[])
{
  // Kolla med find_first_of efter första char.
  // Kolla bakifrån efter första char. Kolla om det char
  // är ett s. Ifall s kolla om char innan är '. Om det är
  // ignorera och fortsätt leta efter nästa char bakifrån.
  // Ta substring mellan dessa tecken och lägg in som potentiellt ord.
  string start_trash_str{"\"('"};
  string end_trash_str{"!?);,.:\"'"};
  bool char_start = false;

  if (argc > 1)
  {
    std::string filename = argv[1];
    if(std::ifstream ifs{filename, std::ios::binary | std::ios::ate})
    {
      std::stringstream str_stream;

      auto size = ifs.tellg();
      std::cout << "result of size: " << size << std::endl;
      std::string str(size, '\0');
      ifs.seekg(0);
      if( ifs.read(&str[0], size))
      {
        str_stream << str;
        std::cout << str << std::endl;
      }

      
    }
    else 
    {
      std::cout << "Too few arguments, please add .txt file to check."
                << std::endl;
    }  
  }
}
