#include "component.h"


Component::Component(std::string name, double value, Connection & positive, Connection & negative)
  : name{name}, value{value}, positive{positive}, negative{negative}
{}

std::string Component::get_name()
{
  return name;
}

double Component::calc_voltage()
{
  if (positive.charge > negative.charge)
  {
    return std::abs(positive.charge - negative.charge);
  }
  return std::abs(negative.charge - positive.charge); 
}

void Component::move_charge(double const charge_flow)
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

  


