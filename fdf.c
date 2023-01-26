/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:55:05 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/10 13:40:06 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	ft_print_map(t_fdf *fdf)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < fdf->nb_line)
// 	{
// 		j = 0;
// 		while (j < fdf->nb_int_line[i])
// 		{
// 			ft_printf("%d ", fdf->arr[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }

static void	ft_draw_backgroud(t_fdf **fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y <= WINDOW_WIDTH)
	{
		x = 0;
		while (x <= WINDOW_HEIGHT)
		{
			img_pix_put(&(*fdf)->data.img, y, x, 0x00000000);
			x++;
		}
		y++;
	}
}

static int	ft_draw(t_fdf **fdf)
{
	t_projection	point;

	ft_draw_backgroud(fdf);
	point.y = 0;
	while (point.y < (*fdf)->nb_line)
	{
		point.x = 0;
		while (point.x < (*fdf)->nb_int_line[(int)point.y])
		{
			if (point.x < (*fdf)->nb_int_line[(int)point.y] - 1)
				ft_draw_line(point, point.x + 1, point.y, fdf);
			if (point.y < (*fdf)->nb_line - 1)
				ft_draw_line(point, point.x, point.y + 1, fdf);
			point.x++;
		}
		point.y++;
	}
	mlx_put_image_to_window((*fdf)->data.mlx_ptr, (*fdf)->data.win_ptr,
		(*fdf)->data.img.mlx_img, -1, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		return (1);
	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (1);
	if (ft_parsing(av[1], fdf) == 0)
	{
		free(fdf);
		return (1);
	}
	if (ft_init(fdf) == 0)
		return (1);
	fdf->data.img.mlx_img = mlx_new_image(fdf->data.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	fdf->data.img.addr = mlx_get_data_addr(fdf->data.img.mlx_img,
			&fdf->data.img.bpp, &fdf->data.img.line_len, &fdf->data.img.endian);
	mlx_loop_hook(fdf->data.mlx_ptr, &ft_draw, &fdf);
	mlx_key_hook(fdf->data.win_ptr, ft_deal_key, &fdf);
	mlx_hook(fdf->data.win_ptr, 33, 0, ft_close, &fdf);
	mlx_loop(fdf->data.mlx_ptr);
}
