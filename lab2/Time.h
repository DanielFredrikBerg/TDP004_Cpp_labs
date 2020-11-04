// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs

// headerguard
#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
public:
  Time();
  Time(int const hour, int const minute, int const second);
  Time(Time const& time, int const second);

  bool is_valid() const;
  bool operator==(Time const& time) const;
  bool operator!=(Time const& time) const;
  bool operator>(Time const& time) const;
  bool operator>=(Time const& time) const;
  bool operator<(Time const& time) const;
  bool operator<=(Time const& time) const;
  
  void adjust_time();
  
  std::string to_string(bool const& am_pm) const;
  
  Time operator+(Time const& time);
  Time operator-(Time const& time);

  Time& operator++();
  Time operator++(int);

  Time& operator--();
  Time operator--(int);

  int get_hour() const;
  int get_minute() const;
  int get_second() const;
  
private:
  int hour;
  int minute;
  int second;

  void set_time(int second);
  void time_to_sec(Time const& time) const; 
};

// end of headerguard
#endif
