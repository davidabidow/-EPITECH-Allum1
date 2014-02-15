/*
** calclines.c for calclines in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Jan 31 15:04:57 2014 david tran
** Last update Sat Feb 15 12:44:07 2014 david tran
*/

#include "list.h"

int		calclines(t_struct *vals)
{
  int		tmline;

  tmline = 0;
  while ((tmline * tmline) < vals->max)
    tmline++;
  return (tmline);
}

void		prefinalize(t_struct *vals, t_booly *booh, int count, int mult)
{
  vals->y = count;
  finalizeia(vals, booh, mult);
}
