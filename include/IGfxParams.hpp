//
// IGfxParams.hpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:11:45 2015 Ambroise Coutarel
// Last update Fri Mar 27 11:24:46 2015 Ambroise Coutarel
//

#ifndef IGFXPARAMS_H_

# define IGFXPARAMS_H_

#include "leSnake.hpp"

typedef struct	s_dump
{
  int		win_x;
  int		win_y;
  int		bpp;
  int		endian;
  int		sizeline;
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*img;
  leSnake	*snake;
}		dump;

class	IGfxParams
{
public:
  IGfxParams(int win_x, int win_y, leSnake *snek);
  dump		data;
  virtual	~IGfxParams() {};
  virtual int	gameLoop() {return 0;};
};

#endif /*!IGFXPARAMS_H_*/
