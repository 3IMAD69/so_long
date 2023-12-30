/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:36:35 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 10:48:40 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	bfs_checker(t_program *prg, int rows, int colums)
{
	char	**copy_map;
	int		total_coins;

	copy_map = create_copy_map(prg->map.map_arr, rows, colums);
	total_coins = get_coins_count(prg->map.map_arr, rows);
	if (bfs(prg, copy_map, total_coins) == 1)
		free_my_map(copy_map, rows, -2);
	else
	{
		free_my_map(prg->map.map_arr, rows, prg->fd);
		free_my_map(copy_map, rows, -2);
		print_error("Exit is Not Reachable!!");
	}
}

t_position	get_entity_pos(char **map, int rows, char c)
{
	int			i;
	int			j;
	t_position	entity;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (c == map[i][j])
			{
				entity.x_row = i;
				entity.y_colum = j;
			}
			j++;
		}
		i++;
	}
	return (entity);
}

void	check_map_if_enclosed_helper(char **my_map, int x, int y, int fd)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (my_map[i][y] != '1')
		{
			free_my_map(my_map, x, fd);
			print_error("Map Invalid , could be an enclosed Map!");
		}
		i++;
	}
}

void	check_map_if_enclosed(char **my_map, int rows, int colums, int fd)
{
	int	i;

	i = 0;
	check_map_if_enclosed_helper(my_map, rows, 0, fd);
	check_map_if_enclosed_helper(my_map, rows, colums - 1, fd);
	while (i < colums)
	{
		if (my_map[0][i] != '1')
		{
			free_my_map(my_map, rows, fd);
			print_error("Map Invalid , could be an enclosed Map!");
		}
		i++;
	}
	i = 0;
	while (i < colums)
	{
		if (my_map[rows - 1][i] != '1')
		{
			free_my_map(my_map, rows, fd);
			print_error("Map Invalid , could be an enclosed Map!");
		}
		i++;
	}
}

void	read_map_helper(char ***my_map, char *buffer, int i)
{
	*my_map = ft_realloc(*my_map, (i + 1) * sizeof(char *), (i)
			* sizeof(char *));
	if (*my_map == NULL)
		print_error("Rellocation failed!");
	if (buffer[ft_strlen(buffer) - 1] == '\n')
		buffer[ft_strlen(buffer) - 1] = '\0';
	(*my_map)[i] = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!(*my_map)[i])
		print_error("Allocation failed");
	ft_strlcpy((*my_map)[i], buffer, ft_strlen(buffer) + 1);
	free(buffer);
}
