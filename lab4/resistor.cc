#include "resistor.h"

/* Flyttar laddningspartiklar från sin mest positiva kopplingspunkt 
   till sin minst positiva kopplingspunkt */
Resistor::Resistor(std::string name, double value, Connection & positive, Connection & negative)
  : Component{name, value, positive, negative}
{}

void Resistor::update(double interval)
{
  double charge_flow{Component::calc_voltage() / value * interval}; 
  Component::move_charge(charge_flow);
}

