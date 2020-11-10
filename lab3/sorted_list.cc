#include "sorted_list.h"

Sorted_List::Sorted_List()
   : head{nullptr}, size_var{0}
{}

// Copy Constructor
Sorted_List::Sorted_List(Sorted_List const& s_list)
  : head{nullptr}, size_var{0}
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
  //std::cout << "size" << std::endl;
  return size_var;
}


void Sorted_List::insert(int const value)
{
  if (is_empty())
  {
    head = new Node{value, nullptr};
    //std::cout << "insert" << std::endl;
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
    //std::cout << "remove" << std::endl;
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
  //std::cout << "first value" << std::endl;
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
  std::string content{to_string()};
  std::cout << content << std::endl;
}

void Sorted_List::clear()
{
  Node* tmp{head};
  
}

Sorted_List& Sorted_List::operator=(Sorted_List const& other)
{
  // Ta bort om det finns något inuti.
  if (head != nullptr)
  {
    *this.clear();
  }
  head = other.head;
  other.head = nullptr;
  return *this;
}


