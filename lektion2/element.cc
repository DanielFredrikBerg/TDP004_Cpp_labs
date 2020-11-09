#include "element.h"


int main() 
{
  // Uppgift 1
  Element* first{ new Element{nullptr, 5} };
  first -> next = first;

  std::cout << first -> next -> value << std::endl;
  
  // Uppgift 2
  (*first -> next).next -> value = 10;
  // first pekar på objektet element vars
  // vars next pekare pekar på sig själv (first).
  // (1 varv)
  // (*(first -> next)) är elementet.
  // (*(first -> next)).next är pekare till sig själv
  // (2 varv)
  // (*(first -> next)).next -> value; 
  // avrefererat till value som är 10.
  first -> value = 10;
  first -> next = nullptr;

  // Uppgift 3
  first -> next = new Element{nullptr, 9};
  std::cout << first -> next -> value << std::endl;
  
  // Uppgift 4
  first -> next = { new Element{first -> next, 8} };
  std::cout << first -> next -> value << std::endl;
  
  
  
}

// Uppgift 5
Element* last_elem_iter(Element* pekvariabel)
{
  if (pekvariabel)
  {
    while (pekvariabel -> next != nullptr)
    {
      pekvariabel = pekvariabel -> next;
    }
  }
  return pekvariabel -> value;
}

// Uppgift 6
Element* last_elem_rec(Element* pekvariabel)
{
  if (pekvariabel -> next == nullptr ||
      pekvariabel == nullptr)
    {
      return pekvariabel;
    }
  else
  {
    return last_elem_rec(pekvariabel -> next);
  }
}

// Uppgift 7 - given func:
void insert(Element* e, int i)
{
  e = new Element(e -> next, i);
}
// Förklara bildligt vad som händer vid insert(first, 2);
// Titta i anteckningar.

