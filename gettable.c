/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 15:23:11 by tchezier          #+#    #+#             */
/*   Updated: 2015/06/09 18:04:22 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*getz(char *line, int *zval, int *nbcases)
{
	int		cases;
	int		len;
	char	**linesplit;

	cases = 0;
	len = 0;
	*nbcases = 0;
	linesplit = ft_strsplit(line, ' ');
	//ft_putendl("the split was did.");
	len = tablen((void **)linesplit);
	/*ft_putstr("len : ");
	ft_putnbr(len);
	ft_putchar('\n');
	ft_putendl("len was calculated.");*/
	zval = (int *)malloc(sizeof(int) * (len + 1));
	//ft_putendl("we malloced this line");
	while (*linesplit != NULL)
	{
	  zval[cases] = ft_atoi(*linesplit);
	  cases++;
	  linesplit++;
	}
	//ft_putendl("we now have this line");
	*nbcases = len;
	//ft_putendl("nbcases");
	linesplit = linesplit - cases;
	freetab(&linesplit, cases);
	return (zval);
}

int		**gettable(int const file, int **zval, int **nbcases)
{
  int		back;
  char	*line;
  int		linen;
  
  linen = 0;
  while ((back = get_next_line(file, &line)) == 1)
  {
	  //ft_putendl("start");
    if (line != NULL)
    {
      zval[linen] = getz(line, zval[linen], (&(*nbcases)[linen]));
      free(line);
      /*ft_putstr("nbcases left : ");
      ft_putnbr((*nbcases)[linen]);
      ft_putchar('\n');*/
      linen++;
      //ft_putendl("finish");
    }
  }
  if (back == 0)
  {
	  /*ft_putstr("linen : ");
    ft_putnbr(linen);
    ft_putchar('\n');
    ft_putendl("leaving");*/
    if (line)
      free(line);
    //ft_putendl("we successfully got the z values contained in the file");
    return (zval);
  }
  //ft_putendl("an error occured during the reading of the file.");
  if (!*line)
    free(line);
  return (NULL);
}
