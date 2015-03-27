//
// MlxGfxParams.hpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:21:12 2015 Ambroise Coutarel
// Last update Fri Mar 27 12:36:28 2015 Ambroise Coutarel
//

#ifndef MLXGFXPARAMS_H_

# define MLXGFXPARAMS_H_

# include "../include/IGfxParams.hpp"
# include "../include/leSnake.hpp"

# define ESCAPE 65307
# define RIGHT 65363
# define LEFT 65361
# define GROUND 0x001A1A1A
# define SNEKHEAD 0x0000E1FA
# define SNEKBOD 0x00FA00D4
# define FOOD 0x00BA0000
# define LEFT_INC(x) (x == 3 ? 0 : (x + 1))
# define RIGHT_DEC(x) (x == 0 ? 3 : (x - 1))


class MlxGfxParams : public IGfxParams
{
public:
  MlxGfxParams(int win_x, int win_y, leSnake *snek);
  ~MlxGfxParams();
  static int		move_snake(char dir, dump *data);
  static int		expose_redraw(void *data);
  static int		key_event(int keycode, void *data);
  static int		updateImg(dump *data);
  static int		drawSnake(dump *data);
  static int		drawSquare(int x, int y, dump *data);
  static int		my_pixel_put_to_image(int x, int y, dump *data, int color);
  int			gameLoop();
};
#endif
