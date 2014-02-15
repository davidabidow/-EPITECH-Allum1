/*
** my_putstr.c for my_putstr.c in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Jan 31 11:20:26 2014 david tran
** Last update Thu Feb  6 09:45:04 2014 david tran
*/

#include "list.h"

int	my_putchar(int c)
{
  write(1, &c, 1);
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i++;
    }
  return (i);
}

int	dogent(int a)
{
  if (a == -1)
    {
      my_putstr("No found\n");
      return (1);
    }
  else if (a == 0)
    {
      my_putstr("TGETENT isn't possible\n");
      return (1);
    }
  return (0);
}

void	my_putstr(char *str)
{
  if (str == NULL)
    exit(EXIT_FAILURE);
  if (write(1, str, my_strlen(str)) == -1)
    exit(EXIT_FAILURE);
}
