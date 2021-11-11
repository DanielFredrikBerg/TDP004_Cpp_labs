#ifndef _COLOR_H_
#define _COLOR_H_

typedef unsigned char byte;

class color {
public:
  color(int c = 0);
  color(byte r, byte g, byte b);

  unsigned char r, g, b;
};

extern const color COLOR_BLACK;
extern const color COLOR_RED;
extern const color COLOR_GREEN;
extern const color COLOR_YELLOW;
extern const color COLOR_BLUE;
extern const color COLOR_MAGENTA;
extern const color COLOR_CYAN;
extern const color COLOR_WHITE;


#endif
