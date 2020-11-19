#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include <vector>
#include <initializer_list>
#include <ostream>

#include "less.h"
#include "distance.h"

template <typename T>
class sorted_array
{

public:

    sorted_array() = default;
    sorted_array(std::initializer_list<T> list);

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
  Distance<T> center{};

};

template <typename T>
std::ostream & operator<<(std::ostream & os, sorted_array<T> const & array);

#include "sorted_array.tcc"

#endif//SORTED_ARRAY_H
