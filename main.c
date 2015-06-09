/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 13:33:01 by tchezier          #+#    #+#             */
/*   Updated: 2015/04/07 10:35:49 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int		linenb;
	char	*file;
	t_env	e;

	if (argc == 4)
	{
	  file = ft_strdup(argv[1]);
	  linenb = read_linenb(file);
	  ft_putstr("so, our file is containing ");
	  ft_putnbr(linenb);
	  ft_putendl(" lines, now we can create an int table which contain the z values for each cases.");
	  e.zval = (int **)malloc(sizeof(int *) * (linenb + 1));
	  e.nbcases = (int *)malloc(sizeof(int) * linenb);
	  e.zval[linenb + 1] = NULL;
	  e.zval = read_table(file, e.zval, &e.nbcases);
	  e.res[0] = ft_atoi(argv[2]);
	  e.res[1] = ft_atoi(argv[3]);
	  ft_putendl("we calculate ");
	  ft_putstr("e.res : ");
	  ft_putnbr(((int)e.res[0]));
	  ft_putchar('\n');
	  ft_putstr("e.nbcases : ");
	  ft_putnbr(e.nbcases[0]);
	  ft_putchar('\n');
	  e.taille = ((int)e.res[0] / 1.15) / (e.nbcases[0] * 0.95);
	  ft_putendl("terminated");
	  free(file);
	  ft_win(e.res[0], e.res[1], &e);
	}
	else
	  ft_putendl("You have to put in first argument the file name, in second argument the x value of the resolution you want and in third argument the y value of the resolution you want !");
	return (0);
}
