//
// IGfxParams.hpp for nibbler in /home/ganesha/projets/cpp_nibbler
//
// Made by Ambroise Coutarel
// Login   <ganesha@epitech.net>
//
// Started on  Mon Mar 23 15:11:45 2015 Ambroise Coutarel
// Last update Tue Mar 24 13:12:45 2015 Ambroise Coutarel
//

#ifndef IGFXPARAMS_H_

# define IGFXPARAMS_H_

class	IGfxParams
{
protected:
  int	win_x;
  int	win_y;
  int	bpp;
  int	sizeline;
  int	endian;

public:
  virtual	~IGfxParams() {};
  virtual int	getWin_x() const = 0;
  virtual int	getWin_y() const = 0;
  virtual int	getBpp() const = 0;
  virtual int	getSizeline() const = 0;
  virtual int	getEndian() const = 0;
};

#endif /*!IGFXPARAMS_H_*/
