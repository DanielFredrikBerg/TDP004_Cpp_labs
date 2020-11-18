#include "resistor.h"

/* Flyttar laddningspartiklar från sin mest positiva kopplingspunkt 
   till sin minst positiva kopplingspunkt */
Resistor::Resistor(std::string name, double value,\
                   Connection & positive, Connection & negative)
  : Component{name, value, positive, negative}
{}

double Resistor::calc_current()
{
  return calc_voltage() / value;
}

void Resistor::update(double interval)
{
  double charge_flow{calc_current() * interval}; 
  move_charge(charge_flow);
}

