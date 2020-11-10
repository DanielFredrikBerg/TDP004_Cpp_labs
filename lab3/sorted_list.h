
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>
#include <string>

class Sorted_List
{
public:
  Sorted_List();
  Sorted_List(Sorted_List const& s_list);
  ~Sorted_List();

  bool is_empty() const;
  int size() const;
  void insert(int const value);
  void remove(int const value);
  int first_value() const;
  std::string to_string() const;
  void print() const;
  void clear();  
  
  Sorted_List& operator=(Sorted_List const& other);

private:
  class Node
  {
  private:
      
    
  public:
    int value;
    Node* next;
    void insert(int const value);
  };
  Node* head;
  int size_var;
   
  
   
};
#endif
