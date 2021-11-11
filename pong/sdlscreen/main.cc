#include <iostream>
#include <cstdlib>
#include <algorithm>

#include <SDL/SDL.h>

#include "screen.h"

//--------------------------------------------------
// Compilation command:
//
// alias g++ -Wall -Wextra -pedantic -g -Wold-style-cast -Woverloaded-virtual -std=c++98
// g++ main.cc shape.cc screen.cc -lSDL
//
//--------------------------------------------------

int main()
{
  if ( SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0 )
  {
    std::cerr << "Unable to init SDL: " << SDL_GetError() << std::endl;
    exit(1);
  }
  atexit(SDL_Quit);

  std::cout << "INSTRUCTIONS" << std::endl
            << "------------" << std::endl
            << "- The application window must be in focus to work." << std::endl
            << "- Press ESCAPE or 'q' to quit." << std::endl;
    
  Screen screen(10, 64, 48);
  screen.setColor(0x00000000);
  
  SDL_Event event;
  SDL_Rect  selection = { 0, 0, 64, 48};
  bool done = false;
//  bool buttonheld = false;
    
  while ( ! done )
  {
    SDL_WaitEvent(&event);
//    std::cerr << "event id " << event.type << std::endl;
    
    switch (event.type)
    {
      case SDL_KEYDOWN:
      {
        switch (event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
          case SDLK_q:
            done = true;
            break;
            
          default:
            break;
        }
        break;
      }

      case SDL_MOUSEBUTTONDOWN:
      {
//        buttonheld = true;
        std::cout << "Mouse button " << event.button.button
                  << " pressed at (" << event.button.x
                  << ", "            << event.button.y
                  << ")" << std::endl;
        selection.x = event.button.x;
        selection.y = event.button.y;
        break;
      }
      case SDL_MOUSEMOTION:
      {
        std::cout << "Mouse moved by " << event.motion.xrel
                  << "," << event.motion.yrel
                  << " to (" << event.motion.x
                  << "," << event.motion.y
                  << ")" << std::endl; 
        break;
      }
      case SDL_MOUSEBUTTONUP:
      {
//        buttonheld = false;
        std::cout << "Mouse button "  << event.button.button
                  << " released at (" << event.button.x
                  << ", "             << event.button.y
                  << ")" << std::endl;
        
        selection.w = abs(selection.x - event.button.x);
        selection.h = abs(selection.y - event.button.y);
        selection.x = std::min(int(selection.x), int(event.button.x));
        selection.y = std::min(int(selection.y), int(event.button.y));

        // round up to even points
        selection.w = (selection.w + screen.getPointSize() - 1)/screen.getPointSize();
        selection.h = (selection.h + screen.getPointSize() - 1)/screen.getPointSize();

        // round down to even points
        selection.x /= screen.getPointSize();
        selection.y /= screen.getPointSize();

        std::cout << "Selected x=" << selection.x
                  << ", y=" << selection.y
                  << ", w=" << selection.w
                  << ", h=" << selection.h
                  << std::endl;

        // highlight area slightly
        screen.setColor(0xCCCCCC00);
        screen.fillArea(selection.x, selection.y,
                        selection.w, selection.h);
        screen.setColor(0x00000000);
        break;
      }
/*
      case SDL_WINDOWEVENT:
      {
        printf("Window %d exposed", event.window.windowID);
        shapes.updateAll(screen);
        break;
      }
*/      
      case SDL_QUIT:
      {
        done = true;
        break;
      }
    }
  }
  
  return 0;
}
