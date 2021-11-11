#ifndef DISTANCE_H
#define DISTANCE_H

template <typename T>
class Distance
{
public:
  Distance(T const& center);  
  bool compare(T const& arg_one, T const& arg_two);

private:
  T center{};
};

#include "distance.tcc"
#endif
