#ifndef STACK_H
#define STACK_H

class Stack
{
public:
  Stack();
  Stack(Stack const& other);
  Stack(Stack && other);
  ~Stack();

  void put(int const value);
  int pop();
  int peek() const;
  
  bool is_empty() const;
  int show_size() const;
  void print_stack() const;

  Stack& operator=(Stack const& other) const;
  Stack& operator=(Stack && other);

private:
  class Layer
  {
  public:
    int const value;
    Layer* next;
  };
  int size;
  Layer* first;

};
#endif
