#include "linked_list.h"


Sorted_list::Sorted_list()
  : size{}, first_node{nullptr}
{}


bool Sorted_list::is_empty() const
{
  return (*this).first_node == nullptr;
}



int main() 
{
  Sorted_list::Node* node_ptr = new Sorted_list::Node{};
  Sorted_list sorted_list{};
  //std::cout << sorted_list.is_empty() << std::endl;
  //Sorted_list::print_node(*node_ptr);

  return 0;
}
