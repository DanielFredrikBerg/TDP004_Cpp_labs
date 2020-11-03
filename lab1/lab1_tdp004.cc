#include <iomanip>
#include <iostream>

using namespace std;

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
  float f_price{-1};
  float s_price{-1};
  float step{-1};
  float vat{-1};

  cout << "INMATNINGSDEL\n============" << endl;
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
      cout << "FEL: Sista pris måste vara större eller lika stort som första pris" << endl;
    }
  }
  while(step + 0.000001 < 0.01)
  {
    cout << "Mata in steglängd: ";
    cin >> step;
    if (step + 0.000001 < 0.01)
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

  //cout << "MOMSTABELLEN\n" << setfill('=') << setw(12) << "" << endl;
  cout << "\nMOMSTABELLEN\n============" << endl;
  cout << setw(12) << right << "Pris" << setw(17) << "Moms" << setw(20)
       << "Pris med moms" << endl;
  cout << setfill('-') << setw(49) << "" << endl;
  
  while(f_price <= s_price)
  {
    cout << fixed << setprecision(2) << setfill(' ') << setw(12) << right << f_price
	 << setw(17) << calc_vat(f_price, vat) << setw(20) << calc_price(f_price, vat) << endl;
    f_price += step;
  }
  return 0;
}
