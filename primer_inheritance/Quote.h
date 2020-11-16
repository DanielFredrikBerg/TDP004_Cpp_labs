#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote 
{
public:
   std::string isbn() const;
   virtual double net_price(std::size_t n) const;

};
#endif
