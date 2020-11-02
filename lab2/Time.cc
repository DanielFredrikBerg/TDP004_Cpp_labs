// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h

#include "Time.h" 

using namespace std;

Time::Time()
: hour{}, minute{}, second{} 
{}

Time::Time(int h, int m, int s)
: hour{h}, minute{m}, second{s} 
{}

bool Time::is_valid() const
{
	return hour >= 0 && hour <= 23 
	       && minute >= 0 && minute <= 60 
		   && second >= 0 && second <= 60; 
}

// TODO
string Time::to_string() const
{
	return ""; // TODO
}

	// TODO
Time Time::operator+(Time const& time)
{
	return *this; // TODO
}

// TODO
Time Time::operator-()
{
	return *this; // TODO
}

// prefix ++ operator
Time& Time::operator++()
{
	second++;
	return *this;
}

// postfix ++ operator
Time Time::operator++(int) // dummy parameter
{
	Time temp = *this;
	++*this;
	return temp;
}

// prefix -- operator
Time& Time::operator--()
{
	second--;
	return *this;
}

// postfix -- operator
Time Time::operator--(int) // dummy parameter
{
	Time temp = *this;
	--*this;
	return temp;
}

void Time::adjust_time() // kasst namn ?
{
	while (second >= 60) 
	{
		second -= 60;
		minute++;
	}

	while (minute >= 60)
	{
		minute -= 60;
		hour++;
	}

	while (hour >= 24)
	{
		hour -= 24;
	}
}
