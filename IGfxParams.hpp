//
// IGfxParams.hpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:11:45 2015 Ambroise Coutarel
// Last update Mon Mar 23 15:21:53 2015 Ambroise Coutarel
//

#ifndef IGFXPARAMS_H_

# define IGFXPARAMS_H_

class	IGfxParams
{
private:
  int	win_x;
  int	win_y;
  int	bpp;
  int	sizeline;
  int	endian;

public:
  virtual ~IGfxParams() {};
  virtual getWin_x() const = 0;
  virtual getWin_y() const = 0;
  virtual getBpp() const = 0;
  virtual getSizeline() const = 0;
  virtual getEndian() const = 0;
};

#endif /*!IGFXPARAMS_H_*/
