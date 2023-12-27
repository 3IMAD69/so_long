/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:36:35 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/27 21:44:18 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	floodfill_recursive(char **map, int rows, int colums, int xrow,
		int ycolum)
{
	if (xrow < 0 || ycolum < 0 || xrow >= rows || ycolum >= colums
		|| (map[xrow][ycolum] != '0' && map[xrow][ycolum] != 'E'
			&& map[xrow][ycolum] != 'C' && map[xrow][ycolum] != 'P'
			&& map[xrow][ycolum] != 'X' && map[xrow][ycolum] != 'Y'))
		return ;
	if (map[xrow][ycolum] == 'E' && (map[xrow][ycolum] = 'B'))
		return ;
	map[xrow][ycolum] = '7';
	floodfill_recursive(map, rows, colums, xrow - 1, ycolum);
	floodfill_recursive(map, rows, colums, xrow + 1, ycolum);
	floodfill_recursive(map, rows, colums, xrow, ycolum - 1);
	floodfill_recursive(map, rows, colums, xrow, ycolum + 1);
}

void	floodfill_checker(t_program *prg, int rows, int colums,
		t_position entity)
{
	t_position	exit_pos;
	char		**copy_map;

	copy_map = create_copy_map(prg->map.map_arr, rows, colums);
	exit_pos = get_entity_pos(prg->map.map_arr, rows, 'E');
	floodfill_recursive(copy_map, rows, colums, entity.x_row, entity.y_colum);
	if (copy_map[exit_pos.x_row][exit_pos.y_colum] == 'B')
	{
		check_if_all_coins_reachable(prg->map.map_arr, copy_map, rows, prg->fd);
		free_my_map(copy_map, rows, -2);
	}
	else
	{
		printf("Bad Map !\n");
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
	printf("Border Fine!\n");
}
