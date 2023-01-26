/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:29:42 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/05 13:26:48 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || x < 0 || x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

static void	ft_first_choice(t_img img, t_draw_line *d_line, int x1, int y1)
{
	int	i;

	i = 0;
	while (i <= d_line->distx)
	{
		img_pix_put(&img, x1, y1, 0x00FFFFFF);
		i++;
		x1 += d_line->xincr;
		d_line->ex -= d_line->dy;
		if (d_line->ex < 0)
		{
			y1 += d_line->yincr;
			d_line->ex += d_line->dx;
		}
	}
}

static void	ft_second_choice(t_img img, t_draw_line *d_line, int x1, int y1)
{
	int	i;

	i = 0;
	while (i <= d_line->disty)
	{
		img_pix_put(&img, x1, y1, 0x00FFFFFF);
		i++;
		y1 += d_line->yincr;
		d_line->ey -= d_line->dx;
		if (d_line->ey < 0)
		{
			x1 += d_line->xincr;
			d_line->ey += d_line->dy;
		}
	}
}

void	ft_draw_line(t_projection point, int x2, int y2, t_fdf **fdf)
{
	t_draw_line		d_line;
	t_projection	projection;
	t_projection	projection1;

	projection = ft_projection(point.x, point.y,
			(*fdf)->arr[(int)point.y][(int)point.x], fdf);
	projection1 = ft_projection(x2, y2, (*fdf)->arr[y2][x2], fdf);
	point.x = projection.x;
	point.y = projection.y;
	x2 = projection1.x;
	y2 = projection1.y;
	d_line.ex = abs(x2 - (int)point.x);
	d_line.ey = abs(y2 - (int)point.y);
	ft_init_line(&d_line);
	if (point.x > x2)
		d_line.xincr = -1;
	if (point.y > y2)
		d_line.yincr = -1;
	if (d_line.distx > d_line.disty)
		ft_first_choice((*fdf)->data.img, &d_line, point.x, point.y);
	if (d_line.distx < d_line.disty)
		ft_second_choice((*fdf)->data.img, &d_line, point.x, point.y);
}
