#include <iostream>
#include <iomanip>

using namespace std;



int main()
{
  int integer{};
  char chr{};
  string str{};
  double db{};
  
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
  cin >> db;
  cout << "Du skrev in flyttalet: " << fixed << setprecision(3) << db << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett heltal och ett flyttal: ";
  cin >> integer >> db;
  cout << "Du skrev in heltalet:" << setw(9) << integer
       << "\nDu skrev in flyttalet:" << setw(8) << db << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett flyttal och ett heltal: ";
  cin >> db >> integer;
  cout << "Du skrev in heltalet:" << setw(9) << setfill('-') << integer
       << "\nDu skrev in flyttalet:" << setw(8) << db << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett tecken: ";
  cin >> chr;
  cout << "Du skrev in tecknet: " << chr << endl;
  cin.ignore(100, '\n');
    
  cout << "\nSkriv in en sträng: ";
  cin >> str;
  cout << "Strängen '" << str << "' har " << str.size() << " tecken." << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in ett heltal och en sträng: ";
  cin >> integer >> str;
  cout << "Du skrev in talet |" << integer << "| och strängen |" << str
       << "|." << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in en sträng och ett flyttal: ";
  cin >> str >> db;
  cout << "Du skrev in \"" << db << "\" och \"" << str << "\"." << endl;
  cin.ignore(100, '\n');

  cout << "\nSkriv in en hel rad med text: ";
  getline(cin, str);
  cout << "Du skrev in textraden: '" << str << "'";
  cin.ignore(100, '\n');

  cout << "\nSkriv in en textrad som slutar med ett negativt heltal: ";
  getline(cin, str, '-');
  cin >> integer;
  integer *= -1;
  cout << "Du skrev in textraden: '" << str << "' och heltalet '" << integer << "'"
       << endl;
    
}
