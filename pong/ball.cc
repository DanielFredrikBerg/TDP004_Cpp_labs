
#include "ball.h"

Ball::Ball(int x_pos, int y_pos, int x_velocity, int y_velocity)
: x_pos{x_pos}, y_pos{y_pos}, x_velocity{x_velocity}, y_velocity{y_velocity}
{}

void Ball::move()
{
	x_pos += x_velocity;
	y_pos += y_velocity;
}


int Ball::get_x_pos() const
{
	return x_pos;
}

int Ball::get_y_pos() const
{
	return y_pos;
}

int Ball::get_x_velocity() const
{
	return x_velocity;
}

int Ball::get_y_velocity() const
{
	return y_velocity;
}


void Ball::invert_x_velocity()
{
	x_velocity *= -1;
}

void Ball::invert_y_velocity()
{
	y_velocity *= -1;
}
