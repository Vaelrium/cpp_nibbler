//
// MlxGfxParams.hpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:21:12 2015 Ambroise Coutarel
// Last update Mon Mar 30 16:44:59 2015 Rémi DURAND
//

#ifndef MLXGFXPARAMS_H_

# define MLXGFXPARAMS_H_

# include "../include/IGfxParams.hpp"
# include "../include/leSnake.hpp"

# define LEFT_INC(x) (x == 3 ? 0 : (x + 1))
# define RIGHT_DEC(x) (x == 0 ? 3 : (x - 1))

class NcurGfxParams : public IGfxParams
{
public:
  NcurGfxParams(int win_x, int win_y, leSnake *snek);
  ~NcurGfxParams();
  int			gameLoop();
};

#endif
