#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "component.h"

class Capacitor : public Component
{
public:
  Capacitor(int capacitance);
  

private:
  int capacitance;
  
}

#endif
