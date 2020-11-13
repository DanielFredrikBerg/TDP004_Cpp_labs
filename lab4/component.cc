#include "component.h"



Component(std::string name, double value, Connection positive, Connection negative)
  : name{name}, value{value}, positive{positive}, negative{negative}
{}



double Component::calc_voltage()
{
  return std::abs(positive.charge - negative.charge); //överlagra - operatorn istället?
}
  


