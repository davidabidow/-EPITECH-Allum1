/*
** allum1.c for allum1 in /home/tran_0/rendu/CPE_2013_allum1
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Jan 31 10:38:23 2014 david tran
** Last update Tue Feb 11 14:13:54 2014 david tran
*/

#include "list.h"

char	*getvar(char *str)
{
  int	i;
  int	j;
  char	*dest;

  j = 0;
  i = 0;
  while (str[i] != '=')
    i++;
  if ((dest = malloc((my_strlen(str) - i) * sizeof(char))) == NULL)
    return (NULL);
  i++;
  while (str[i] != 0)
    {
      dest[j] = str[i];
      i++;
      j++;
    }
  dest[j] = 0;
  return (dest);
}

char	*getterm(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (env[i][0] == 'T' && env[i][1] == 'E' && env[i][2] == 'R' &&
	  env[i][3] == 'M' && env[i][4] == '=')
	return (getvar(my_strdup(env[i])));
      i++;
    }
  return (NULL);
}

t_struct	checkfonc(int ac, t_struct vals, char **av)
{
  if (ac == 1)
    gonormal(&vals);
  else if (ac == 3 && av[1][0] == '-' && av[1][1] == 'r')
    gorange(&vals, av);
  else if (ac == 3 && av[1][0] == '-' && av[1][1] == 'p')
    gonumb(&vals, av);
  else
    {
      my_putstr("USAGE: ./allum1 &&/|| [-r || -p]");
      my_putstr("[Number of lines || Number of Allums]\n");
      exit(1);
    }
  return (vals);
}

t_booly		*fillin(t_struct vals)
{
  t_booly	*booh;
  int		i;
  int		j;
  int		x;
  int		y;
  
  y = vals.may * 2 + 1;
  x = 0;
  j = 0;
  i = (vals.may + 1) * y;
  if ((booh = malloc((i + 1) * sizeof(*booh))) == NULL)
    exit(1);
  while ((vals.pars + vals.midd) < (y - 1))
    {
      middfeed(vals, &j, &x, booh);
      x++;
      vals.pars++;
    }
  endfeed(vals, &j, &x, booh);
  return (booh);
}

int			main(int ac, char **av, char **environ)
{
  char			*term;
  int			a;
  t_struct		vals;
  t_booly		*booh;

  vals = checkfonc(ac, vals, av);
  booh = fillin(vals);
  if ((term = getterm(environ)) == NULL)
    return (1);
  a = tgetent(NULL, term);
  if (dogent(a) == 1)
    return (1);
  checkwinsize(&vals);
  fillstruct(&vals);
  tputs(vals.tget->hidecurs, 1, my_putchar);
  tputs(vals.tget->clears, 1, my_putchar);
  afffile(vals, booh);
  makeread(vals, booh);
  return (0);
}
