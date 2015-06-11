/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 14:59:46 by tchezier          #+#    #+#             */
/*   Updated: 2015/06/09 16:28:01 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
#include <math.h>

typedef struct s_env
{
  void		*mlx;
  void		*win;
  void		*img;
  char		*addr;
  size_t	res[2];
  size_t	len;
  int		**zval;
  int		*nbcases;
  int		bpp;
  int		sizeline;
  int		endian;
  int		taille;
  int		line;
  int		x;
  int		y;
}				t_env;

void	trace_map(t_env *e, int x, int y);
void	freetab(char ***table, int cases);
int	expose_hook(t_env *e);
int	key_hook(int keycode, t_env *e);
int	ft_win(size_t x, size_t y, t_env *e);
int	getlinenb(int const file);
int	*getz(char *line, int *zval, int *nbcases);
int	**gettable(int const file, int **zval, int **nbcases);
int	tablen(void **table);
int	v_red_line(t_env *e, int x1, int y1, int **var);
int	h_red_line(t_env *e, int x1, int y1, int **var);
int	v_blue_line(t_env *e, int x1, int y1, int **var);
int	h_blue_line(t_env *e, int x1, int y1, int **var);
int	read_linenb(char *file);
int	**read_table(char *file, int **zval, int **nbcases);
int	showz4x(int x, int y, int z);
int	showz4y(int x, int y, int z);
void	sub_trace_map(t_env *e, int **var, int x, int y);
void	swap_try(int *x1, int *x2, int *y1, int *y2);
void	sub_red_line(t_env *e, int *coords, int z);
void	final_h_red_line(t_env *e, int *coords, int z);
void	final_v_red_line(t_env *e, int *coords, int z);
void	sub_blue_line(t_env *e, int *coords);
void	final_h_blue_line(t_env *e, int *coords);
void	final_v_blue_line(t_env *e, int *coords);

#endif
