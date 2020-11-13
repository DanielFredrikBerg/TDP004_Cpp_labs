#include "sorted_list.h"

Sorted_List::Sorted_List()
   : head{nullptr}, size_var{0}
{}

// Copy Constructor
Sorted_List::Sorted_List(Sorted_List const& other_list)
  : head{nullptr}, size_var{0}
{
   if (!other_list.head)
   {
      return;
   }
   Node* tmp{other_list.head};
   
   while (tmp != nullptr)
   {
      insert(tmp->value);
      tmp = tmp->next;
   }
} 

// Move Constructor
Sorted_List::Sorted_List(Sorted_List && s_list)
  :head{s_list.head}, size_var{s_list.size_var}
{
  s_list.head = nullptr;
  s_list.size_var = 0;
}

// Destructor
Sorted_List::~Sorted_List()
{
  clear();
}


bool Sorted_List::is_empty() const
{
  return head == nullptr;
}

bool Sorted_List::is_sorted() const
{
  Node* tmp{head};
  if (tmp == nullptr)
  {
    return true;
  }
  while (tmp -> next != nullptr)
  {
    if (tmp -> value > tmp -> next -> value)
    {
      return false;
    }
    tmp = tmp -> next;
  }
  return true;
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
  if (size() == 0)
  {
    return;
  }

  Node* tmp{head};
  if (first_value() == value)
  {
    head = head -> next;
    delete tmp;
    --size_var;
    return;
  }  

  while (tmp -> next) 
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


std::string Sorted_List::to_string() const
{
  std::string str{"["};
  Node* tmp{head};
  while (tmp != nullptr)
  {
    str += std::to_string(tmp -> value);
    if (tmp -> next != nullptr)
    {
      str += ", ";
    }
    tmp = tmp -> next;
  }
  str += "]";
  return str;
}


void Sorted_List::print() const
{
  std::cout << to_string() << std::endl;
}


void Sorted_List::clear()
{
  size_var = 0;
  Node* tmp{head};
  while (head != nullptr)
  {
    head = head -> next;
    delete tmp;
    tmp = head;
  }
}


// move assign
Sorted_List& Sorted_List::operator=(Sorted_List && other)
{
  if (head != nullptr)
  {
    clear();
  }
  head = other.head;
  other.head = nullptr;

  size_var = other.size_var;
  other.size_var = 0;

  return *this;
}


// copy assign
Sorted_List& Sorted_List::operator=(Sorted_List const& other)
{
  if (head != nullptr)
  {
    clear();
  }
  Sorted_List temp{other};
  head = temp.head;
  temp.head = nullptr;
  size_var = temp.size_var;
  return *this;
}



