#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
public:
   // uppg1
   int wheels;
   int top_speed;
   void drive(point const& A, point const& B);

// uppg1
private:
   struct Point
   {
      int x;
      int y;
   }

};

#endif
