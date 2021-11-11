


#ifndef PADDLE_H
#define PADDLE_H

class Paddle 
{
public:
	Paddle() = default;
	Paddle(int x_pos, int y_pos, int length);

	void update(int screen_width, bool direction);

	int get_x_pos() const;
	int get_y_pos() const;
	int get_length() const;
private:
	int x_pos;
	int y_pos;
	int length;
};

#endif