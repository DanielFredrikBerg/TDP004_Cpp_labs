#include <iostream>
#include <stdexcept>

#include "screen.h"

SDL_Surface *Screen::screen = NULL;

Screen::Screen(int point_size, int w, int h) : point_width(point_size)
{
  if ( screen != NULL )
  {
    throw std::logic_error("You can only have one screen");
  }
  screen = SDL_SetVideoMode(point_width*w, point_width*h, 32, SDL_SWSURFACE);
  if ( screen == NULL )
  {
    std::cerr << "Unable to set video mode: " << SDL_GetError() << std::endl;
    throw;
  }
  setColor(0xFFFFFFFF);
  fillArea(0, 0, point_width*w, point_width*h);
}

Screen::~Screen()
{
}

void Screen::setColor(unsigned int rgba)
{
  SDL_color = SDL_MapRGB(screen->format,
                         Uint8(rgba >> 24),
                         Uint8(rgba >> 16),
                         Uint8(rgba >>  8));
}

void Screen::drawPoint(int x, int y)
{
  if (screen->w < (x+1)*point_width || screen->h < (y+1)*point_width || x < 0 || y < 0)
  {
    std::cerr << "WARNING: Point at ("
              << x << ", " << y
              << ") out of bounds" << std::endl;
    return;
  }
  
  for ( int ix = 0; ix < point_width; ++ix)
  {
    for ( int iy = 0; iy < point_width; ++iy)
    {
      Uint32 *bufp = (reinterpret_cast<Uint32*>(screen->pixels) +
                      (y*point_width+iy)*screen->pitch/4 +
                      x*point_width+ix);
      *bufp = SDL_color;
    }
  }
}

void Screen::drawPoint(double x, double y)
{
  drawPoint(int(x), int(y));
}

void Screen::refresh(int x, int y, int w, int h)
{
  SDL_UpdateRect(screen,
                 x*point_width, y*point_width,
                 w*point_width, h*point_width);
}

void Screen::fillArea(int x, int y, int w, int h)
{
  SDL_Rect area;
  area.x = x*point_width;
  area.y = y*point_width;
  area.w = w*point_width;
  area.h = h*point_width;
  
  SDL_FillRect(screen, &area, SDL_color);
  SDL_UpdateRect(screen,
                 area.x, area.y,
                 area.w, area.h);
}
