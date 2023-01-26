/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:05:22 by jsauvage          #+#    #+#             */
/*   Updated: 2022/10/08 14:14:27 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_count_line(char *str, t_fdf *fdf)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\0')
			count++;
		i++;
	}
	fdf->nb_line = count;
}

void	ft_count_int_line(char *str, t_fdf *fdf)
{
	char	**tab;
	char	**tmp;
	int		i;
	int		j;

	tab = ft_split(str, '\n');
	i = 0;
	fdf->nb_int_line = malloc(fdf->nb_line * sizeof(int));
	if (fdf->nb_int_line == NULL)
		return ;
	while (i < fdf->nb_line)
	{
		j = 0;
		tmp = ft_split(tab[i], ' ');
		while (tmp[j])
			j++;
		fdf->nb_int_line[i] = j;
		ft_free_split(tmp, j);
		i++;
	}
	ft_free_split(tab, i);
}

static void	ft_fill_tab(char *str, t_fdf *fdf)
{
	char	**tab;
	char	**tmp;
	int		i[2];
	t_fdf	*test;

	test = fdf;
	tab = ft_init_fill_tab(fdf, test, str);
	i[0] = 0;
	while (tab[i[0]])
	{
		i[1] = 0;
		tmp = ft_split(tab[i[0]], ' ');
		test->arr[i[0]] = malloc(test->nb_int_line[i[0]] * sizeof(int));
		if (test->arr[i[0]] == NULL)
			return ;
		i[1] = 0;
		while (tmp[i[1]])
		{
			test->arr[i[0]][i[1]] = ft_atoi(tmp[i[1]]);
			i[1]++;
		}
		ft_free_split(tmp, i[1]);
		i[0]++;
	}
	ft_free_split(tab, i[0]);
}

char	*ft_newstrjoin(char *str, char *line)
{
	char	*newstr;

	newstr = ft_strjoin(str, line);
	free(str);
	return (newstr);
}

int	ft_parsing(char *av, t_fdf *fdf)
{
	char	*line;
	int		fd;
	char	*str;

	str = ft_calloc(0, 0);
	fd = open(av, O_RDONLY);
	if (fd < 0 || ft_read_extension(av) == 0)
	{
		free(str);
		ft_printf("argument invalide\n");
		return (0);
	}
	line = get_next_line(fd);
	str = ft_newstrjoin(str, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			str = ft_newstrjoin(str, line);
	}
	close(fd);
	ft_fill_tab(str, fdf);
	free(str);
	return (1);
}
