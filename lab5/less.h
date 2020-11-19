#ifndef LESS_H
#define LESS_H

template <typename T>
class Less
{
  public:
  bool compare(T const& arg_one, T const& arg_two);
  bool compare(T const& arg_one, T const& arg_two, T const& distance);

  private:
};

#include "less.tcc"

#endif
