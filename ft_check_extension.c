/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:14:17 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/08 14:17:23 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_extension(const char *str)
{
	char	extension[5];
	int		i;

	extension[0] = '.';
	extension[1] = 'f';
	extension[2] = 'd';
	extension[3] = 'f';
	extension[4] = '\0';
	i = 0;
	while (extension[i])
	{
		if (extension[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_read_extension(char *av)
{
	size_t	size;
	int		i;
	char	check[4];

	i = 5;
	size = ft_strlen(av);
	if (size < 4)
		return (0);
	while (i > 0)
	{
		check[i - 1] = av[size];
		i--;
		size--;
	}
	if (ft_check_extension(check) == 0)
		return (0);
	return (1);
}
