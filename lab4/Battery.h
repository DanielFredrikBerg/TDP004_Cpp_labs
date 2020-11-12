#ifndef BATTERY_H
#define BATTERY_H
class Battery : public Component
{
public:
  Battery(double voltage);
  

private:
  int charge;
}


#endif
