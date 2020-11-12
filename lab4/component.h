#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
  Component();
  int plus_side;
  int minus_side;
  string name;
  virtual double update(double const value) const = 0;

private:

}






#endif
