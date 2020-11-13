#ifndef RESISTOR_H
#define RESISTOR_H

#include "component.h"

class Resistor : public Component
{
public:
  Resistor(std::string name, double value, Connection positive, Connection negative);
  void Component::update(double interval);
  //double Component::calc_current();
  //int get_resistance() const;
  
private:
  //int resistance;
};

#endif
