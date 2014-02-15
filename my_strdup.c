/*
** my_strdup.c for my_strdup in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Jan 31 11:15:37 2014 david tran
** Last update Tue Feb 11 14:09:33 2014 david tran
*/

#include "list.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_strdup(char *src)
{
  char	*str2;
  int	b;

  b = my_strlen(src);
  if ((str2 = malloc((b + 1) * sizeof(char))) == NULL)
    exit(1);
  my_strcpy(str2, src);
  return (str2);
}
