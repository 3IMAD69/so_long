/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:20:25 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 14:30:18 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	attack_vertical(t_program *prg, int offset)
{
	char	attacking_place;
	char	my_place;

	attacking_place = prg->map.map_arr[prg->player.y + offset][prg->player.x];
	my_place = prg->map.map_arr[prg->player.y][prg->player.x];
	if (attacking_place == 'Y' && free_frames(prg, &(prg->player_anim), 7))
	{
		if (prg->player.left_or_right == 0)
			init_player_attack_right(prg);
		else
			init_player_attack_left(prg);
		play_sound_async("./bonus/sounds/katana_sound.mp3");
		prg->map.map_arr[prg->player.y + offset][prg->player.x] = '0';
	}
}

void	attack_horizontal(t_program *prg, int offset)
{
	char	attacking_place;
	char	my_place;

	attacking_place = prg->map.map_arr[prg->player.y][prg->player.x + offset];
	my_place = prg->map.map_arr[prg->player.y][prg->player.x];
	if (attacking_place == 'Y' && free_frames(prg, &(prg->player_anim), 7))
	{
		if (offset == 1)
			init_player_attack_right(prg);
		else
			init_player_attack_left(prg);
		play_sound_async("./bonus/sounds/katana_sound.mp3");
		prg->map.map_arr[prg->player.y][prg->player.x + offset] = '0';
	}
}

void	handle_attack(int keycode, t_program *prg)
{
	if (keycode == 126)
		attack_vertical(prg, -1);
	if (keycode == 125)
		attack_vertical(prg, 1);
	if (keycode == 124)
		attack_horizontal(prg, 1);
	if (keycode == 123)
		attack_horizontal(prg, -1);
}
