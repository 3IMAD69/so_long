/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:41:00 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/29 17:17:08 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**create_copy_map(char **map, int rows, int colums)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = (char **)malloc(rows * sizeof(char *));
	while (i < rows)
	{
		copy_map[i] = (char *)malloc(colums + 1 * sizeof(char));
		ft_strlcpy(copy_map[i], map[i], colums + 1);
		i++;
	}
	return (copy_map);
}

int	get_coins_count(char **real_map, int rows)
{
	int	i;
	int	j;
	int	coins;

	coins = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (real_map[i][j] != '\0')
		{
			if (real_map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

void	init_second_enemy(char **my_map, int rows)
{
	int	i;
	int	j;
	int	offset;

	offset = 1;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (my_map[i][j] != '\0')
		{
			if (ft_strchr("X", my_map[i][j]))
			{
				if ((offset % 2) == 0)
					my_map[i][j] = 'F';
				offset++;
			}
			j++;
		}
		i++;
	}
}

void	init_dolphins_direction_arr(t_program *prg, char **my_map, int rows)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (my_map[i][j] != '\0')
		{
			if (my_map[i][j] == 'Y')
				counter++;
			j++;
		}
		i++;
	}
	prg->dolphins_direction = (int *)ft_calloc(counter, sizeof(int));
}

void	validate_and_init(char **my_map, int i, t_program *prg, t_map *map)
{
	validate_map(my_map, i, prg->fd);
	check_map_character(my_map, i, prg);
	check_map_if_enclosed(my_map, i, ft_strlen(my_map[0]), prg->fd);
	prg->map.map_arr = my_map;
	map->rows = i;
	prg->width = i * 64;
	prg->height = ft_strlen(my_map[0]) * 64;
	map->colums = ft_strlen(my_map[0]);
	bfs_checker(prg, i, ft_strlen(my_map[0]));
	init_second_enemy(my_map, i);
	init_dolphins_direction_arr(prg, my_map, i);
}
