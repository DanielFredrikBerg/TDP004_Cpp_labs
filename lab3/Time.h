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
	Time(int const, int const, int const);

	bool is_valid() const;

	std::string to_string() const;

	Time operator+(Time const&);
	Time operator-();

	Time& operator++();
	Time operator++(int);

	Time& operator--();
	Time operator--(int);

private:
	int hour;
	int minute;
	int second;

	void adjust_time();
};

// end of headerguard
#endif