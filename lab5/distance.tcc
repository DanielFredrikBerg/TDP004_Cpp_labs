#ifndef DISTANCE_H
#define DISTANCE_H

template <typename T>
class Distance
{
public:
   Distance(T);  
   bool compare(T const& arg_one, T const& arg_two, T const& distance);

private:
  T center{};
};

#include "distance.tcc"
#endif
