/*
** otherkeys.c for otherkeys in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed Feb  5 21:16:06 2014 david tran
** Last update Sat Feb 15 12:46:06 2014 david tran
*/

#include "list.h"

void			iffinaldo(t_struct vals, t_booly *booh)
{
  int			x;
  struct termios	t;

  if ((x = checkfinal(vals, booh)) == 0)
    {
      tcgetattr(0, &t);
      my_putstr("-----------YOU LOST-----------\n");
      free(booh);
      tputs(vals.tget->endhide, 1, my_putchar);
      get_back(&t);
      exit(1);
    }
  else if (x == 1)
    {
      tcgetattr(0, &t);
      my_putstr("-----------CPU LOST-----------\n");
      free(booh);
      tputs(vals.tget->endhide, 1, my_putchar);
      get_back(&t);
      exit(1);
    }
}

int	checkok(t_struct vals, t_booly *booh, int *j)
{
  int	i;
  int	x;
  int	w;
  int	y;
  int	z;

  i = 0;
  while (i != ((vals.may + 1) * (vals.may * 2 + 1)))
    {
      y = 0;
      if (booh[i].status == 1)
	{
	  if (booh[i].bolly == 1)
	    {
	      calccoord(&w, &y, &vals, &i);
	      calccoord(&x, &z, &vals, j);
	      if (y == z && w == x)
		return (2);
	      else if (y == z)
		return (0);
	      else
		return (1);
	    }
	}
      i++;
    }
  return (0); 
}

int	checkfinal(t_struct vals, t_booly *booh)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  while (i != ((vals.may + 1) * (vals.may * 2 + 1)))
    {
      if (booh[i].status == 1)
	y++;
      i++;
    }
  return (y);
}

void	pressup(t_struct *vals, t_booly *booh, int *j)
{
  int	x;
  int	y;

  calccoord(&x, &y, vals, j);
  tputs(tgoto(vals->tget->movecurs, x, y), 1, my_putchar);
  if (booh[*j].status == 1)
    {
      if (booh[*j].bolly == 0)
	my_putchar('|');
    }
  *j = *j + (vals->may * 2 + 1);
  if (*j > ((vals->may + 1) * (vals->may * 2 + 1) - 1))
    *j = 0;
  while (booh[*j].status == 0)
    {
      if (*j > ((vals->may + 1) * (vals->may * 2 + 1) - 1))
	*j = 0;
      *j = *j + 1;
    }
  calccoord(&x, &y, vals, j);
  tputs(tgoto(vals->tget->movecurs, x, y), 1, my_putchar);
  tputs(vals->tget->underline, 1, my_putchar);
  if (booh[*j].bolly == 0)
    my_putchar('|');
  tputs(vals->tget->endunder, 1, my_putchar);
}

void	pressdown(t_struct *vals, t_booly *booh, int *j)
{
  int	x;
  int	y;

  calccoord(&x, &y, vals, j);
  tputs(tgoto(vals->tget->movecurs, x, y), 1, my_putchar);
  if (booh[*j].status == 1)
    {
      if (booh[*j].bolly == 0)
	my_putchar('|');
    }
  *j = *j - (vals->may * 2 + 1);
  if (*j < 0)
    *j = (vals->may + 1) * (vals->may * 2 + 1) - 1;
  while (booh[*j].status == 0)
    {
      if (*j == 0)
	*j = (vals->may + 1) * (vals->may * 2 + 1) - 1;
      *j = *j - 1;
    }
  calccoord(&x, &y, vals, j);
  tputs(tgoto(vals->tget->movecurs, x, y), 1, my_putchar);
  tputs(vals->tget->underline, 1, my_putchar);
  if (booh[*j].bolly == 0)
    my_putchar('|');
  tputs(vals->tget->endunder, 1, my_putchar);
}
