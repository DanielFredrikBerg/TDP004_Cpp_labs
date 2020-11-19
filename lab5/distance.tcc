#ifndef DISTANCE_H
#define DISTANCE_H

template <typename T>
class Distance
{
public:
  Distance(T);

private:
  T center{};
};

#include "distance.tcc"
#endif
