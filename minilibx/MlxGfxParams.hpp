//
// MlxGfxParams.hpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:21:12 2015 Ambroise Coutarel
// Last update Wed Mar 25 13:21:05 2015 Ambroise Coutarel
//

#ifndef MLXGFXPARAMS_H_

# define MLXGFXPARAMS_H_

# include "../include/IGfxParams.hpp"
# include "../include/leSnake.hpp"

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

class MlxGfxParams : public IGfxParams
{
public:
  dump		data;
  // void	*mlx_ptr;
  // void	*win_ptr;
  // void	*img_ptr;

  // public:
  // char	*img;
  // leSnake	*snake;
  MlxGfxParams(int win_x, int win_y, leSnake *snek);
  ~MlxGfxParams();
  static int		move_snake(char dir, dump *data);
  // int		expose_redraw();
  // int		key_event(int keycode);
  static int		expose_redraw(dump *data);
  static int		key_event(int keycode, dump *data);
  //dump		*getData();
  static int		updateImg(dump *data);
  //int		updateImg();
  int		gameLoop();
  int		getWin_x() const;
  int		getWin_y() const;
  int		getBpp() const;
  int		getSizeline() const;
  int		getEndian() const;
  // void		*getMlxPtr() const;
  // void		*getWinPtr() const;
  // void		*getImgPtr() const;
};
#endif
