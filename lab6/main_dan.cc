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

std::string extract_alpha_subset(std::string& word)
{
   std::locale swe_loc("sv_SE.UTF-8");
   auto found{std::find_if( word.begin(), word.end(), [&swe_loc](char c) { return std::isalpha(c, swe_loc); } )};
   if (found != word.end())
   {
      long int first_index{found - word.begin()};
      auto last_index{word.find_last_not_of( "!?;,:.\"')" )};
      if (word.at(last_index - 1) == '\'')
      {
         last_index = last_index - 2;
      }
      return word.substr(first_index, last_index - first_index + 1);  
   }
   return "";
}

bool validate(std::string& s)
{ 
   if (s.size() < 3)
   {
      return false;
   }
   if(s.find("--") != std::string::npos)
   {
      return false;
   }
   if( s.find_last_of( "!?;,:.\"')" ) != std::string::npos )
   {
      return false;
   }
   return true;
}


int main(int argc, char* argv[])
{
   if (argc > 1)
   {
      
      std::string filename = argv[1];
      if(std::ifstream ifs{filename, std::ios::in})
      {
         std::vector<std::string> words{ std::istream_iterator<std::string>{ifs}, std::istream_iterator<std::string>{} };
         std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

         
         //ta bort skr�p fram och bak
         std::vector<std::string> less_trash; 
         std::vector<std::string> less_t; 
         
         //std::cout << extract_alpha_subset(s) << std::endl; 
         
         std::transform(words.begin(), words.end(), std::back_inserter(less_trash),
                        [](std::string s) -> auto {return extract_alpha_subset(s);});

         std::transform(less_trash.begin(), less_trash.end(), std::back_inserter(less_t),
                        [](std::string s) -> std::string { if(validate(s)) {return s; } else {return "";}} );
         
         
         std::copy(less_t.begin(), less_t.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
         
      }
      else
      {
         std::cout << "Error: Second argument missing or invalid.\nUsage: ./a.out FILE [-a] [-f] [-o N]" << std::endl;
      }
      
   }
   else
   {
      std::cout << "Error: No arguments given.\nUsage: a.out FILE [-a] [-f] [-o N]" << std::endl;
      return -1;
   }
   return 0;
}
