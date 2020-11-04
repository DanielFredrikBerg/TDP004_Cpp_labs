// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h

#include "Time.h" 

using namespace std;

Time::Time()
: hour{}, minute{}, second{} 
{}

Time::Time(int const h, int const m, int const s)
: hour{h}, minute{m}, second{s} 
{}

Time::Time(Time const& t1, int const s)
: hour{t1.hour}, minute{t1.minute}, second{t1.second + s}
{}

Time::Time(Time const& t1)
: hour{t1.hour}, minute{t1.minute}, second{t1.second}
{}

bool Time::is_valid() const
{
  return hour >= 0 && hour <= 23 
	  && minute >= 0 && minute <= 60 
	  && second >= 0 && second <= 60; 
}

bool Time::operator==(Time const& time) const
{
  return hour == time.get_hour() && minute == time.get_minute()
    && second == time.get_second();
}


string Time::to_string(bool const& p) const
{
  string end = "";
  string str = "";
  int temp_hour = hour;
  if (p)
  {
    if (temp_hour >= 12)
    {
      end += " pm";
      if (temp_hour > 12)
      {
	temp_hour -= 12;
      }
    }
    else
    {
      end += " am";
    }
  }
  if (temp_hour < 10)
  {
    str += "0";
  }
  str += std::to_string(temp_hour) + ":";
  if (minute < 10)
  {
    str += "0";
  }
  str += std::to_string(minute) + ":";
  if (second < 10)
  {
    str += "0";
  }
  str += std::to_string(second);
  return str + end;
}


Time Time::operator+(Time const& time)
{
  set_time(time_to_sec(*this) + time_to_sec(time));
  return *this;
}


Time Time::operator-(Time const& time)
{
  set_time(time_to_sec(*this) - time_to_sec(time));
  return *this; 
}

// prefix ++ operator
Time& Time::operator++()
{
  set_time(time_to_sec(*this) + 1);
  return *this;
}

// postfix ++ operator
Time Time::operator++(int) 
{
  Time temp{*this};
  ++*this;
  return temp;
}

// prefix -- operator
Time& Time::operator--()
{
  set_time(time_to_sec(*this) - 1);
  return *this;
}

// postfix -- operator
Time Time::operator--(int) // dummy parameter
{
  Time temp{*this};
  --*this;
  return temp;
}

int Time::get_hour() const {return hour;}
int Time::get_minute() const {return minute;}
int Time::get_second() const {return second;}

int Time::time_to_sec(Time const& time) const
{
  return time.hour * 3600 + time.minute * 60 + time.second; 
}

void Time::set_time(int total_seconds)
{
  int sec_per_min{60};
  int sec_per_hour{sec_per_min * 60};
  int sec_per_day{sec_per_hour * 24};
  if (total_seconds < 0)
  {
    total_seconds += (1 + total_seconds / sec_per_day) * sec_per_day;
  }
  if (total_seconds >= sec_per_day)
  {
    total_seconds %= sec_per_day;
  }

  hour = total_seconds / sec_per_hour;
  minute = (total_seconds - hour * sec_per_hour) / sec_per_min;
  second = total_seconds - sec_per_hour * hour - sec_per_min * minute;
}

void Time::adjust_time() // kasst namn ?
{
  minute += second / 60;
  second %= 60;
  
  if (second < 0)
  {
    minute--;
    second += 60;
  }

  hour += minute / 60;
  minute %= 60;
  
  if (minute < 0)
  {
    hour--;
    minute += 60;
  }
  
  hour %= 24;
  
  if (hour < 0)
  {
    hour += 24;
  }
}
