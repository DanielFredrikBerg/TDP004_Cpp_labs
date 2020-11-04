#include <iostream>
#include <iomanip>

using namespace std;

/* Komplettering:
 * När jag testar ert program så blir det ett fel vid 
 * "Skriv in en hel rad med text". Efter att jag har 
 * skrivit in texten så krävs ett extra enter för att
 * få programmet att fortsätta.
*/

// Komplettering: 2-6.
// Kommentar: 1-4, se rad 91.


int main()
{
  int integer{};
  char char_var{};
  string string_var{};
  // Komplettering: Dålig namngivning.
  double double_num{};
  
  
  cout << "Skriv in ett heltal: ";
  cin >> integer;
  cout << "Du skrev in talet: " << integer << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in fem heltal: ";
  cin >> integer;
  cout << "Du skrev in talen: " << integer << ", ";
  cin >> integer;
  cout << integer << ", ";
  cin >> integer;
  cout << integer << ", ";
  cin >> integer;
  cout << integer << ", ";
  cin >> integer;
  cout << integer << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett flyttal: ";
  cin >> double_num;
  cout << "Du skrev in flyttalet: " << fixed << setprecision(3)
       << double_num << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett heltal och ett flyttal: ";
  cin >> integer >> double_num;
  cout << "Du skrev in heltalet:" << setw(9) << integer
       << "\nDu skrev in flyttalet:" << setw(8) << double_num << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett flyttal och ett heltal: ";
  cin >> double_num >> integer;
  cout << "Du skrev in heltalet:" << setw(9) << setfill('-') << integer
       << "\nDu skrev in flyttalet:" << setw(8) << double_num << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett tecken: ";
  cin >> char_var;
  cout << "Du skrev in tecknet: " << char_var << endl;
  cin.ignore(100, '\n');
    
  cout << "\nSkriv in en sträng: ";
  cin >> string_var;
  cout << "Strängen '" << string_var << "' har " << string_var.size()
       << " tecken." << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett heltal och en sträng: ";
  cin >> integer >> string_var;
  cout << "Du skrev in talet |" << integer << "| och strängen |" << string_var
       << "|." << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in en sträng och ett flyttal: ";
  cin >> string_var >> double_num;
  cout << "Du skrev in \"" << double_num << "\" och \"" << string_var
       << "\"." << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in en hel rad med text: ";
  getline(cin, string_var);
  cout << "Du skrev in textraden: '" << string_var << "'" << endl;
  
  cout << "\nSkriv in en textrad som slutar med ett negativt heltal: ";
  getline(cin, string_var, '-');
  cin >> integer;
  integer *= -1;
  // Kommentar: 1-4
  cout << "Du skrev in textraden: '" << string_var << "' och heltalet '"
       << integer << "'" << endl;

  return 0;
    
}
