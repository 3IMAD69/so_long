/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:21:25 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 16:07:54 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_player_right(t_program *prg)
{
	int		i;
	char	file_path[100];
	char	*number;

	i = 0;
	prg->player.left_or_right = 0;
	prg->player_anim.offset = 0;
	while (i <= 7)
	{
		number = ft_itoa(i);
		ft_strlcpy(file_path, "./bonus/animation/player/idle_right/idle",
			sizeof(file_path));
		ft_strlcat(file_path, number, sizeof(file_path));
		ft_strlcat(file_path, ".xpm", sizeof(file_path));
		prg->player_anim.frames_arr[i] = mlx_xpm_file_to_image(prg->mlx,
				file_path, &(prg->player_anim.img_widght),
				&(prg->player_anim.img_height));
		free(number);
		i++;
	}
}

void	init_player_left(t_program *prg)
{
	int		i;
	char	file_path[100];
	char	*number;

	i = 0;
	prg->player.left_or_right = 1;
	prg->player_anim.offset = 0;
	while (i <= 7)
	{
		number = ft_itoa(i);
		ft_strlcpy(file_path, "./bonus/animation/player/idle_left/idle",
			sizeof(file_path));
		ft_strlcat(file_path, number, sizeof(file_path));
		ft_strlcat(file_path, ".xpm", sizeof(file_path));
		prg->player_anim.frames_arr[i] = mlx_xpm_file_to_image(prg->mlx,
				file_path, &(prg->player_anim.img_widght),
				&(prg->player_anim.img_height));
		free(number);
		i++;
	}
}

void	init_player_attack_right(t_program *prg)
{
	int		i;
	char	file_path[100];
	char	*number;

	i = 0;
	while (i <= 7)
	{
		number = ft_itoa(i);
		ft_strlcpy(file_path, "./bonus/animation/player/attack_right/attack",
			sizeof(file_path));
		ft_strlcat(file_path, number, sizeof(file_path));
		ft_strlcat(file_path, ".xpm", sizeof(file_path));
		prg->player_anim.frames_arr[i] = mlx_xpm_file_to_image(prg->mlx,
				file_path, &(prg->player_anim.img_widght),
				&(prg->player_anim.img_height));
		free(number);
		i++;
	}
	prg->player_attacking = 1;
	prg->player_anim.offset = 0;
}

void	init_player_attack_left(t_program *prg)
{
	int		i;
	char	file_path[100];
	char	*number;

	i = 0;
	while (i <= 7)
	{
		number = ft_itoa(i);
		ft_strlcpy(file_path, "./bonus/animation/player/attack_left/attack",
			sizeof(file_path));
		ft_strlcat(file_path, number, sizeof(file_path));
		ft_strlcat(file_path, ".xpm", sizeof(file_path));
		prg->player_anim.frames_arr[i] = mlx_xpm_file_to_image(prg->mlx,
				file_path, &(prg->player_anim.img_widght),
				&(prg->player_anim.img_height));
		free(number);
		i++;
	}
	prg->player_attacking = 1;
	prg->player_anim.offset = 0;
}

void	init_move_player(t_program *prg)
{
	prg->wall_ptr = mlx_xpm_file_to_image(prg->mlx, "./bonus/textures/wall.xpm",
			&(prg->wall_animated.img_widght), &(prg->wall_animated.img_height));
	prg->wall_darker_ptr = mlx_xpm_file_to_image(prg->mlx,
			"./bonus/textures/wall_darker.xpm",
			&(prg->wall_animated.img_widght), &(prg->wall_animated.img_height));
	prg->player_anim.frames_arr[8] = mlx_xpm_file_to_image(prg->mlx,
			"./bonus/animation/player/run_right.xpm",
			&(prg->player_anim.img_widght), &(prg->player_anim.img_height));
	prg->player_anim.frames_arr[9] = mlx_xpm_file_to_image(prg->mlx,
			"./bonus/animation/player/run_left.xpm",
			&(prg->player_anim.img_widght), &(prg->player_anim.img_height));
	prg->player_anim.frames_arr[10] = mlx_xpm_file_to_image(prg->mlx,
			"./bonus/animation/player/run_up.xpm",
			&(prg->player_anim.img_widght), &(prg->player_anim.img_height));
	prg->player_anim.frames_arr[11] = mlx_xpm_file_to_image(prg->mlx,
			"./bonus/animation/player/run_down.xpm",
			&(prg->player_anim.img_widght), &(prg->player_anim.img_height));
}
