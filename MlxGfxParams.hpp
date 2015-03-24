//
// MlxGfxParams.hpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:21:12 2015 Ambroise Coutarel
// Last update Mon Mar 23 15:51:20 2015 Ambroise Coutarel
//

#ifndef MLXGFXPARAMS_H_

# define MLXGFXPARAMS_H_

# include "IGfxParams.hpp"

class MlxGfxParams : public IGfxParams
{
private:
  void	*mlx_ptr;
  void	*win_ptr;
  void	*img_ptr;

public:
  char	*img;
  MlxGfxParams(int win_x, int win_y);
  ~MlxGfxParams();
  int	getWin_x() const;
  int	getWin_y() const;
  int	getBpp() const;
  int	getSizeline() const;
  int	getEndian() const;
};

#endif
