#include "resistor.h"

/* Flyttar laddningspartiklar från sin mest positiva kopplingspunkt 
   till sin minst positiva kopplingspunkt */
Resistor(std::string name, double value, Connection positive, Connection negative)
  : Component{name, value, positive, negative}
{}

void Component::update(double interval)
{
  double charge_flow{Component::calc_voltage() / value * interval}; 
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

