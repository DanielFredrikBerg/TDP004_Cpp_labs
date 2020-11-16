#include "capacitor.h"

Capacitor::Capacitor(std::string name, double value, Connection & positive, Connection & negative)
  : Component{name, value, positive, negative}
{}

void Capacitor::update(double interval)
{
  double charge_flow{value * (Component::calc_voltage() - storage) * interval};
  

}
