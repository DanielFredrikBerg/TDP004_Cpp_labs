#include "capacitor.h"

Capacitor::Capacitor(std::string name, double value, Connection & positive, Connection & negative)
  : Component{name, value, positive, negative}
{}

void Capacitor::move_charge(double charge_flow)
{
  Component::move_charge(charge_flow);
  storage += charge_flow;
}

void Capacitor::update(double interval)
{
  double charge{value * (Component::calc_voltage() - storage) * interval};
  Capacitor::move_charge(charge);

}
