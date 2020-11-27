#include <iostream> 
#include <exception>
#include <algorithm> 
#include <iterator>
#include <iomanip>
#include <fstream>
#include <utility> 
#include <vector>
#include <cctype> 
#include <locale>
#include <map>

bool is_valid(std::string const& str)
{
   // words shorter than 3 characters are not valid
   if (str.length() < 3)
   {
      return false;
   }

   // words starting/ending with a '-' are not valid
   if (str[0] == '-' || str[str.length() - 1] == '-')
   {
      return false;
   }

   // words with two '-' in a row are not valid
   if (str.find("--") != std::string::npos)
   {
      return false;
   }

   // words that contain other characters than '-' or letters are not valid
   std::locale swe_loc("sv_SE.UTF-8");
   return std::all_of(str.begin(), str.end(), 
                      [&swe_loc](char c)
                      {return isalpha(c, swe_loc) || c == '-';});
}

std::string clean_word(std::string & str)
{
   // find index of first/last letter in the word
   auto first{str.find_first_not_of("\"'(")};
   auto last{str.find_last_not_of("!?;,:.\"')")};

   // adjust index for last letter in case it ends with 's
   if (str[last - 1] == '\'')
   {
      last -= 2;
   }
   return str.substr(first, last - first + 1);
}


void print_error(std::string const& error_msg)
{
   std::cerr << error_msg << std::endl;
   std::cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << std::endl;
}


int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      print_error("Error: No arguments given."); 
      return 1;
   }
   else if (argc < 3 || argv[2][0] != '-' || 
            (argv[2][1] != 'a' && argv[2][1] != 'f' && argv[2][1] != 'o'))
   {
      print_error("Error: Second argument missing or invalid.");
      return 2;
   }
   else if (argv[2][1] == 'o')
   {
      try
      {
         std::stoi(argv[3]);
      }
      catch (std::exception &)
      {
         print_error("Error: Third argument missing or invalid.");
         return 3;
      }
   }

   // open file
   std::ifstream in_stream;
   in_stream.open(argv[1]);
   if (!in_stream.is_open())
   {
      print_error("Error: Invalid file name.");
      return 4;
   }

   // read potential words from file
   std::vector<std::string> words;
   std::copy(std::istream_iterator<std::string>{in_stream}, 
             std::istream_iterator<std::string>{}, std::back_inserter(words));

   // clean potential words
   std::transform(words.begin(), words.end(), words.begin(), 
                  [](std::string & str) { return clean_word(str); });

   // validate clean words
   auto it = std::remove_if(words.begin(), words.end(), 
                            [](std::string const& str) {return !is_valid(str);});
   words.erase(it, words.end());

   // convert valid words to lowercase
   std::transform(words.begin(), words.end(), words.begin(), 
                  [](std::string & str) 
                  { 
                     std::transform(str.begin(), str.end(), str.begin(), 
                                    [](char c){return std::tolower(c);});
                     return str;
                  });


   // print valid words in alphabetical order with count
   if (argv[2][1] == 'a')
   {
      // copy words into a map<string, int>
      std::map<std::string, int> words_map;
      transform(words.begin(), words.end(), inserter(words_map, words_map.begin()),
                [&words] (std::string const& str)
                {
                   return make_pair(str, std::count(words.begin(), words.end(), str));
                });

      // clear vector
      words.clear();

      // copy words + count from map to vector
      transform(words_map.begin(), words_map.end(), back_inserter(words), 
                [&words_map] (std::pair<std::string, int> const& p) 
                {
                   return p.first + " " + std::to_string(p.second);
                });

      // print vector with words + count
      std::copy(words.begin(), words.end(), 
                std::ostream_iterator<std::string>(std::cout, "\n"));
   } 
   else if (argv[2][1] == 'f')
   {
      // create vector of unique words
      std::sort(words.begin(), words.end());
      std::vector<std::string> unique_words;
      std::unique_copy(words.begin(), words.end(), std::back_inserter(unique_words));

      // create vector of word count
      std::vector<int> word_count;
      std::transform(unique_words.begin(), unique_words.end(), 
                     std::back_inserter(word_count), 
                     [&words](std::string & str) 
                     { return std::count(words.begin(), words.end(), str); });
		
      // merge into a vector of pairs
      std::vector<std::pair<std::string, int>> pairs;
      std::transform(unique_words.begin(), unique_words.end(), word_count.begin(), 
                     std::back_inserter(pairs),
                     [](std::string & str, int cnt) 
                     { return std::make_pair(str, cnt); });


      // sort vector<string, int> by int 
      std::sort(pairs.begin(), pairs.end(), [](std::pair<std::string,int> l, \
                                               std::pair<std::string,int> r) 
                                            { return l.second > r.second; }); 

      // print
      std::transform(pairs.begin(), pairs.end(), 
                     std::ostream_iterator<std::string>(std::cout, "\n" ), 
                     [](std::pair<std::string, int> & p) 
                     { return p.first + " " + std::to_string(p.second); } );
   } 
   else if (argv[2][1] == 'o')
   {
      std::stringstream str_stream;
      unsigned long int length{0};
      unsigned long int max_length{std::stoul(argv[3])};

      auto copy_to_sstream = [&length, &max_length, &str_stream](std::string str) 
                             {
                                if (length != 0 
                                    && length + str.length() + 1 >= max_length)
                                {
                                   str_stream << "\n";
                                   length = 0;
                                }
                                else if (length > 0)
                                {
                                   str_stream << " ";
                                   length++;
                                }
                                str_stream << str;
                                length += str.length();
                             };

      std::for_each(words.begin(), words.end(), copy_to_sstream);

      std::cout << str_stream.str() << std::endl; 

   }
 

}
