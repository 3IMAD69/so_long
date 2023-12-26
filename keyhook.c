/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:10:35 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/26 16:19:58 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	play_sound_async(char *path)
{
	char	command[256];

	ft_strlcpy(command, "afplay ", sizeof(command));
	ft_strlcat(command, path, sizeof(command));
	ft_strlcat(command, " &", sizeof(command));
	system(command);
}

void	handle_frames_attack(t_program *prg)
{
	if (prg->player_attacking == 1 && prg->player_anim.offset == 7
		&& free_frames(prg, &(prg->player_anim), 7))
	{
		prg->player_attacking = 0;
		if (prg->player.left_or_right == 0)
			init_player_right(prg);
		else
			init_player_left(prg);
	}
}

void	handle_status_printed(t_program *prg)
{
	char	*coins_char;
	char	*coins_string;
	char	*moves_char;
	char	*moves_string;

	moves_char = ft_itoa(prg->player.moves);
	moves_string = ft_strjoin("MOVES : ", moves_char);
	mlx_string_put(prg->mlx, prg->win, 0, 0, 0xFFFFFFFF, moves_string);
	coins_char = ft_itoa(prg->player.coins_collected);
	coins_string = ft_strjoin("COINS : ", coins_char);
	mlx_string_put(prg->mlx, prg->win, (prg->map.colums - 1.5) * 64, 0,
		0xFFFFFFFF, coins_string);
	free(coins_char);
	free(moves_char);
	free(moves_string);
	free(coins_string);
}

int	key_hook(int keycode, t_program *prg)
{
	if (keycode == 53)
		free_my_game(prg);
	if (keycode == 13)
		handle_player_move_vertical(prg, -1);
	if (keycode == 1)
		handle_player_move_vertical(prg, 1);
	if (keycode == 2)
		handle_player_move_horizontal(prg, 1);
	if (keycode == 0)
		handle_player_move_horizontal(prg, -1);
	handle_attack(keycode, prg);
	return (0);
}

int	close_x(int keycode, t_program *prg)
{
	printf("%d => cloosing", prg->frames);
	return (0);
}
