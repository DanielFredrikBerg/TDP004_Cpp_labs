#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

// Komplettering: Alla parametrar av klasstyp ska skickas in som const& om de inte ändras 
//                och som referenser om de ändras.

// Komplettering: Varje subklass ska ha sin egen speciella datamedlem. Det kan framstå som 
//                att denna 'special value' kan vara i basklassen eftersom att den förekommer 
//                i alla subklasser men dem används annorlunda och betyder olika saker.
//                I och med att dem betyder olika saker för olika subklasser ska dem ligga i sin respektive klass.
//                Detta syftar till 'double value'.

// Komplettering: Programmet läcker minne för körningen: ./a.out 200000 10 0.01 24

// Komplettering: Upprepa inte manipulatorer med permanent effekt. 
// Kommentar: Superbra att ni kör med en stringstream i main::simulate!!! :D :D

struct Connection
{
  double charge{};
};

class Component
{
public:
  Component(std::string name, double value, \
            Connection & positive, Connection & negative);
  virtual ~Component() = default;
  std::string get_name();
  virtual void update(double interval) = 0;
  virtual double calc_current() = 0;  
  double calc_voltage();
  void move_charge(double charge_flow);

  
protected:
  std::string name;
  double value;
  Connection & positive;
  Connection & negative;

private:
  
};






#endif
