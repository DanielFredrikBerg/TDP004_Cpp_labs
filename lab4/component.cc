#include "component.h"


Component::Component(std::string const& name, \
                     Connection & positive, Connection & negative)
  : name{name}, positive{positive}, negative{negative}
{}

std::string Component::get_name()
{
  return name;
}

double Component::calc_voltage()
{
  return std::abs(positive.charge - negative.charge);
}

void Component::move_charge(double charge_flow)
{
  if (positive.charge > negative.charge)
  {
    positive.charge -= charge_flow;
    negative.charge += charge_flow;
  }
  else
  {
    positive.charge += charge_flow;
    negative.charge -= charge_flow;
  }
}

  


