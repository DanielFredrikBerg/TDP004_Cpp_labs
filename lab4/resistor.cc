#include "resistor.h"

/* Flyttar laddningspartiklar från sin mest positiva kopplingspunkt 
   till sin minst positiva kopplingspunkt */
Resistor::Resistor(std::string const& name, double value, \
				   Connection & positive, Connection & negative)
  : Component{name, positive, negative}, resistance{value}
{}

double Resistor::calc_current()
{
  return calc_voltage() / resistance;
}

void Resistor::update(double interval)
{
  double charge_flow{calc_current() * interval}; 
  move_charge(charge_flow);
}

