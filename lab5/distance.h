#ifndef DISTANCE_H
#define DISTANCE_H


template <typedef T>
class Distance
{
public:
  Distance(T);

private:
  T center;
}

#include "distance.tcc"

#endif
