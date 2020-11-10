#ifndef STACK_H
#define STACK_H

class Stack
{
public:
   Stack();
   void put(int const value);
   int pop();

   int size;

private:
   class Layer
   {
      int value;
      Layer* next;
   };



};
#endif
