#include "capacitor.h"

Capacitor::Capacitor(std::string name, double value, Connection & positive, Connection & negative)
  : Component{name, value, positive, negative}
{}

void Capacitor::move_charge(double charge_flow)
{
  Component::move_charge(charge_flow);
  storage += charge_flow;
}

double Capacitor::calc_current()
{
  return value * (Component::calc_voltage() - storage);
}

void Capacitor::update(double interval)
{
  double charge_flow{calc_current() * interval};
  move_charge(charge_flow);
}


