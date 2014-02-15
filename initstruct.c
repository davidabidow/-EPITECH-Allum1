/*
** initstruct.c for initstruct in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun Feb  2 14:22:44 2014 david tran
** Last update Mon Feb 10 13:47:04 2014 david tran
*/

#include "list.h"

int	checkargs(char **av)
{
  int	i;
  int	j;

  i = 2;
  j = 0;
  if (av[i] == NULL)
    return (1);
  while (av[i] != NULL)
    {
      while (av[i][j] != 0)
	{
	  if (av[i][j] < 48 || av[i][j] > 57)
	    return (1);
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}

void	gonormal(t_struct *vals)
{
  vals->max = 16;
  vals->may = 3;
  vals->midd = 3;
  vals->x = 3;
  vals->y = 0;
  vals->pars = 0;
  vals->turn = 1;
}

void	gorange(t_struct *vals, char **av)
{
  if (checkargs(av) == 1)
    {
      my_putstr("USAGE: ./allum1 &&/|| [-r || -p]");
      my_putstr("[Number of lines || Number of Allums]\n");
      exit(1);
    }
  vals->may = my_getnbr(av[2]) - 1;
  vals->max = (vals->may + 1) * (vals->may + vals->may + 1);
  if (vals->max == 1 || vals->max == 1)
    {
      my_putstr("--------------YOU LOOSE---------------\n");
      exit(1);
    }
  vals->midd = (vals->may * 2) / 2;
  vals->x = 0;
  vals->y = 0;
  vals->pars = 0;
  vals->turn = 1;
}

void	gonumb(t_struct *vals, char **av)
{
  if (checkargs(av) == 1)
    {
      my_putstr("USAGE: ./allum1 &&/|| [-r || -p]");
      my_putstr("[Number of lines || Number of Allums]\n");
      exit(1);
    }
  vals->max = my_getnbr(av[2]) - 1;
  if (vals->max == 0 || vals->max == -1)
    {
      my_putstr("--------------YOU LOOSE---------------\n");
      exit(1);
    }
  vals->may = calclines(vals) - 1;
  if (vals->may >vals->max)
    {
      my_putstr("Too much lines for alllums \n");
      my_putstr("--------------YOU LOOSE---------------\n");
      exit(1);
    }
  vals->midd = (vals->may * 2) / 2;
  vals->x = 0;
  vals->y = 0;
  vals->pars = 0;
  vals->turn = 1;
}
