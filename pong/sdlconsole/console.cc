#include "console.h"

#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;

bool Console::instantiated = false;

Console::Console() {
  if (instantiated) {
    throw ConsoleError("Cannot create more than one instance of the console class!");
  }
  instantiated = true;

  cursor_x = cursor_y = 0;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw ConsoleError("Failed to create SDL!");
  }

  setBackgroundColor(COLOR_BLACK);
  setForegroundColor(COLOR_WHITE);

  screen = SDL_SetVideoMode(WINDOW_INIT_WIDTH, WINDOW_INIT_HEIGHT, 8, SDL_SWSURFACE);
  SDL_WM_SetCaption("Console window", 0);
}

Console::~Console() {
  instantiated = false;

  SDL_FreeSurface(screen);
  SDL_Quit();
}

const int numPollKeys = 3;
int pollKeys[numPollKeys][2] = {{ SDLK_q, 'q' }, { SDLK_a, 'a' }, { SDLK_d, 'd'}};

int Console::get() {
  SDL_Delay(KEY_DELAY);

  SDL_PumpEvents();
  int numKeys;
  Uint8 *keys = SDL_GetKeyState(&numKeys);

  for (int i = 0; i < numPollKeys; i++) {
    int idx = pollKeys[i][0];
    if (keys[idx]) {
      return pollKeys[i][1];
    }
  }

  return ERR;
}

bool Console::get(char &c) {
  int ch = get();
  if (ch == ERR) return false;
  c = (char)ch;
  return true;
}

void Console::put(char ch) {
  color &c = (ch == ' ' ? background_color : foreground_color);
  drawRect(cursor_x * SQUARE_X_SIZE, cursor_y * SQUARE_Y_SIZE, SQUARE_X_SIZE, SQUARE_Y_SIZE, c);
  if (++cursor_x >= getWidth()) {
    if (++cursor_y >= getHeight()) cursor_y = 0;
    cursor_x = 0;
  }
}

void Console::put(const string &str) {
  for (unsigned int i = 0; i < str.size(); i++) {
    put(str[i]);
  }
}

void Console::put(int i) {
  ostringstream ss;
  ss << i;
  put(ss.str());
}

void Console::put(unsigned int i) {
  ostringstream ss;
  ss << i;
  put(ss.str());
}

void Console::drawRect(int x, int y, int w, int h, const color &c) {
  Uint32 pixel = SDL_MapRGB(screen->format, c.r, c.g, c.b);

  if (SDL_MUSTLOCK(screen)) {
    if (SDL_LockSurface(screen) < 0) throw ConsoleError("FATAL: Could not lock the screen!");
  }

  int xEnd = min(x + w, screen->w);
  int yEnd = min(y + h, screen->h);
  Uint8 bpp = screen->format->BytesPerPixel;
  for (int cx = x; cx < xEnd; cx++) {
    for (int cy = y; cy < yEnd; cy++) {

      Uint8 *bits = ((Uint8 *)screen->pixels) + cy * screen->pitch + cx * bpp;

      switch (bpp) {
      case 1:
	*((Uint8 *)(bits)) = (Uint8)pixel;
	break;
      case 2:
	*((Uint16 *)(bits)) = (Uint16)pixel;
	break;
      case 3:
	{ /* Format/endian independent */
	  Uint8 r, g, b;

	  r = (pixel>>screen->format->Rshift)&0xFF;
	  g = (pixel>>screen->format->Gshift)&0xFF;
	  b = (pixel>>screen->format->Bshift)&0xFF;
	  *((bits)+screen->format->Rshift/8) = r; 
	  *((bits)+screen->format->Gshift/8) = g;
	  *((bits)+screen->format->Bshift/8) = b;
	}
	break;
      case 4:
	*((Uint32 *)(bits)) = (Uint32)pixel;
	break;
      }
    }
  }

  if (SDL_MUSTLOCK(screen)) {
    SDL_UnlockSurface(screen);
  }

  SDL_UpdateRect(screen, x, y, w, h);
}

void Console::setPos(int x, int y) {
  if (x < 0) return;
  if (x >= getWidth()) return;
  if (y < 0) return;
  if (y >= getHeight()) return;
  cursor_x = x;
  cursor_y = y;
}

void Console::getPos(int &x, int &y) {
  x = cursor_x;
  y = cursor_y;
}

int Console::getWidth() {
  return screen->w / SQUARE_X_SIZE;
}

int Console::getHeight() {
  return screen->h / SQUARE_Y_SIZE;
}

void Console::setForegroundColor(color c) {
  foreground_color = c;
}

void Console::setBackgroundColor(color c) {
  background_color = c;
}

color Console::getForegroundColor() {
  return foreground_color;
}

color Console::getBackgroundColor() {
  return background_color;
}
