/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:19:15 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 19:26:16 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_all_move(t_program *prg)
{
	play_sound_async("./mandatory/sounds/move_sound.mp3");
	prg->player.moves++;
	ft_printf("Moves -> %d!\n", prg->player.moves);
}

void	check_for_coins(t_program *prg, char next_place)
{
	if (next_place == 'C')
	{
		prg->player.coins_collected++;
		play_sound_async("./mandatory/sounds/collect_coin.mp3");
	}
}

int	check_for_ending(t_program *prg, char next_place)
{
	if (next_place == 'E' && prg->player.coins_collected == prg->map.coin)
	{
		play_sound_async("./mandatory/sounds/portal_closed.mp3");
		ft_printf("You won!");
		free_my_game(prg);
	}
	else if (next_place == 'E' && prg->player.coins_collected != prg->map.coin)
	{
		play_sound_async("./mandatory/sounds/portal_looked.mp3");
		return (0);
	}
	return (1);
}

int	handle_player_move_vertical(t_program *prg, int offset)
{
	char	next_place;

	next_place = prg->map.map_arr[prg->player.y + offset][prg->player.x];
	if (next_place == '1')
		return (0);
	check_for_coins(prg, next_place);
	handle_all_move(prg);
	if (check_for_ending(prg, next_place) == 1)
	{
		display_player(*prg, prg->wall, &(prg->player));
		prg->player.y = prg->player.y + offset;
		display_player(*prg, prg->wall, &(prg->player));
		display_player(*prg, prg->player_texture, &(prg->player));
		prg->map.map_arr[prg->player.y][prg->player.x] = 'P';
		prg->map.map_arr[prg->player.y - offset][prg->player.x] = '0';
	}
	return (1);
}

int	handle_player_move_horizontal(t_program *prg, int offset)
{
	char	next_place;

	next_place = prg->map.map_arr[prg->player.y][prg->player.x + offset];
	if (next_place == '1')
		return (0);
	check_for_coins(prg, next_place);
	handle_all_move(prg);
	if (check_for_ending(prg, next_place) == 1)
	{
		display_player(*prg, prg->wall, &(prg->player));
		prg->player.x = prg->player.x + offset;
		display_player(*prg, prg->wall, &(prg->player));
		display_player(*prg, prg->player_texture, &(prg->player));
		prg->map.map_arr[prg->player.y][prg->player.x] = 'P';
		prg->map.map_arr[prg->player.y][prg->player.x - offset] = '0';
	}
	return (1);
}
