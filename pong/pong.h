

#ifndef PONG_H
#define PONG_H

#include <vector>

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
   Paddle p2;
   Ball b;
   
   int score;
   int score2;
   bool game_over;
   
   void draw_game();
   void handle_collisions();
};

#endif
