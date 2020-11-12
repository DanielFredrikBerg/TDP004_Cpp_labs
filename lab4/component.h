#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
  Component();
  double next;
  double previous;
  string name;
  virtual double update() const = 0;

private:
  virtual double calc_voltage(double const next, double const previous);
  virtual double calc_power(double const next, double const previous);
}






#endif
