/*
** presskeys.c for presskeys in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Wed Feb  5 13:25:14 2014 david tran
** Last update Sat Feb 15 21:54:54 2014 david tran
*/

#include "list.h"

void	calccoord(int *x, int *y, t_struct vals, int *j)
{
  *x = *j;
  *y = 0;
  while (*x >= (vals.may + vals.may + 1))
    {
      *x = *x - (vals.may + vals.may + 1);
      *y = *y + 1;
    }
}

void	goright(t_struct vals, t_booly *booh, int *j)
{
  int	y;
  int	x;

  calccoord(&x, &y, vals, j);
  tputs(tgoto(vals.tget->movecurs, x, y), 1, my_putchar);  
  if (booh[*j].status == 1)
    {
      if (booh[*j].bolly == 0)
	my_putchar('|');
    }
  *j = *j + 1;
  if (*j > ((vals.may + 1) * (vals.may + vals.may + 1) - 1))
    *j = 0;
  while (booh[*j].status == 0)
    {
      if (*j > ((vals.may + 1) * (vals.may + vals.may + 1) - 1))
	*j = 0;
      *j = *j + 1;
    }
  calccoord(&x, &y, vals, j);
  tputs(tgoto(vals.tget->movecurs, x, y), 1, my_putchar);
  tputs(vals.tget->underline, 1, my_putchar);
  if (booh[*j].bolly == 0)
    my_putchar('|');
  tputs(vals.tget->endunder, 1, my_putchar);
}

void	goleft(t_struct vals, t_booly *booh, int *j)
{
  int	x;
  int	y;

  calccoord(&x, &y, vals, j);
  tputs(tgoto(vals.tget->movecurs, x, y), 1, my_putchar);
  if (booh[*j].status == 1)
    {
      if (booh[*j].bolly == 0)
	my_putchar('|');
    }
  *j = *j - 1;
  if (*j < 0)
    *j = (vals.may + 1) * (vals.may + vals.may + 1) - 1;
  while (booh[*j].status == 0)
    {
      if (*j == 0)
	*j = (vals.may + 1) * (vals.may + vals.may + 1);
      *j = *j - 1;
    }
  calccoord(&x, &y, vals, j);
  tputs(tgoto(vals.tget->movecurs, x, y), 1, my_putchar);
  tputs(vals.tget->underline, 1, my_putchar);
  if (booh[*j].bolly == 0)
    my_putchar('|');
  tputs(vals.tget->endunder, 1, my_putchar);
}

void	pressspace(t_struct vals, t_booly *booh, int *j)
{
  int	x;
  int	y;

  if ((x = checkok(vals, booh, j)) == 0)
    {
      calccoord(&x, &y, vals, j);
      tputs(tgoto(vals.tget->movecurs, x, y), 1, my_putchar);
      tputs(vals.tget->revvid, 1, my_putchar);
      my_putchar('|');
      tputs(vals.tget->endrev, 1, my_putchar);
      booh[*j].bolly = 1;
    }
  else if (x == 2)
    {
      calccoord(&x, &y, vals, j);
      tputs(tgoto(vals.tget->movecurs, x, y), 1, my_putchar);
      my_putchar('|');
      booh[*j].bolly = 0;
    }
}

void	pressenter(t_struct *vals, t_booly *booh)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  while (i != ((vals->may + 1) * (vals->may + vals->may + 1)))
    {
      y = 0;
      if (booh[i].status == 1)
	{
	  if (booh[i].bolly == 1)
	    {
	      x = i;
	      booh[i].status = 0;
	      calccoord(&x, &y, *vals, &i);
	      tputs(tgoto(vals->tget->movecurs, x, y), 1, my_putchar);
	      my_putstr("\e[0;34mx\e[0;37m");
	    }
	}
      i++;
    }
  iffinaldo(*vals, booh);
  if (x != 0)
    initia(vals, booh);
}
