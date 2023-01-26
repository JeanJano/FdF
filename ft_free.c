/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:56:44 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/05 11:24:52 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_split(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

void	ft_free_arr(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->nb_line)
	{
		free(fdf->arr[i]);
		i++;
	}
	free(fdf->arr);
}
