#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include <vector>
#include <initializer_list>
#include <ostream>

#include "less.h"

template <typename T, typename comp>
class sorted_array
{

public:
  sorted_array() = default;
  sorted_array(std::initializer_list<T> list); 
  sorted_array(std::initializer_list<T> list, comp comparator); 
  
  void insert(T value);
  T erase(int index);
  
  T & operator[](int index);
  T operator[](int index) const;
  
  T & at(int index);
  T at(int index) const;
  
  int size() const;
  
private:
  std::vector<T> data{};
  Less<T> comparator{};

};

template <typename T, typename comp>
std::ostream & operator<<(std::ostream & os, sorted_array<T, comp> const & array);

#include "sorted_array.tcc"

#endif//SORTED_ARRAY_H
