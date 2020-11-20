

#ifndef PONG_H
#define PONG_H

#include "console.h"
#include "paddle.h"
#include "ball.h"


class Pong
{
public:
	Pong();
	void run();
private:
	Console c;
	Paddle p;
	Ball b;

	int score;
	bool game_over;

	void draw_game();
	void handle_collisions();
};

#endif