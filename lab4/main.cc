#include <vector>
#include <iostream>
#include <iomanip>

#include "battery.h"
#include "capacitor.h"
#include "resistor.h"

std::string volt_curr_str(long unsigned int occ)
{
  std::stringstream str_stream;
  str_stream << std::right;
  std::string val;
  for (long unsigned int i = 1; i <= occ * 2; i++)
  {
    if (i % 2 == 0)
    {
      val = "Curr";
    }
    else
    {
      val = "Volt";
    }
    str_stream << std::setw(6) << val;
  }
  return str_stream.str();
} 

void simulate(std::vector<Component*> const& net, \
              int iterations, int text_rows, double interval)
{
  std::stringstream str_stream;
  str_stream << std::right << std::fixed;

  long unsigned int net_size = net.size();
  for (long unsigned int i = 0; i < net_size; i++)
  {
    str_stream << std::setw(12) << net[i] -> get_name();
  }

  str_stream << "\n" << volt_curr_str(net_size) << "\n";

  int row_print_time{iterations / text_rows};
  for (int i{1}; i <= iterations; i++)
  {
    for (long unsigned int k = 0; k < net_size; k++)
    {
      net[k] -> update(interval);
    }
    if (i % row_print_time == 0)
    {
      for (long unsigned int k = 0; k < net_size; k++)
      {
        str_stream << std::setw(6) << std::setprecision(2) 
                   << net[k] -> calc_voltage() << std::setw(6) 
                   << net[k] -> calc_current();
      }
      str_stream << "\n";
    }
  }

  std::cout << str_stream.str() << std::endl;
} 

void clear_net(std::vector<Component*> & net)
{
  for (Component* comp : net)
  {
    delete comp;
  }
  net.clear();
}

int main(int argc, char* argv[]) 
{
  if (argc != 5)
  {
    std::cerr << "Including the file name, there needs to be 5 arguments." 
              << std::endl;
    return 1;
  }

  int iterations{};
  int text_rows{};
  double interval{};
  double voltage{};

  try
  {
    iterations = std::stoi(argv[1]);
  }
  catch(std::invalid_argument& ia_error)
  {
    std::cerr << "first argument needs to be an int." << std::endl;
    return 2;
  }
  try
  {
    text_rows = std::stoi(argv[2]);
  }
  catch(std::invalid_argument& ia_error)
  {
    std::cerr << "second argument needs to be an int." << std::endl;
    return 3;
  }
  try
  {
    interval = std::stod(argv[3]);
  }
  catch(std::invalid_argument& ia_error)
  {
    std::cerr << "third argument needs to be a double." << std::endl;
    return 4;
  }
  try
  {
    voltage = std::stod(argv[4]);
  }
  catch(std::invalid_argument& ia_error)
  {
    std::cerr << "fourth argument needs to be a double." << std::endl;
    return 5;
  }
  
  // First circuit
  Connection p, n, r124, r23;
  std::vector<Component*> net;
  net.push_back(new Battery("Bat", voltage, p, n));
  net.push_back(new Resistor("R1",  6.0, p, r124));
  net.push_back(new Resistor("R2",  4.0, r124, r23));
  net.push_back(new Resistor("R3",  8.0, r23, n));
  net.push_back(new Resistor("R4",  12.0, r124, n));
  simulate(net, iterations, text_rows, interval);
  
  clear_net(net);

  // Second circuit
  Connection p2, n2, l2, r2;
  net.push_back(new Battery("Bat", voltage, p2, n2));
  net.push_back(new Resistor("R1",  150.0, p2, l2));
  net.push_back(new Resistor("R2",  50.0, p2, r2));
  net.push_back(new Resistor("R3",  100.0, l2, r2));
  net.push_back(new Resistor("R4",  300.0, l2, n2));
  net.push_back(new Resistor("R5",  250.0, r2, n2));
  simulate(net, iterations, text_rows, interval);
  
  clear_net(net);

  // Third circuit
  Connection p3, n3, l3, r3;
  net.push_back(new Battery("Bat", voltage, p3, n3));
  net.push_back(new Resistor("R1",  150.0, p3, l3));
  net.push_back(new Resistor("R2",  50.0, p3, r3));
  net.push_back(new Capacitor("C3",  1.0, l3, r3));
  net.push_back(new Resistor("R4",  300.0, l3, n3));
  net.push_back(new Capacitor("C5",  0.75, r3, n3));
  simulate(net, iterations, text_rows, interval);

  clear_net(net);

  return 0;
}
