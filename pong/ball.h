

#ifndef BALL_H
#define BALL_H

class Ball 
{
public:
	Ball() = default;
	Ball(int x_pos, int y_pos, int x_velocity, int y_velocity);

	void move();

	int get_x_pos() const;
	int get_y_pos() const;
	int get_x_velocity() const;
	int get_y_velocity() const;

	void invert_x_velocity();
	void invert_y_velocity();

private:
	int x_pos;
	int y_pos;

	int x_velocity;
	int y_velocity;
};

#endif