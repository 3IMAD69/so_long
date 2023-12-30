/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:43:11 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 16:05:32 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_all_move(t_program *prg)
{
	play_sound_async("./bonus/sounds/move_sound.mp3");
	prg->player.moves++;
	ft_printf("Moves -> %d!\n", prg->player.moves);
}

void	check_for_coins(t_program *prg, char next_place)
{
	if (next_place == 'C')
	{
		prg->player.coins_collected++;
		play_sound_async("./bonus/sounds/collect_coin.mp3");
	}
}

int	check_for_ending(t_program *prg, char next_place)
{
	if (next_place == 'E' && prg->player.coins_collected == prg->map.coin)
	{
		play_sound_async("./bonus/sounds/portal_closed.mp3");
		free_my_game(prg);
		exit(0);
	}
	else if (next_place == 'E' && prg->player.coins_collected != prg->map.coin)
	{
		play_sound_async("./bonus/sounds/portal_looked.mp3");
		return (0);
	}
	else
		return (1);
}
