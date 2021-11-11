template <typename T>
Distance<T>::Distance(T const& center_)
  : center{center_}
{}

template <typename T>
bool Distance<T>::compare(T const& arg_one, T const& arg_two)
{
  // Returnera true om arg_one ligger närmare distance än arg_two.
   return std::abs(arg_one - center) < std::abs(arg_two - center);
}
