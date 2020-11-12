#ifndef RESISTOR_H
#define RESISTOR_H

#include "component.h"

class Resistor : public Component
{
public:
  Resistor(int resistance);

private:
  int resistance;

}

#endif
