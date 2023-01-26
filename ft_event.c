/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:19:44 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/09 15:56:08 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_move(int key, t_fdf **fdf)
{
	int	zoom;
	int	move;

	zoom = 1;
	move = 2;
	if (key == 61)
		(*fdf)->zoom += zoom;
	if (key == 45)
		(*fdf)->zoom -= zoom;
	if (key == 52)
		(*fdf)->x += move;
	if (key == 51)
		(*fdf)->x -= move;
	if (key == 50)
		(*fdf)->y += move;
	if (key == 49)
		(*fdf)->y -= move;
}

int	ft_close(t_fdf **fdf)
{
	ft_deal_key(XK_Escape, fdf);
	return (0);
}

int	ft_deal_key(int key, t_fdf **fdf)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image((*fdf)->data.mlx_ptr, (*fdf)->data.img.mlx_img);
		mlx_destroy_window((*fdf)->data.mlx_ptr, (*fdf)->data.win_ptr);
		mlx_destroy_display((*fdf)->data.mlx_ptr);
		free((*fdf)->data.mlx_ptr);
		ft_free_arr(*fdf);
		free((*fdf)->nb_int_line);
		free((*fdf));
		exit(0);
	}
	ft_move(key, fdf);
	return (0);
}
