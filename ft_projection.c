/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:41:49 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/05 11:45:36 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_projection	ft_projection(int x, int y, int z, t_fdf **fdf)
{
	t_projection	projection;

	projection.x = (sqrt(2.0) / 2) * (x - y);
	projection.y = (-sqrt(2.0 / 3.0) * z) - ((1 / sqrt(6.0)) * -(x + y));
	projection.x = round((projection.x + (*fdf)->x) * (*fdf)->zoom);
	projection.y = round((projection.y + (*fdf)->y) * (*fdf)->zoom);
	return (projection);
}
