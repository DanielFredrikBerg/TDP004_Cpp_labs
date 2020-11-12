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

  Time& operator=(Time const& time);
  bool operator==(Time const& time) const;
  bool operator!=(Time const& time) const;
  bool operator>(Time const& time) const;
  bool operator>=(Time const& time) const;
  bool operator<(Time const& time) const;
  bool operator<=(Time const& time) const;
  
  std::string to_string(bool const am_pm) const;
  
  Time operator+(int const seconds) const;
  Time operator-(int const seconds) const;

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
  bool is_valid() const;

  std::string fill_digit(int const number) const;
  int time_to_sec() const; 
  void set_time(int total_seconds);
};

std::ostream& operator<<(std::ostream & out_stream, Time const& time);
std::istream& operator>>(std::istream & in_stream, Time & time);

#endif
