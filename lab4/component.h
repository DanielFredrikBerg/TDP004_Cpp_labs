#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "connection.h"

class Component
{
public:
  Component();
  virtual ~Component();
  virtual void update(double interval) = 0;
  double calc_voltage();
  virtual double charge_to_move() = 0;

protected:
  std::string name;
  double value;
  Connection positive;
  Connection negative;

private:
  
};






#endif
