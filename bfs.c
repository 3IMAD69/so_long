/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:22:29 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/29 17:11:50 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_offsets(int *dx, int *dy)
{
	dx[0] = -1;
	dy[0] = 0;
	dx[1] = 1;
	dy[1] = 0;
	dx[2] = 0;
	dy[2] = -1;
	dx[3] = 0;
	dy[3] = 1;
}

void	bfs_helper(t_program *prg, t_queue *bfsq, t_position current,
		char **map)
{
	int			i;
	int			dx[4];
	int			dy[4];
	t_position	neighbor;

	i = -1;
	initialize_offsets(dx, dy);
	while (++i < 4)
	{
		if (current.x_row + dx[i] >= 0 && current.x_row + dx[i] < prg->map.rows
			&& current.y_colum + dy[i] >= 0 && current.y_colum
			+ dy[i] < prg->map.colums && map[current.x_row
				+ dx[i]][current.y_colum + dy[i]] != '7' && map[current.x_row
				+ dx[i]][current.y_colum + dy[i]] != '1')
		{
			if (map[current.x_row + dx[i]][current.y_colum + dy[i]] == 'C')
				bfsq->total_bfs_coins++;
			if (map[current.x_row + dx[i]][current.y_colum + dy[i]] == 'E')
				bfsq->exit_found = 1;
			map[current.x_row + dx[i]][current.y_colum + dy[i]] = '7';
			neighbor = (t_position){current.x_row + dx[i], current.y_colum
				+ dy[i]};
			bfsq->queue[bfsq->rear++] = neighbor;
		}
	}
}

int	bfs(t_program *prg, char **map, int total_coins)
{
	t_queue		bfsq;
	t_position	current;

	ft_memset(&bfsq, 0, sizeof(bfsq));
	bfsq.queue = (t_position *)malloc(prg->map.rows * prg->map.colums
			* sizeof(t_position));
	map[prg->player.x][prg->player.x] = '7';
	bfsq.queue[bfsq.rear++] = (t_position){prg->player.x, prg->player.y};
	while (bfsq.front < bfsq.rear)
	{
		current = bfsq.queue[bfsq.front++];
		if (bfsq.exit_found == 1 && total_coins == bfsq.total_bfs_coins)
		{
			free(bfsq.queue);
			return (1);
		}
		bfs_helper(prg, &bfsq, current, map);
	}
	free(bfsq.queue);
	return (0);
}
