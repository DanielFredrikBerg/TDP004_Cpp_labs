#include "battery.h"

Battery::Battery(std::string name, double value, \
                 Connection & positive, Connection & negative)
  : Component{name, value, positive, negative}
{}

void Battery::update(double)
{
  positive.charge = value;
  negative.charge = 0;
}

double Battery::calc_current()
{
  return 0;
}
