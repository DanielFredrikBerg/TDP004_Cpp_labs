#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "connection.h"

class Component
{
public:
  Component(std::string name, double value, Connection & positive, Connection & negative);
  virtual ~Component() = default;
  virtual void update(double interval);
  double calc_voltage();
  virtual void move_charge(double charge_flow);

protected:
  std::string name;
  double value;
  Connection & positive;
  Connection & negative;

private:
  
};






#endif
