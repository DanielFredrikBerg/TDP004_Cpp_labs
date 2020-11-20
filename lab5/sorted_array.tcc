#include <utility>
#include <stdexcept>

#include "less.h"
#include "distance.h"

using namespace std;

template <typename T, typename comp>
sorted_array<T, comp>::sorted_array(initializer_list<T> list)
  : data{}, comparator{Less<T>{}}
{
  for (T val : list)
  {
    insert(val);
  }
}

template <typename T, typename comp>
sorted_array<T, comp>::sorted_array(initializer_list<T> list, comp comparator)
  : data{}, comparator{comparator}
{
    for (T val : list)
    {
        insert(val);
    }
}

template <typename T, typename comp>
void sorted_array<T, comp>::insert(T value)
{
    data.push_back(value);
    for (int i {size() - 1}; i > 0; --i)
    {
      if (comparator.compare(data[i], data[i-1]))
        {
            swap(data[i-1], data[i]);
        }
        else
        {
            break;
        }
    }
}

template <typename T, typename comp>
T sorted_array<T, comp>::erase(int index)
{
    if (index < 0 || index >= size())
        throw std::out_of_range{"unable to erase; index is out of bounds."};
    for (int i {index}; i + 1 < size(); ++i)
    {
        swap(data[i], data[i+1]);
    }
    T value {data.back()};
    data.pop_back();
    return value;
}

template <typename T, typename comp>
T & sorted_array<T, comp>::operator[](int index)
{
    return data[index];
}

template <typename T, typename comp>
T sorted_array<T, comp>::operator[](int index) const
{
    return data[index];
}

template <typename T, typename comp>
T & sorted_array<T, comp>::at(int index)
{
    return data.at(index);
}

template <typename T, typename comp>
T sorted_array<T, comp>::at(int index) const
{
    return data.at(index);
}

template <typename T, typename comp>
int sorted_array<T, comp>::size() const
{
    return static_cast<int>(data.size());
}

template <typename T, typename comp>
ostream & operator<<(ostream & os, sorted_array<T, comp> const & array)
{
    if (array.size() == 0)
    {
        os << "{}";
        return os;
    }
    os << '{' << array[0];
    for (int i {1}; i < array.size(); ++i)
    {
        os << ", " << array[i];
    }
    os << '}';
    return os;
}
