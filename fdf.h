/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:39:55 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/10 13:40:20 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>

# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 800

typedef struct s_projection
{
	double		x;
	double		y;
}				t_projection;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_data;

typedef struct s_fdf
{
	int			**arr;
	int			nb_line;
	int			*nb_int_line;
	int			zoom;
	int			x;
	int			y;
	t_data		data;
}				t_fdf;

typedef struct s_draw_line
{
	int			dx;
	int			dy;
	int			ex;
	int			ey;
	int			distx;
	int			disty;
	int			xincr;
	int			yincr;
}				t_draw_line;

void			ft_count_line(char *str, t_fdf *fdf);
void			ft_count_int_line(char *str, t_fdf *fdf);
int				ft_parsing(char *av, t_fdf *fdf);
int				ft_check_extension(const char *str);
int				ft_read_extension(char *av);

t_projection	ft_projection(int x, int y, int z, t_fdf **fdf);

void			ft_free_split(char **arr, int i);
void			ft_free_arr(t_fdf *fdf);

void			img_pix_put(t_img *img, int x, int y, int color);
void			ft_draw_line(t_projection point, int x2, int y2, t_fdf **fdf);

int				ft_deal_key(int key, t_fdf **fdf);
int				ft_close(t_fdf **fdf);

int				ft_init(t_fdf *fdf);
char			**ft_init_fill_tab(t_fdf *fdf, t_fdf *test, char *str);
void			ft_init_line(t_draw_line *d_line);

#endif