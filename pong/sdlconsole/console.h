#ifndef CONSOLE_H
#define CONSOLE_H

#include <exception>
#include <string>
#include <SDL/SDL.h>

#include "color.h"

/**
 * This is the color constants you can use where a color is expected:
 *
 * COLOR_BLACK
 * COLOR_RED
 * COLOR_GREEN
 * COLOR_YELLOW
 * COLOR_BLUE
 * COLOR_MAGENTA
 * COLOR_CYAN
 * COLOR_WHITE
 */

const int ERR = -1;

/**
 * Provide "C++" access to elementary ncurses functions.
 *
 * ** Not meant to be efficient, but simple to grasp fast
 *
 * version 0.1
 */
class Console
{
public:
  Console();
  ~Console();
  
  Console(Console&) = delete;
  Console& operator=(Console&) = delete;

  /* get input from keyboard */
  int  get(); // returns ERR after 1/10 second
  bool get(char& c); // returns false if a character was not
  // available within 1/10 second

  /* write character(s) at current position */
  void put(char c);     // put the character for ascii code c
  void put(int i);      // put the integer i
  void put(unsigned int i);
  void put(const std::string &str); // put a string

  /* set/get position where next character will end up */
  void setPos(int x, int y);
  void getPos(int& x, int& y);

  /* get the size of the screen */
  int getWidth();
  int getHeight();

  /* set/get the current color for characters and background */
  void setForegroundColor(color c);
  void setBackgroundColor(color c);
  color getForegroundColor();
  color getBackgroundColor();

private:
  SDL_Surface *screen;

  int cursor_x, cursor_y;

  color background_color, foreground_color;

  void drawRect(int x, int y, int w, int h, const color &c);

  static const int SQUARE_X_SIZE = 10;
  static const int SQUARE_Y_SIZE = 10;
  static const int WINDOW_INIT_WIDTH = 640;
  static const int WINDOW_INIT_HEIGHT = 480;
  static const int KEY_DELAY = 100;

  static bool instantiated;
};

/**
 * Thrown when something goes amiss
 */
class ConsoleError : public std::exception
{
public:
  ConsoleError(std::string const& msg) : std::exception(), _what(msg) {}
  ~ConsoleError() throw() {}

  const char* what() const throw() { return _what.c_str(); }

private:
  std::string _what;
};

#endif
