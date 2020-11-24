#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>



//#include "word_list.h"

int main(int argc, char* argv[])
{
  // Kolla med find_first_of efter första char.
  // Kolla bakifrån efter första char. Kolla om det char
  // är ett s. Ifall s kolla om char innan är '. Om det är
  // ignorera och fortsätt leta efter nästa char bakifrån.
  // Ta substring mellan dessa tecken och lägg in som potentiellt ord.
   //std::string start_trash_str{"\"('"};
   //std::string end_trash_str{"!?);,.:\"'"};
   //bool char_start = false;

  if (argc > 1)
  {
     std::vector<std::string> args{argv, argv + argc};
     for (std::string word : args)
     {
        std::cout << word << std::endl;
     }
     
// Ta reda p� exakt vad denna g�r:
     std::vector<std::string> vs {istream_iterator<std::string> {ifs}, istream_iterator<std::string>{} }
     
    std::string filename = argv[1];
    if(std::ifstream ifs{filename, std::ios::binary | std::ios::ate})
    {
       
    }
    //   std::stringstream str_stream;

    //   auto size = ifs.tellg();
    //   std::string str(size, '\0');
    //   std::vector<std::string> s{};
    //   ifs.seekg(0);
    //   if (ifs.read(&str[0], size))
    //   {
    //      str_stream << str;
    //      std::copy(std::begin(str_stream), std::end(str_stream), std::back_inserter(s));
    //   }

      
    //   std::cout << "result of size: " << size << std::endl;
    // }
    // else 
    // {
    //   std::cout << "Too few arguments, please add .txt file to check."
    //             << std::endl;
    // }  
  }
}
