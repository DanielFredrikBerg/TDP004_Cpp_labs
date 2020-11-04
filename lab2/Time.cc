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

Time::Time(string time_str)
  : hour{stoi(time_str.substr(0,2))},
    minute{stoi(time_str.substr(3,2))},
    second{stoi(time_str.substr(6,2))} 
{}

bool Time::is_valid() const
{
  return hour >= 0 && hour <= 23 
	  && minute >= 0 && minute <= 60 
	  && second >= 0 && second <= 60;  
}

string Time::to_string(bool const& am_pm) const
{
  string end{""};
  string str{""};
  int temp_hour{hour};
  if (am_pm)
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

bool Time::operator==(Time const& time) const
{
  return time_to_sec(*this) == time_to_sec(time);
}

bool Time::operator!=(Time const& time) const
{
  return !(*this == time);
}

bool Time::operator>(Time const& time) const
{
  return time_to_sec(*this) > time_to_sec(time);
}

bool Time::operator>=(Time const& time) const
{
  return *this == time || *this > time;
}

bool Time::operator<(Time const& time) const
{
  return !(*this >= time);
}

bool Time::operator<=(Time const& time) const
{
  return !(*this > time);
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

ostream& operator<<(ostream & out_stream, Time const& time)
{
  return out_stream << time.to_string(false);
}

istream& operator>>(istream & in_stream, Time const& time)
{
  if (!time.is_valid())
  {
    in_stream.setstate(std::ios_base::failbit);
  }
  string str{};
  in_stream >> str;
  // TODO
  return in_stream;
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

