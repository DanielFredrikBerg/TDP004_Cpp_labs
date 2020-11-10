
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>

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
   
  

private:
   class Node
   {
   private:
      Node copy_node(Node* node_ptr);
      
   public:
      int value;
      Node* next;
   };
   Node* head;
   int size_var;
   
   
   
};
#endif
