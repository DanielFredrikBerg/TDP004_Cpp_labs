#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "component.h"

class Capacitor : public Component
{
public:
  Capacitor(std::string name, double value, Connection & positive, Connection & negative);

  void update(double interval) override;
  void move_charge(double charge_flow) override;

private:
  double storage;
};

#endif
