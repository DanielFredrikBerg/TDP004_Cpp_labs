#include <iostream>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <locale>
#include <set>

std::string extract_alpha_subset(std::string word)
{
   std::locale swe_loc("sv_SE.UTF-8");
   auto found = std::find_if( word.begin(), word.end(), [swe_loc](char c) { return std::isalpha(c, swe_loc); } );
   if (found != word.end())
   {
      long int first_index{found - word.begin()};
      auto found_rev = std::find_if( word.rbegin(), word.rend(), [swe_loc](char c) { return std::isalpha(c, swe_loc); } );
      if (found_rev != word.rend())
      {
         long unsigned int second_index{found_rev - word.rbegin() + word.size()};
         std::cout << "second find: " << *found_rev << std::endl;
         return "substring( " + std::to_string(first_index) + ", " + std::to_string(second_index) + " );     "
            + word.substr( first_index, second_index ); 
         //return word.substr( first_index, second_index );
      }
   }
   return "";
}


//#include "word_list.h"

int main(int argc, char* argv[])
{
   if (argc > 1)
   {
           
// Ta reda på exakt vad denna gör:
      
      std::string filename = argv[1];
      if(std::ifstream ifs{filename, std::ios::in})
      {
         std::vector<std::string> words{ std::istream_iterator<std::string>{ifs}, std::istream_iterator<std::string>{} };
         std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

         
         //ta bort skräp fram och bak
         std::vector<std::string> less_trash; 

         //s.erase(std::remove_if(s.begin(), find(), [swe_loc](char c) {return !std::isalpha(c, swe_loc); } ), s.end() );
            
         for (std::string s : words)
         {
            std::cout << extract_alpha_subset(s) << std::endl; 
         }
         
         

         std::copy(less_trash.begin(), less_trash.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
         //std::transform(words.begin(), words.end(), std::back_inserter(less_trash),
         //                [swe_loc](std::string s) -> auto {return });
      }
      
   }
   return 0;
}
