#ifndef RESISTOR_H
#define RESISTOR_H

#include "component.h"

class Resistor : public Component
{
public:
  Resistor(std::string const& name, double value, \
           Connection & positive, Connection & negative);

  void update(double interval) override;
  double calc_current() override;
  
private:
	double resistance;
};

#endif
