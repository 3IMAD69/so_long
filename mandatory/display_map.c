/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:26:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 11:07:48 by idhaimy          ###   ########.fr       */
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

void	display_player(t_program prg, void *frame, t_player *player)
{
	int	img_width;
	int	img_height;

	img_width = 0;
	img_height = 0;
	mlx_put_image_to_window(prg.mlx, prg.win, frame, (player->x * 64),
		(player->y * 64));
}

void	display_map(t_program prg, t_map map, t_player *player)
{
	display_helper_with_frame(prg, map, "0CPE", prg.wall);
	display_helper_with_frame(prg, map, "1", prg.wall2);
	display_helper_with_frame(prg, map, "E", prg.door);
	display_helper_with_frame(prg, map, "C", prg.coin);
	display_player(prg, prg.player_texture, player);
}
