#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "component.h"

class Capacitor : public Component
{
public:
  Capacitor(int capacitance);
  double update();

private:
  int capacitance;
  double calc_voltage(double const next, double const previous);
  double calc_power(double const next, double const previous);
}

#endif
