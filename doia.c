/*
** doia.c for doia in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Feb  6 16:06:15 2014 david tran
** Last update Sun Feb 16 05:18:50 2014 david tran
*/

#include "list.h"

void	initia(t_struct *vals, t_booly *booh)
{
  int	w;
  int	y;
  int	count;
  int	perm;

  perm = 0;
  y = vals->may * 2 + 1;
  w = 0;
  while (w <= vals->may)
    {
      vals->pars = 0;
      count = 0;
      while ((vals->pars + (y * w)) < (y + (y * w)))
	{
	  if (booh[vals->pars + (y * w)].status == 1)
	    count++;
	  vals->pars++;
	}
      if (perm < count)
	perm = count;
      w++;
    }
  vals->x = perm;
  checkia(vals, booh);
}

void	checkia(t_struct *vals, t_booly *booh)
{
  int	count;
  int	total;
  int	mult;

  mult = 2;
  total = checkfinal(*vals, booh);
  if (total % 2 == 1)
    {
      count = 2;
      if (count > vals->x)
	count = 1;
      while (count * mult <= vals->x)
	mult++;
    }
  else
    {
      count = 3;
      if (total == 2)
	count = 1;
      else if (count > vals->x)
	count = 1;
      while (count * mult <= vals->x)
	mult++;
    }
  execia(vals, booh, count * (mult - 1));
}

void	execia(t_struct *vals, t_booly *booh, int count)
{
  int	i;
  int	j;
  int	mult;

  mult = 0;
  i = 0;
  j = 0;
  while (i != vals->x)
    {
      i = 0;
      while (j != (vals->may * 2 + 1) + ((vals->may * 2 + 1) * mult))
	{
	  if (booh[j].status == 1)
	    i++;
	  if (i == vals->x)
	    {
	      prefinalize(vals, booh, count, mult);
	      return ;
	    }
	  j++;
	}
      mult++;
    }
  vals->y = count;
  finalizeia(vals, booh, mult - 1);
}

void	finalizeia(t_struct *vals, t_booly *booh, int line)
{
  int	i;
  int	x;

  x = 0;
  i = 0;
  while (i != vals->y)
    {
      if (booh[x + ((vals->may * 2 + 1) * line)].status == 0)
	x++;
      else
	{
	  booh[x + ((vals->may * 2 + 1) * line)].status = 0;
	  tputs(tgoto(vals->tget->movecurs, x, line), 1, my_putchar);
	  my_putstr("\e[0;31mx\e[0;37m");
	  x++;
	  i++;
	}
    }
  vals->pars = 0;
  iffinalia(vals, booh);
}

void			iffinalia(t_struct *vals, t_booly *booh)
{
  struct termios	t;

  vals->turn++;
  affturn(*vals, booh);
  if (checkfinal(*vals, booh) == 0)
    {
      free(booh);
      tcgetattr(0, &t);
      my_putstr("-------------CPU LOST------------\n");
      tputs(vals->tget->endhide, 1, my_putchar);
      get_back(&t);
      exit(1);
    }
}
