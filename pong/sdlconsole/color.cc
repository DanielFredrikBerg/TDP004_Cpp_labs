#include <array>

#include "color.h"

color::color(byte r, byte g, byte b) : r(r), g(g), b(b) {}

const color COLOR_BLACK = color(0, 0, 0);
const color COLOR_RED = color(255, 0, 0);
const color COLOR_GREEN = color(0, 255, 0);
const color COLOR_YELLOW = color(255, 255, 0);
const color COLOR_BLUE = color(0, 0, 255);
const color COLOR_MAGENTA = color(255, 0, 255);
const color COLOR_CYAN = color(0, 255, 255);
const color COLOR_WHITE = color(255, 255, 255);

static const std::array<color, 8> std_colors = {
  COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW,
  COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE
};

color::color(int i)
{
  r = std_colors.at(i).r;
  g = std_colors.at(i).g;
  b = std_colors.at(i).b;
}
