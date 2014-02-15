/*
** afffile.c for afffile in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Mon Feb  3 11:47:40 2014 david tran
** Last update Sat Feb 15 21:51:48 2014 david tran
*/

#include "list.h"

void	afffile(t_struct vals, t_booly *booh)
{
  int	i;
  int	x;

  i = 0;
  x = 1;
  while (i != ((vals.may + 1) * (vals.may + vals.may + 1)))
    {
      if (booh[i].status == 1)
	my_putchar('|');
      else
	my_putchar(' ');
      i++;
      if (i == ((vals.may + vals.may + 1) * x))
	{
	  my_putchar('\n');
	  x++;
	}
    }
  makeread(vals, booh);
}

void	fillstruct(t_struct *vals)
{
  vals->tget = malloc(sizeof(t_tget));
  vals->tget->hidecurs = tgetstr("vi", NULL);
  vals->tget->clears = tgetstr("cl", NULL);
  vals->tget->movecurs = tgetstr("cm", NULL);
  vals->tget->underline = tgetstr("us", NULL);
  vals->tget->endunder = tgetstr("ue", NULL);
  vals->tget->revvid = tgetstr("so", NULL);
  vals->tget->endrev = tgetstr("se", NULL);
  vals->tget->endhide = tgetstr("ve", NULL);
}

void	refreshall(t_struct *vals, t_booly *booh, int *j)
{
  free(booh);
  booh = fillin(*vals);
  tputs(vals->tget->clears, 1, my_putchar);
  afffile(*vals, booh);
  vals->turn = 0;
  *j = 0;
}
