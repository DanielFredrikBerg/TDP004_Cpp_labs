#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "component.h"

class Capacitor : public Component
{
public:
  Capacitor(std::string name, double value, Connection & positive, Connection & negative);
  void update(double interval) override;
  

private:
  double storage;
};

#endif
