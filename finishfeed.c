/*
** finishfeed.c for finishfeed in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Thu Feb  6 15:19:49 2014 david tran
** Last update Sat Feb  8 17:55:49 2014 david tran
*/

#include "list.h"

void	middfeed(t_struct vals, int *j, int *x, t_booly *booh)
{
  int	y;
  int	i;

  y = vals.may * 2 + 1;
  i = (vals.may + 1) * y;
  while (*j <= ((vals.midd - vals.pars - 1) + (y * *x)) && *j != i)
    {
      booh[*j].status = 0;
      *j = *j + 1;
    }
  while (*j < ((vals.pars + vals.midd + 1) + (y * *x)) && *j != i)
    {
      booh[*j].status = 1;
      booh[*j].bolly = 0;
      *j = *j + 1;
    }
  while (*j <= ((y - 1) + (y * *x)) && *j != i)
    {
      booh[*j].status = 0;
      *j = *j + 1;
    }
}

void	endfeed(t_struct vals, int *j, int *x, t_booly *booh)
{
  int	y;
  int	i;

  y = vals.may * 2 + 1;
  i = (vals.may + 1) * y;
  while (*j <= ((y - 1) + (y * *x)) &&
	 *j != (i - (y - (vals.max - vals.may * vals.may))))
    {
      booh[*j].status = 1;
      booh[*j].bolly = 0;
      *j = *j + 1;
    }
  while (*j <= ((y - 1) + (y * *x)))
    {
      booh[*j].status = 0;
      *j = *j + 1;
    }
}
