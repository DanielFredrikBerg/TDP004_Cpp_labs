#include <vector>
#include <iostream>
#include <iomanip>

#include "battery.h"
#include "capacitor.h"
#include "resistor.h"

std::stringstream volt_curr_str(long unsigned int occ)
{
  std::stringstream str_stream;
  std::string val;
  int w{0};
  for (long unsigned int i = 1; i <= occ * 2; i++)
  {
    if (i % 2 == 0)
    {
      val = "Curr";
      w = 6;
    }
    else
    {
      val = "Volt";
      w = 6;
    }
    str_stream << std::right << std::setw(w) << val;
  }
  return str_stream;
} 

void simulate(std::vector<Component*> & net, int iterations, int text_rows, double interval)
{
  std::stringstream str_stream;
  long unsigned int net_size = net.size();
  for (long unsigned int i = 0; i < net_size; i++)
  {
    str_stream << std::right  << std::setw(12) << net[i] -> get_name();
  }
  str_stream << "\n" << volt_curr_str(net_size).str() << "\n";
  int counter{0};
  int times{1};
  int row_print_time{iterations / text_rows};
  while (counter < iterations)
  {
    for (long unsigned int k = 0; k < net_size; k++)
    {
      net[k] -> update(interval);
    }
    if (counter % row_print_time == 0)
    {
      times++;
      // Ska lägga till en rad i str.
      for (long unsigned int k = 0; k < net_size; k++)
      {
        str_stream << std::right  << std::setw(6) << std::fixed 
                   << std::setprecision(2) << std::setfill(' ') 
                   << net[k] -> calc_voltage() << std::setw(6) 
                   << net[k] -> calc_current();
      }
      str_stream << "\n";
    }
    counter++;
  }

  std::cout << str_stream.str() << std::endl;


  //std::cout << net[0] << iterations << text_rows << interval << std::endl;
} 

int main() 
{
  // First circuit
  Connection p, n;
  std::vector<Component*> net;
  net.push_back(new Battery("Bat", 24.0, p, n));
  net.push_back(new Resistor("R1",  6.0, p, n));
  net.push_back(new Resistor("R2",  4.0, p, n));
  net.push_back(new Resistor("R3",  8.0, p, n));
  net.push_back(new Resistor("R4",  12.0, p, n));
  simulate(net, 200000, 10, 0.01);
  
  
  // Second circuit
  Connection p2, n2;
  std::vector<Component*> net2;
  net2.push_back(new Battery("Bat", 24.0, p2, n2));
  net2.push_back(new Resistor("R1",  150.0, p2, n2));
  net2.push_back(new Resistor("R2",  50.0, p2, n2));
  net2.push_back(new Resistor("R3",  100.0, p2, n2));
  net2.push_back(new Resistor("R4",  300.0, p2, n2));
  net2.push_back(new Resistor("R5",  250.0, p2, n2));
  simulate(net2, 200000, 10, 0.01);
  
  // Third circuit
  Connection p3, n3;
  std::vector<Component*> net3;
  net3.push_back(new Battery("Bat", 24.0, p3, n3));
  net3.push_back(new Resistor("R1",  150.0, p3, n3));
  net3.push_back(new Resistor("R2",  50.0, p3, n3));
  net3.push_back(new Capacitor("C3",  1.0, p3, n3));
  net3.push_back(new Resistor("R4",  300.0, p3, n3));
  net3.push_back(new Capacitor("C5",  0.75, p3, n3));
  simulate(net3, 200000, 10, 0.01);

  return 0;
}
