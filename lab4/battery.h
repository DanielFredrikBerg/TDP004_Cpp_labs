#ifndef BATTERY_H
#define BATTERY_H

#include "component.h"

class Battery : public Component
{
public:
  Battery(double voltage);
  double update();

private:
  int charge;
  double calc_voltage(double const next, double const previous);
  double calc_power(double const next, double const previous);
}


#endif
