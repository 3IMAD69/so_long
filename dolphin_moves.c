/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dolphin_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:57:13 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/25 08:59:13 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_dolphin_helper2(t_program *prg, int offset, int i, int *j)
{
	char	tmp;

	tmp = prg->map.map_arr[i][*j + offset];
	prg->map.map_arr[i][*j + offset] = 'Y';
	prg->map.map_arr[i][*j] = '0';
	*j = *j + offset;
	if (tmp == 'P')
		prg->game_status = 0;
}

void	move_dolphin_helper(t_program *prg, int dolphin_number, int i, int *j)
{
	if (prg->dolphins_direction[dolphin_number] == 0 && (prg->map.map_arr[i][*j
			+ 1] == '0' || prg->map.map_arr[i][*j + 1] == 'P'))
		move_dolphin_helper2(prg, 1, i, j);
	else if (prg->dolphins_direction[dolphin_number] == 1
		&& (prg->map.map_arr[i][*j - 1] == '0' || prg->map.map_arr[i][*j
		- 1] == 'P'))
		move_dolphin_helper2(prg, -1, i, j);
}

void	set_dolphins_next_direction(t_program *prg, int dolphin_number, int i,
		int j)
{
	if (prg->dolphins_direction[dolphin_number] == 0 && (prg->map.map_arr[i][j
			+ 1] != '0' && prg->map.map_arr[i][j + 1] != 'P'))
		prg->dolphins_direction[dolphin_number] = 1;
	if (prg->dolphins_direction[dolphin_number] == 1 && (prg->map.map_arr[i][j
			- 1] != '0' && prg->map.map_arr[i][j - 1] != 'P'))
		prg->dolphins_direction[dolphin_number] = 0;
}

void	move_dolphin(t_program *prg)
{
	int	i;
	int	j;
	int	dolphin_number;

	dolphin_number = 0;
	i = 0;
	while (i < prg->map.rows)
	{
		j = 0;
		while (prg->map.map_arr[i][j] != '\0')
		{
			if (prg->map.map_arr[i][j] == 'Y')
			{
				move_dolphin_helper(prg, dolphin_number, i, &j);
				set_dolphins_next_direction(prg, dolphin_number, i, j);
				dolphin_number++;
			}
			j++;
		}
		i++;
	}
}
