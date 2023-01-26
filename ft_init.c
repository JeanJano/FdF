/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:23:33 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/10 13:42:05 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_init_fill_tab(t_fdf *fdf, t_fdf *test, char *str)
{
	char	**tab;

	ft_count_line(str, fdf);
	test->arr = malloc(test->nb_line * sizeof(int *));
	if (test->arr == NULL)
		return (NULL);
	tab = ft_split(str, '\n');
	ft_count_int_line(str, fdf);
	return (tab);
}

int	ft_init(t_fdf *fdf)
{
	fdf->zoom = 10;
	fdf->x = 50;
	fdf->y = 50;
	fdf->data.mlx_ptr = mlx_init();
	if (fdf->data.mlx_ptr == NULL)
		return (0);
	fdf->data.win_ptr = mlx_new_window(fdf->data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (fdf->data.win_ptr == NULL)
	{
		free(fdf->data.win_ptr);
		return (0);
	}
	return (1);
}

void	ft_init_line(t_draw_line *d_line)
{
	(*d_line).dx = 2 * (*d_line).ex;
	(*d_line).dy = 2 * (*d_line).ey;
	(*d_line).distx = (*d_line).ex;
	(*d_line).disty = (*d_line).ey;
	(*d_line).xincr = 1;
	(*d_line).yincr = 1;
}
