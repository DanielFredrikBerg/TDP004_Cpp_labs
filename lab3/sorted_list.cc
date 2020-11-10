#include "sorted_list.h"

Sorted_List::Sorted_List()
   : head{nullptr}, size_var{0}
{}

// Copy Constructor
Sorted_List::Sorted_List(Sorted_List const& s_list)
{
   if (!s_list.head)
   {
      return;
   }
   Node* tmp{s_list.head};
   
   while (tmp != nullptr)
   {
      insert(tmp->value);
      tmp = tmp->next;
   }
} 

// Destructor
Sorted_List::~Sorted_List()
{
   Node* current{head};

   while (current != nullptr)
   {
      current = current->next;
      delete head;
      head = current;
   }
}

bool Sorted_List::is_empty() const
{
  return head == nullptr;
}

int Sorted_List::size() const
{
  return size_var;
}

void Sorted_List::insert(int const value)
{
  if (is_empty())
  {
    head = new Node{value, nullptr};
  }
  else if (head -> value >= value)
  {
    head = new Node{value, head};
  }
  else
  {
    head -> insert(value);
  }
  ++size_var;
}

void Sorted_List::remove(int const value)
{
  Node* tmp{head};
  if (size() == 0)
  {
    return;
  }
  else if (first_value() == value)
  {
    head = head -> next;
    delete tmp;
    --size_var;
    return;
  }  
  while (tmp -> next) //nullptr är automatiskt false
  {
    if (tmp -> next -> value == value)
    {
      Node* node_rem{tmp -> next};
      tmp -> next = tmp -> next -> next;
      delete node_rem;
      --size_var;
      return;
    }
    tmp = tmp -> next;
  }
}

int Sorted_List::first_value() const
{
  return head -> value;
}

void Sorted_List::Node::insert(int const value)
{
  if (next == nullptr || value <= next -> value)
  {
    next = new Node{value, next};
  }
  else
  {
    next -> insert(value);
  }
}




