
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>

class Sorted_List
{
public:
  Sorted_List();
  //Sorted_list(Node node);

  bool is_empty() const;
  int size() const;
  void insert(int const value);
  void remove(int const value);
  int first_value() const;
  

private:
  class Node
  {
  public:
    int value;
    Node* next;
  };
  Node* head;
  int size_var;
  void print_node(Node const& node) const;
  
};
#endif
