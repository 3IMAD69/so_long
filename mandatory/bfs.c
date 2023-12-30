/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:22:29 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 17:54:17 by idhaimy          ###   ########.fr       */
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

void	bfs_helper(t_program *prg, t_queue *bfsq, t_position cur, char **map)
{
	int			i;
	int			dx[4];
	int			dy[4];
	t_position	neighbor;

	i = -1;
	initialize_offsets(dx, dy);
	while (++i < 4)
	{
		if (map[cur.x_row + dx[i]][cur.y_colum + dy[i]] == 'E')
			bfsq->exit_found = 1;
		if (cur.x_row + dx[i] >= 0 && cur.x_row + dx[i] < prg->map.rows
			&& cur.y_colum + dy[i] >= 0 && cur.y_colum + dy[i] < prg->map.colums
			&& map[cur.x_row + dx[i]][cur.y_colum + dy[i]] != '7'
			&& map[cur.x_row + dx[i]][cur.y_colum + dy[i]] != '1'
			&& map[cur.x_row + dx[i]][cur.y_colum + dy[i]] != 'E')
		{
			if (map[cur.x_row + dx[i]][cur.y_colum + dy[i]] == 'C')
				bfsq->total_bfs_coins++;
			map[cur.x_row + dx[i]][cur.y_colum + dy[i]] = '7';
			neighbor = (t_position){cur.x_row + dx[i], cur.y_colum + dy[i]};
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
	map[prg->player.y][prg->player.x] = '7';
	bfsq.queue[bfsq.rear++] = (t_position){prg->player.y, prg->player.x};
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
