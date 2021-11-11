#include <iomanip>
#include <iostream>
#include <string>

// Ser fint ut! Bra jobbat, men jag har några små kompletteringar ni bör fixa.

// Komplettering: 4-9, antar att ni har utkommenterad kod för att visa att det
//                     går att göra med std::fill('=') också, men ta bort utkommenterad
//                     kod i framtiden! :D I den här uppgiften godkänner vi båda
//                     alternativen ni skrivit så välj en.

// Komplettering: 1-4, radbrytning

using namespace std;

// Kommentar: Fina funktioner!
float calc_vat(float base, float vat_percentage)
{
  return base / 100 * vat_percentage;
}


float calc_price(float base_price, float vat)
{
  return base_price + calc_vat(base_price, vat);
}


int main()
{
  // Kommentar: 1-9, värt att kolla på denna punkt till framtiden.
  //            Tycker det är ok nu men vill bara att ni ska ha koll
  //            på den punkten i rättningsprotokollet.
  float f_price{-1};
  float s_price{-1};
  float step{-1};
  float vat{-1};
  string input{"INMATNINGSDEL"};
  cout << input << "\n" << setfill('=') << setw(input.size()) << '='  << endl; //fill f�re setw, m�ste vara n�got efter fill
  while(f_price < 0)
  {
    cout << "Mata in första pris: ";
    cin >> f_price;
    if (f_price < 0)
    {
      cout << "FEL: Första pris måste vara minst 0 (noll) kronor" << endl;
    }
  }

  while(s_price < f_price)
  {
    cout << "Mata in sista pris: ";
    cin >> s_price;
    if (s_price < f_price)
    {
      cout << "FEL: Sista pris måste vara större eller lika stort som första pris"
	   << endl;
    }
  }
  // Komplettering: Varför adderar ni 0.000001? Varför plus? Kanske minus?
  //                Hur vet ni om ni får 0.00001 för mycket eller för lite?

  while(step < 0.01)
  {
    cout << "Mata in steglängd: ";
    cin >> step;
    if (step < 0.01)
    {
      cout << "FEL: steglängd måste vara minst 0.01" << endl;
    }
  }

  while(vat < 0)
  {
    cout << "Mata in momsprocent: ";
    cin >> vat;
    if (vat <= 0)
    {
      cout << "FEL: momsprocent måste vara positiv" << endl;
    }
  }

  
  cout << "\nMOMSTABELLEN\n============" << endl;
  // Kommentar: Bra radbrytning!
  cout << setw(12) << right << "Pris" << setw(17) << "Moms" << setw(20)
       << "Pris med moms" << endl;
  cout << setfill('-') << setw(49) << "" << endl;
  
  while(f_price <= s_price + 0.001)
  {
    cout << fixed << setprecision(2) << setfill(' ') << setw(12)
	 << right << f_price << setw(17) << calc_vat(f_price, vat)
	 << setw(20) << calc_price(f_price, vat) << endl;
    f_price += step;
  }
  return 0;
}
