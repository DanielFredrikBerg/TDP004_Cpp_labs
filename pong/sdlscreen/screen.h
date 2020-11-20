#ifndef SCREEN_H
#define SCREEN_H

#include <SDL/SDL.h>

class Screen
{
public:
  Screen(int point_size, int w, int h);
  ~Screen();

  // Draw one square point with set color
  void drawPoint(int x, int y);
  
  // Draw one square point with set color
  // Coordinate always rounded down to nearest integer
  void drawPoint(double x, double y);
  
  // Update a section of the screen
  // Must be called after drawing to actually see changes!
  void refresh(int x, int y, int w, int h);

  
  // Set the color for next draw operation
  void setColor(unsigned int rgba);

  // Fill a section of the screen with the set color
  void fillArea(int x, int y, int w, int h);
  
  // Determine the size of one square point
  int getPointSize() const { return point_width; } 
  
private:
  Screen(Screen const&);
  Screen& operator=(Screen const&);
  
  static SDL_Surface *screen;
  Uint32 SDL_color;
  int point_width;
};

#endif
