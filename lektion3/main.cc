#include <iostream>
#include <vector>

class Binary_Operator
{
public:
  virtual double evaluate(double a, double b) const =0;
};

class Multiply : public Binary_Operator
{
public:
  double evaluate(double a, double b) const override { return a * b; }  
};

class Add : public Binary_Operator
{
public:
  double evaluate(double a, double b) const override { return a + b; }  
};

int main()
{
  std::vector<Binary_Operator*> v{ new Multiply{}, new Add{} };
  
  for ( Binary_Operator* bo_ptr : v )
  {
    std::cout << bo_ptr -> evaluate(5.0, 3.0) << std::endl;
  }
  return 0;
}
