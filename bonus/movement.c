/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:33:25 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 19:24:14 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_encounter_enemy_v(t_program *prg, char next_place, int offset,
		char my_place)
{
	if (next_place == 'X' || next_place == 'F' || next_place == 'Y')
	{
		if (next_place == 'Y')
		{
			prg->game_status = 0;
		}
		if (my_place == 'H')
			prg->map.map_arr[prg->player.y
				- offset][prg->player.x] = get_enemy_type(prg->map);
		else
			prg->map.map_arr[prg->player.y - offset][prg->player.x] = '0';
		prg->map.map_arr[prg->player.y][prg->player.x] = 'H';
		return (1);
	}
	if (my_place == 'H')
	{
		prg->map.map_arr[prg->player.y
			- offset][prg->player.x] = get_enemy_type(prg->map);
		prg->map.map_arr[prg->player.y][prg->player.x] = 'P';
		return (1);
	}
	return (0);
}

int	handle_player_move_vertical(t_program *prg, int offset)
{
	char	next_place;
	char	my_place;

	next_place = prg->map.map_arr[prg->player.y + offset][prg->player.x];
	my_place = prg->map.map_arr[prg->player.y][prg->player.x];
	if (next_place == '1')
		return (0);
	check_for_coins(prg, next_place);
	handle_all_move(prg);
	if (check_for_ending(prg, next_place) == 1)
	{
		if (offset == 1)
			prg->player_anim.offset = 11;
		else
			prg->player_anim.offset = 10;
		prg->player.y = prg->player.y + offset;
		if (handle_encounter_enemy_v(prg, next_place, offset, my_place) == 0)
		{
			prg->map.map_arr[prg->player.y][prg->player.x] = 'P';
			prg->map.map_arr[prg->player.y - offset][prg->player.x] = '0';
		}
	}
	return (1);
}

int	handle_encounter_enemy_h(t_program *prg, char next_place, int offset,
		char my_place)
{
	if (next_place == 'X' || next_place == 'F' || next_place == 'Y')
	{
		if (next_place == 'Y')
			prg->game_status = 0;
		if (prg->enemy[0].offset >= 15)
			prg->game_status = 0;
		if (my_place == 'H')
			prg->map.map_arr[prg->player.y][prg->player.x
				- offset] = get_enemy_type(prg->map);
		else
			prg->map.map_arr[prg->player.y][prg->player.x - offset] = '0';
		prg->map.map_arr[prg->player.y][prg->player.x] = 'H';
		return (1);
	}
	if (my_place == 'H')
	{
		prg->map.map_arr[prg->player.y][prg->player.x
			- offset] = get_enemy_type(prg->map);
		prg->map.map_arr[prg->player.y][prg->player.x] = 'P';
		return (1);
	}
	return (0);
}

void	handle_change_left_right(t_program *prg, int offset)
{
	if (offset == 1)
	{
		prg->player_anim.offset = 8;
		if (prg->player.left_or_right == 1 && free_frames(prg,
				&(prg->player_anim), 7))
			init_player_right(prg);
	}
	else
	{
		prg->player_anim.offset = 9;
		if (prg->player.left_or_right == 0 && free_frames(prg,
				&(prg->player_anim), 7))
			init_player_left(prg);
	}
	prg->player.x = prg->player.x + offset;
}

int	handle_player_move_horizontal(t_program *prg, int offset)
{
	char	next_place;
	char	my_place;

	next_place = prg->map.map_arr[prg->player.y][prg->player.x + offset];
	my_place = prg->map.map_arr[prg->player.y][prg->player.x];
	if (next_place == '1')
		return (0);
	check_for_coins(prg, next_place);
	handle_all_move(prg);
	if (check_for_ending(prg, next_place) == 1)
	{
		handle_change_left_right(prg, offset);
		if (handle_encounter_enemy_h(prg, next_place, offset, my_place) == 0)
		{
			prg->map.map_arr[prg->player.y][prg->player.x] = 'P';
			prg->map.map_arr[prg->player.y][prg->player.x - offset] = '0';
		}
	}
	return (1);
}
