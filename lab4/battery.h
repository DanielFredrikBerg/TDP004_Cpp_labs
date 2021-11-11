#ifndef BATTERY_H
#define BATTERY_H

#include "component.h"

class Battery : public Component
{
public:
  Battery(std::string const& name, double value, \
          Connection & positive, Connection & negative);

  void update(double interval) override;
  double calc_current() override;

private:
	double charge;
};


#endif
