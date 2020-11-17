#include "sorted_list.h"

Sorted_List::Sorted_List()
   : head{nullptr}, size_var{0}
{}

/* Komplettering:
 * Ni använder tmp som namn på väldigt många variabler.
 * Det är inte en jättebra beskrivning på vad den gör,
 * endast den är temporär, vilket alla lokala variabler
 * i en funktion är.
*/

/* Kommentar:
 * I er Node klass så har ni en insert fuktion som har som uppgift
 * att sätta in ett värde i listan. Detta betyder att det är Node's
 * uppgift att allokera datat. Eftersom det är Nodes funktion som
 * gör detta. Detta betyder att det även borde vara Nodes ansvar att
 * ta bort datat som har blivit allokerat. Ni har även att Sorted_lists
 * insert gör en allokering av data. Helst vill man att den som allokerar
 * minnet också har som ansvar att ta bort det.
*/

/* Kommentar för kopieringstilldelning:
 * Kan vara bra att kolla så att användaren inte skickar in this som
 * parameter vid kopiering. List l1{1,2,3} l1 = l1. 
*/

/* Komplettering:
 * Ni använder insert inuti kopieringen, detta är väldigt ineffektivt.
 * Eftersom den alltid kommer att sätta in värdet längst bak i listan.
 * Varje gång ni lägger in ett element så tar det längre tid att ta
 * sig till slutet av listan.
 * 
 * Potentiell l�sning: Skapa array av pekare som pekar p� varje 
 * element i listan. L�gg in noder bakifr�n?
*/
// Copy Constructor
Sorted_List::Sorted_List(Sorted_List const& other_list)
  : head{nullptr}, size_var{0}
{
   if (!other_list.head)
   {
      return;
   }
   Node* other_ptr{other_list.head};
   std::vector<Node*> node_ptrs{};

   while (other_ptr)
   {
     node_ptrs.push_back(other_ptr);
     other_ptr = other_ptr -> next;
   }
   unsigned long int node_ptrs_size{node_ptrs.size()};
   for (unsigned long int i{0}; i < node_ptrs_size; ++i)
   {
     head = new Node{node_ptrs.back() -> value, head};
     node_ptrs.pop_back();
   }
   size_var = other_list.size_var;
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

/* Kommentar:
 * Jag förstår varför ni har denna funktionen. Men det är en 
 * väldigt konstig funktion att ha till det publika gränssnittet
 * i en sorterad lista. Vi antar ju att den alltid är sorterad.
 * Ett annat sätt att lösa detta på skulle vara att ha en at() 
 * funktion som kan hämta ett värde ur listan via index. Sedan
 * hade ni kunnat göra en is_sorted funktion i testfilen.
*/
bool Sorted_List::is_sorted() const
{
  Node* node_ptr{head};
  if (node_ptr == nullptr)
  {
    return true;
  }
  while (node_ptr -> next != nullptr)
  {
    if (node_ptr -> value > node_ptr -> next -> value)
    {
      return false;
    }
    node_ptr = node_ptr -> next;
  }
  return true;
}

int Sorted_List::size() const
{
  return size_var;
}


void Sorted_List::insert(int const value)
{
  if (is_empty() || head -> value >= value)
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

  Node* node_ptr{head};
  if (first_value() == value)
  {
    head = head -> next;
    delete node_ptr;
    --size_var;
    return;
  }  

  while (node_ptr -> next) 
  {
    if (node_ptr -> next -> value == value)
    {
      Node* node_rem{node_ptr -> next};
      node_ptr -> next = node_ptr -> next -> next;
      delete node_rem;
      --size_var;
      return;
    }
    node_ptr = node_ptr -> next;
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
  Node* node_ptr{head};
  while (node_ptr != nullptr)
  {
    str += std::to_string(node_ptr -> value);
    if (node_ptr -> next != nullptr)
    {
      str += ", ";
    }
    node_ptr = node_ptr -> next;
  }
  str += "]";
  return str;
}


// Kommentar: Hade kanske varit trevligt med en parameter som
//            gör att man kan välja ström.
void Sorted_List::print() const
{
  std::cout << to_string() << std::endl;
}

void Sorted_List::clear()
{
  size_var = 0;
  Node* node_ptr{head};
  while (head != nullptr)
  {
    head = head -> next;
    delete node_ptr;
    node_ptr = head;
  }
}


// move assign
// Kommentar: Om ni swappar pekarna mellan listorna så krävs ingen clear().
//            Eftersom rhs snart kommer att dö. Så om rhs får this gamla
//            data så kommer den att ta bort detta vid sin död.
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
// Kommentar: Snyggt att ni använder copy konstruktorn här.
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



