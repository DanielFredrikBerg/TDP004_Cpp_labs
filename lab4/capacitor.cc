#include "capacitor.h"

Capacitor::Capacitor(std::string const& name, double value,\
                     Connection & positive, Connection & negative)
  : Component{name, positive, negative}, capacitance{value}, storage{0}
{}


double Capacitor::calc_current()
{
  return capacitance * (calc_voltage() - storage);
}

void Capacitor::update(double interval)
{
  double charge_flow{calc_current() * interval};
  move_charge(charge_flow);
  storage += charge_flow;
}


