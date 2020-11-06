
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>

class Sorted_list
{
public:
  Sorted_list();
  //Sorted_list(Node node);

  bool is_empty() const;



private:
  struct Node
  {
    int value;
    Node* node_ptr;
  };
  Node* first_node;
  int size;
  void print_node(Node const& node) const;
  
};
#endif
