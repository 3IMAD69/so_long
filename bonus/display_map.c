/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:42:27 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/29 17:21:20 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_helper_with_frame(t_program prg, t_map map, char *characters,
		void *frame)
{
	int	i;
	int	j;
	int	img_width;
	int	img_height;

	i = 0;
	img_width = 0;
	img_height = 0;
	while (i < map.rows)
	{
		j = 0;
		while (map.map_arr[i][j] != '\0')
		{
			if (ft_strchr(characters, map.map_arr[i][j]))
			{
				mlx_put_image_to_window(prg.mlx, prg.win, frame, (j * 64), (i
						* 64));
			}
			j++;
		}
		i++;
	}
}

char	get_enemy_type(t_map map)
{
	int	i;
	int	j;
	int	traps;

	traps = 0;
	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (map.map_arr[i][j] != '\0')
		{
			if (map.map_arr[i][j] == 'X' || map.map_arr[i][j] == 'F')
				traps++;
			if (map.map_arr[i][j] == 'H')
			{
				if (traps % 2 == 0)
					return ('X');
				else
					return ('F');
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	diplay_enemy_and_player(t_program prg, t_map map)
{
	int		i;
	int		j;
	char	trap_type;

	trap_type = get_enemy_type(map);
	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (map.map_arr[i][j] != '\0')
		{
			if ((j++) && ft_strchr("H", map.map_arr[i][j]))
			{
				if (trap_type == 'X')
					display_helper_with_frame(prg, map, "H",
						prg.enemy[0].frames_arr[prg.enemy[0].offset]);
				else
					display_helper_with_frame(prg, map, "H",
						prg.enemy[1].frames_arr[prg.enemy[1].offset]);
				display_helper_with_frame(prg, map, "H",
					prg.player_anim.frames_arr[prg.player_anim.offset]);
			}
		}
		i++;
	}
}

void	display_map(t_program prg, t_map map)
{
	display_helper_with_frame(prg, map, "0CPXHFYE", prg.wall_ptr);
	display_helper_with_frame(prg, map, "1", prg.wall_darker_ptr);
	display_helper_with_frame(prg, map, "E",
		prg.door_animation.frames_arr[prg.door_animation.offset]);
	display_helper_with_frame(prg, map, "C",
		prg.coin.frames_arr[prg.coin.offset]);
	display_helper_with_frame(prg, map, "P",
		prg.player_anim.frames_arr[prg.player_anim.offset]);
	display_helper_with_frame(prg, map, "X",
		prg.enemy[0].frames_arr[prg.enemy[0].offset]);
	display_helper_with_frame(prg, map, "F",
		prg.enemy[1].frames_arr[prg.enemy[1].offset]);
	display_helper_with_frame(prg, map, "Y",
		prg.dolphin_anim.frames_arr[prg.dolphin_anim.offset]);
	display_helper_with_frame(prg, map, "10PCHEXFY",
		prg.snow.frames_arr[prg.snow.offset]);
	diplay_enemy_and_player(prg, map);
}
