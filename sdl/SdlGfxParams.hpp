//
// SdlGfxParams.hpp for  in /home/ganesha/projets/cpp_nibbler/sdl
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 30 14:45:36 2015 Ambroise Coutarel
// Last update Mon Mar 30 16:56:23 2015 Ambroise Coutarel
//

#ifndef SDLGFXPARAMS_H_

#define SDLGFXPARAMS_H_

# include <SDL.h>
# include "../include/IGfxParams.hpp"
# include "../include/leSnake.hpp"

# define GROUND 0x00FFFF87
# define SNEKHEAD 0x003FF527
# define SNEKBOD 0x00DD27F5
# define FOOD 0x0027F5CF

typedef std::vector<std::pair<int, int> > bodyVector;

class SdlGfxParams : public IGfxParams
{
public:
  SdlGfxParams(int win_x, int win_y, leSnake *snek);
  ~SdlGfxParams();
  int		gameLoop();
  int		sdlWait();
  int		drawSnake(SDL_Surface *window);
};

extern "C"
{
  IGfxParams	*init_lib(int win_x, int win_y, leSnake *snek);
}

#endif /* !SDLGFXPARAMS_H_ */
