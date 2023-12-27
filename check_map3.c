/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:41:00 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/27 21:44:23 by idhaimy          ###   ########.fr       */
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

void	check_if_all_coins_reachable(char **real_map, char **fake_map, int rows,
		int fd)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (real_map[i][j] != '\0')
		{
			if (real_map[i][j] == 'C' && fake_map[i][j] != '7')
			{
				free_my_map(real_map, rows, fd);
				free_my_map(fake_map, rows, -2);
				print_error("Coins Are Not Reachable!!");
			}
			j++;
		}
		i++;
	}
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
	floodfill_checker(prg, i, ft_strlen(my_map[0]), get_entity_pos(my_map, i,
			'P'));
	init_second_enemy(my_map, i);
	init_dolphins_direction_arr(prg, my_map, i);
	prg->height = ft_strlen(my_map[0]) * 64;
	prg->width = i * 64;
	map->rows = i;
	map->colums = ft_strlen(my_map[0]);
}
