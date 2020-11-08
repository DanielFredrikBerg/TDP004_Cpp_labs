// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <exception>

class Time
{
public:
  Time();
  Time(int const hour, int const minute, int const second);
  Time(Time const& time, int const second);
  Time(Time const& time);
  Time(Time const& time1, Time const& time2);
  Time(std::string time_str);

  bool is_valid() const;
  void operator=(Time const& time);
  bool operator==(Time const& time) const;
  bool operator!=(Time const& time) const;
  bool operator>(Time const& time) const;
  bool operator>=(Time const& time) const;
  bool operator<(Time const& time) const;
  bool operator<=(Time const& time) const;
  
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
  int time_to_sec(Time const& time) const; 
};

std::ostream& operator<<(std::ostream & out_stream, Time const& time);
std::istream& operator>>(std::istream & in_stream, Time & time);

#endif
