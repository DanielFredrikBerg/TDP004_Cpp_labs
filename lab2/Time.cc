// I denna fil lÃ¤ggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h

#include "Time.h" 

Time::Time()
  : hour{}, minute{}, second{} 
{}

// KlaAr36: Mycket bra löst. Omöjligt skapa felaktiga tider!
Time::Time(int const hour, int const minute, int const second)
  : hour{hour}, minute{minute}, second{second} 
{
  if (!is_valid())
  {
    throw std::runtime_error("Invalid time");
  }
}

// KlaAr36: Komplettering: Datamedlemmar ska initieras i datamedlemsinitieringslista - KLART
Time::Time(Time const& time, int const seconds)
  : hour{0}, minute{0}, second{0}
{
  set_time(time.time_to_sec() + seconds);
}

Time::Time(Time const& time)
: hour{time.hour}, minute{time.minute}, second{time.second}
{}

bool Time::is_valid() const
{
// KlaAr36: Skrivsättet ( 0 <= hour <= 23 ) skulle vara tydligast och i c++ kan vi komma ganska nära genom att skriva ( 0 <= hour && hour <= 23 ). Ni är i sin tur väldigt nära det. Bra!
  return hour >= 0 && hour <= 23 
    && minute >= 0 && minute <= 59 
    && second >= 0 && second <= 59;  
}

std::string Time::fill_digit(int const number) const
{
  if (number < 10)
  {
    return "0";
  }
  return "";
}

std::string Time::to_string(bool const am_pm) const
{
  int temp_hour{hour};
  std::string end{""};
  if (am_pm)
  {
    if (temp_hour >= 12)
    {
      end = " pm";
      if (temp_hour > 12)
      {
         temp_hour -= 12;
      }
    }
    else
    {
      end = " am";
// KlaAr36: Komplettering: Det ser ut som ni missar specialfallet att "0:xx:xx" skrivs "12:xx:xx am" - KLART
    }
  }
  
  std::string str{""};
  if (am_pm && temp_hour == 0)
  {
    temp_hour = 12; 
  }
// KlaAr36: Komplettering: Kodupprepning. Gör funktion eller använd strängström med setfill för att fylla med nolla! - KLART
  int array[3]{temp_hour, minute, second};
  for (int i{0}; i < 3; i++)
  {
      str += fill_digit(array[i]);
      str += std::to_string(array[i]);
      if (i < 2)
      {
        str += ":";
      }
  }
  return str + end;
}



Time& Time::operator=(Time const& time)
{
  hour = time.hour;
  minute = time.minute;
  second = time.second;
  return *this;
}

bool Time::operator==(Time const& time) const
{
// KlaAr36: Komplettering: Ej objektorienterat skrivsätt. Så ska det vara:
//  return time_to_sec() == time.time_to_sec(); - KLART
  return time_to_sec() == time.time_to_sec();
}

bool Time::operator!=(Time const& time) const
{
  return !(*this == time);
}

bool Time::operator>(Time const& time) const
{
// KlaAr36: Komplettering: Ej objektorienterat skrivsätt. -KLART
  return time_to_sec() > time.time_to_sec();
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

// KlaAr36: Snyggt. Kunde vara "return *this += seconds".
Time Time::operator+(int const seconds) const
{
  return Time{*this, seconds};
}


Time Time::operator-(int const seconds) const
{
  return Time{*this, -seconds}; 
}


Time& Time::operator++()
{
  set_time(time_to_sec() + 1);
  return *this;
}

Time Time::operator++(int) 
{
  Time temp{*this};
  ++*this;
  return temp;
}

Time& Time::operator--()
{
  set_time(time_to_sec() - 1);
  return *this;
}

Time Time::operator--(int) 
{
  Time temp{*this};
  --*this;
  return temp;
}

// KlaAr36: Bra! Snyggt!
std::ostream& operator<<(std::ostream & out_stream, Time const& time)
{
  return out_stream << time.to_string(false);
}

// KlaAr36: Bra! Snyggt! Rätt tänk och nära referenslösning. 
std::istream& operator>>(std::istream & in_stream, Time & time)
{
  int hour_temp;
  int minute_temp;
  int second_temp;

  in_stream >> hour_temp >> minute_temp >> second_temp;
  
// KlaAr36: Komplettering: Fungerar inte. Ni måste fånga undantaget från er konstruktor för att detektera felet
  try
  {
    Time temp{hour_temp, minute_temp, second_temp};
    time = temp;
    
  } 
  catch (const std::runtime_error& error)
  {
    in_stream.setstate(std::ios_base::failbit);
  }
  
  return in_stream;
}



int Time::get_hour() const {return hour;}
int Time::get_minute() const {return minute;}
int Time::get_second() const {return second;}

int Time::time_to_sec() const
{
  return hour * 3600 + minute * 60 + second; 
}

void Time::set_time(int total_seconds)
{
  int sec_per_min{60};
  int sec_per_hour{sec_per_min * 60};
  int sec_per_day{sec_per_hour * 24};

  if (total_seconds < 0)
  {
// KlaAr36: Bra uttänkt!
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
