#include "battery.h"

Battery::Battery(std::string const& name, double value, \
                 Connection & positive, Connection & negative)
  : Component{name, positive, negative}, charge{value}
{}

void Battery::update(double)
{
  positive.charge = charge;
  negative.charge = 0;
}

double Battery::calc_current()
{
  return 0;
}
