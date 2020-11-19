
template <typename T>
bool Less<T>::compare(T const& arg_one, T const& arg_two)
{
  return arg_one < arg_two;
}

template <typename T>
bool Less<T>::compare(T const& arg_one, T const& arg_two, T const& distance)
{
  // Returnera true om arg_one ligger närmare distance än arg_two.
  return std::abs(arg_one - distance) < std::abs(arg_two - distance);
}
