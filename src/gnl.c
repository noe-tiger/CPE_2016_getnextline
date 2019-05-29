/*
** gnl.c for  in /home/noe/gnl
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Fri Apr 14 13:36:13 2017 Noé
** Last update Fri Apr 14 14:26:02 2017 Noé
*/

#include "gnl.h"
#include <stdio.h>

int	get_list(const int fd, t_char *list)
{
  int	nb;

  while ((nb = (read(fd, &list->c, 1))) >= 1 && (list->c != '\n'))
    {
      if ((list->next = malloc(sizeof(t_char))) == NULL)
	return (-1);
      list = list->next;
      list->next = NULL;
    }
  return (nb);
}

char		*get_str(t_char *list)
{
  t_char	*sav;
  int		nb;
  char		*str;

  nb = 0;
  sav = list;
  while (list->next != NULL)
    {
      list = list->next;
      nb++;
    }
  if ((str = malloc(sizeof(char) * (nb + 1))) == NULL)
    return (NULL);
  nb = 0;
  while (sav->next != NULL)
    {
      str[nb] = sav->c;
      sav = sav->next;
      nb++;
    }
  str[nb] = 0;
  return (str);
}

char	*get_next_line(const int fd)
{
  static	int	toog = 0;
  t_char		*list;
  char			*str;
  int			nb;

  if ((list = malloc(sizeof(t_char))) == NULL || toog == 1)
    return (NULL);
  list->next = NULL;
  if (nb = get_list(fd, list) == 0)
    toog = 1;
  if (nb == -1)
    return (NULL);
  str = get_str(list);
  return (str);
}
