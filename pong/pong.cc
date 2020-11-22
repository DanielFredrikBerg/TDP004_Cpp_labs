
#include <string>
#include <cstdlib>
#include <vector>

#include "pong.h"

Pong::Pong()
   : c{}, p{Paddle{}}, p2{Paddle{}}, b{Ball{}}, score{0}, score2{0}, game_over{false}
{

	// create paddles
	int paddle_length{20};
  	p = Paddle{c.getWidth() / 2 - paddle_length / 2, c.getHeight() - 6, paddle_length};
        p2 = Paddle{c.getWidth() / 2 - paddle_length / 2, 6, paddle_length};

  	// create ball
  	srand (time(NULL));
  	int x_pos{std::min(2 + rand() % c.getWidth(), c.getWidth() - 2)};
  	int y_pos{2 + rand() % c.getHeight() / 2};
  	int x_velocity{rand() % 2 == 0 ? -1 : 1};
  	int y_velocity{rand() % 2 == 0 ? -1 : 1};
  	b = Ball{x_pos, y_pos, x_velocity, y_velocity};
}


void Pong::draw_game()
{
	// draw corners
	c.setForegroundColor(COLOR_BLUE);
	c.setPos(0, 4);
	c.put('+');
	c.setPos(c.getWidth() - 1, 4);
	c.put('+');
	c.setPos(0, c.getHeight() - 4);
	c.put('+');
	c.setPos(c.getWidth()- 1, c.getHeight() - 4);
	c.put('+');

	// draw top/bottom walls
	c.setForegroundColor(COLOR_BLUE);
	std::string wall(c.getWidth() - 2, '-');
	c.setPos(1, 4);
	c.put(wall);
	c.setForegroundColor(COLOR_GREEN);
	c.setPos(1, c.getHeight() - 4);
	c.put(wall);

	// draw middle
	c.setForegroundColor(COLOR_WHITE);
	std::string fill(c.getWidth() - 2, ' ');
	fill = "|" + fill + "|";
	for (int i{5}; i < c.getHeight() - 4; ++i)
	{
		c.setPos(0, i);
		c.put(fill);
	}

        // draw paddle
        c.setForegroundColor(COLOR_YELLOW);
        for (int i{0}; i < p.get_length(); ++i)
        {
           c.setPos(p.get_x_pos() + i, p.get_y_pos());
           
           // draw paddle end points
           if (i == 0 || i == p.get_length() - 1)
           {
              c.put('o');
           }
           else
           {
              c.put('-');
           }
        }

        c.setForegroundColor(COLOR_YELLOW);
        for (int i{0}; i < p.get_length(); ++i)
        {
           c.setPos(p2.get_x_pos() + i, p2.get_y_pos());
           
           // draw paddle end points
           if (i == 0 || i == p.get_length() - 1)
           {
              c.put('o');
           }
           else
           {
              c.put('-');
           }
        }
        
        

	// draw ball
	c.setForegroundColor(COLOR_RED);
	c.setPos(b.get_x_pos(), b.get_y_pos());
	c.put('0');

	// draw score
	c.setForegroundColor(COLOR_WHITE);
	std::string score_str{"Score Player 1: " + std::to_string(score)};
        std::string score_str2{"Score Player 2: " + std::to_string(score2)};
	c.setPos(c.getWidth() / 2 - 7, c.getHeight() - 2);
	c.put(score_str);
        c.setPos(c.getWidth() / 2 -7, 2);
        c.put(score_str2);

	// draw game over message
	if (game_over)
	{
           c.setForegroundColor(COLOR_WHITE);
           c.setPos(c.getWidth() / 2 - 5, c.getHeight() / 2);
           c.put("Game Over!");
           c.setPos(c.getWidth() / 2 - 6, c.getHeight() / 2 + 1);
           if (score > score2)
           {
              c.put("Player 1 won!");
           }
           else
           {
              c.put("Player 2 won!");
           }
           c.setPos(c.getWidth() / 2 - 9, c.getHeight() / 2 + 2);
           c.put("Press 'q' to quit.");			
	}
}

void Pong::handle_collisions()
{
	int ball_x{b.get_x_pos()};
	int ball_y{b.get_y_pos()};
	int ball_x_velocity{b.get_x_velocity()};

	// check collision - ball with walls
	if (ball_x == 1 && ball_x_velocity < 0)
	{
		b.invert_x_velocity();
	}
	else if (b.get_x_pos() == c.getWidth() - 2 
			 && ball_x_velocity > 0)
	{
		b.invert_x_velocity();
	}

	if (ball_y <= 4)
	{
           ++score;
           b.invert_y_velocity();
	}
	else if (ball_y >= c.getHeight() - 4)
	{
           ++score2;
           b.invert_y_velocity();
	}
        
        if (score == 2 || score2 == 2)
        {
           // game over
           game_over = true;
        }

	// check collision - ball with paddle1
	int paddle_x{p.get_x_pos()};
	int paddle_y{p.get_y_pos()};
	int paddle_length{p.get_length()};

	if (ball_y + 1 == paddle_y
		&& ball_x >= paddle_x
		&& ball_x <= paddle_x + paddle_length)
	{
		b.invert_y_velocity();
	}

        // check collision - ball with paddle2
	int paddle_x2{p2.get_x_pos()};
	int paddle_y2{p2.get_y_pos()};
	int paddle_length_2{p2.get_length()};

	if (ball_y - 1 == paddle_y2
		&& ball_x >= paddle_x2
		&& ball_x <= paddle_x2 + paddle_length_2)
	{
		b.invert_y_velocity();
	}
}

void Pong::run()
{
   while ( c.get() != 'q' )
   {
      
      if (!game_over)
      {
         // handle input
         if (c.get() == 'a')
         {
            p.update(c.getWidth(), true);
         }
         else if (c.get() == 'd')
         {
            p.update(c.getWidth(), false);
         }
         else if (c.get() == 'j')
         {
            p2.update(c.getWidth(), true);
         }
         else if (c.get() == 'l')
         {
            p2.update(c.getWidth(), false);
         }
         
         // move ball
         b.move();
         
         // handle collisions
         handle_collisions();
         
         // draw game
         draw_game();
      }	    
   }
}

