
#include "paddle.h"

Paddle::Paddle(int x_pos, int y_pos, int length)
: x_pos{x_pos}, y_pos{y_pos}, length{length}
{}


void Paddle::update(int screen_width, bool direction)
{
	if (direction)
	{
		if (x_pos > 2)
		{
			x_pos -= 2;
		}
	}
	else
	{
		if (x_pos + length < screen_width - 2)
		{
			x_pos += 2;
		}
	}
}

int Paddle::get_x_pos() const
{
	return x_pos;
}

int Paddle::get_y_pos() const
{
	return y_pos;
}

int Paddle::get_length() const
{
	return length;
}