/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlinenb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 14:46:37 by tchezier          #+#    #+#             */
/*   Updated: 2015/06/09 18:05:07 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int getlinenb(int const file)
{
  int		linenb;
  int		back;
  char	*line;
  
  linenb = 0;
  //ft_putendl("we are going to calculate the total number of lines the files is containing.");
  while ((back = get_next_line(file, &line)) == 1)
  {
    linenb++;
    //ft_putendl(line);
    if (line)
      free(line);
  }
  if (back == 0)
  {
    //ft_putendl(line);
    return (linenb);
  }
  if (line)
    free(line);
  return (back);
}
