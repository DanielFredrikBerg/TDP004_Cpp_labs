#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "component.h"

class Capacitor : public Component
{
public:
  Capacitor(std::string const& name, double value, \
            Connection & positive, Connection & negative);

  void update(double interval) override;
  double calc_current() override;
  
private:
  double capacitance;
  double storage;
};

#endif
