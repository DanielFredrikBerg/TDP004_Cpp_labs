#include "battery.h"

Battery::Battery(std::string name, double value, Connection & positive, Connection & negative)
  : Component{name, value, positive, negative}
{}

void Battery::update(double interval)
{
  positive.charge = value * interval;
  negative.charge = 0;
}
