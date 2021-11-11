#include "console.h"

#include <cmath>

int main() {
  Console c;

  SDL_Delay(1000);

  for (int x = 0; x < min(c.getWidth(), c.getHeight()); x++) {
    c.setPos(x, x);
    c.put('a');

    if (c.get() == 'q') return 0;
  }

  while (c.get() != 'q') {}

  return 0;
}
