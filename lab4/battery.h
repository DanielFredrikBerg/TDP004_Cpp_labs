#ifndef BATTERY_H
#define BATTERY_H

#include "component.h"

class Battery : public Component
{
public:
  Battery(std::string name, double value, Connection & positive, Connection & negative);
  void update(double interval) override;

private:
  // int charge;
  // double calc_voltage(double const next, double const previous);
  // double calc_power(double const next, double const previous);
};


#endif
