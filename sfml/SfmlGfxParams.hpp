//
// SdlGfxParams.hpp for  in /home/ganesha/projets/cpp_nibbler/sdl
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 30 14:45:36 2015 Ambroise Coutarel
// Last update Wed Apr  1 14:18:40 2015 Ambroise Coutarel
//

#ifndef SDLGFXPARAMS_H_

#define SDLGFXPARAMS_H_

# include <SFML/System.hpp>
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include "../include/IGfxParams.hpp"
# include "../include/leSnake.hpp"

# define GROUND 0x00FFFF87
# define SNEKHEAD 0x003FF527
# define SNEKBOD 0x00DD27F5
# define FOOD 0x0027F5CF
# define LEFT_INC(x) (x == 3 ? 0 : (x + 1))
# define RIGHT_DEC(x) (x == 0 ? 3 : (x - 1))

typedef std::vector<std::pair<int, int> > bodyVector;

class SfmlGfxParams : public IGfxParams
{
public:
  SfmlGfxParams(int win_x, int win_y, leSnake *snek);
  ~SfmlGfxParams();
  int			gameLoop();
  int			sfmlWait(sf::RenderWindow *window);
  int			drawSnake(sf::RenderWindow *window);
  int			SfmlKeyEvents(sf::Event event, sf::RenderWindow *window);
  int			move_snake(char dir, sf::RenderWindow *window);
};

extern "C"
{
  IGfxParams	*init_lib(int win_x, int win_y, leSnake *snek);
}

#endif /* !SDLGFXPARAMS_H_ */
