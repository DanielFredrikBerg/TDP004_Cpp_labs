#ifndef RESISTOR_H
#define RESISTOR_H

#include "component.h"

class Resistor : public Component
{
public:
  Resistor(int resistance);
  double update();

private:
  int resistance;
  double calc_voltage(double const next, double const previous);
  double calc_power(double const next, double const previous);
}

#endif
