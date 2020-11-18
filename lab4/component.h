#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

struct Connection
{
  double charge{};
};

class Component
{
public:
  Component(std::string name, double value, \
            Connection & positive, Connection & negative);
  virtual ~Component() = default;
  std::string get_name();
  virtual void update(double interval) = 0;
  virtual double calc_current() = 0;  
  double calc_voltage();
  void move_charge(double charge_flow);

  
protected:
  std::string name;
  double value;
  Connection & positive;
  Connection & negative;

private:
  
};






#endif
