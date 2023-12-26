/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_my_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:03:38 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/26 17:37:26 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_error(char *str)
{
	printf("Error\n");
	printf("%s", str);
	exit(0);
}

int	free_frames(t_program *prg, t_animation *animation, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		mlx_destroy_image(prg->mlx, animation->frames_arr[i]);
		i++;
	}
	return (1);
}

void	free_my_game(t_program *prg)
{
	int	i;

	i = 0;
	free(prg->dolphins_direction);
	free_my_map(prg->map.map_arr, prg->map.rows);
	free_frames(prg, &(prg->coin), 4);
	free_frames(prg, &(prg->snow), 4);
	free_frames(prg, &(prg->player_anim), 11);
	free_frames(prg, &(prg->enemy[0]), 17);
	free_frames(prg, &(prg->enemy[1]), 17);
	free_frames(prg, &(prg->dolphin_anim), 6);
	mlx_destroy_image(prg->mlx, prg->wall_ptr);
	mlx_destroy_image(prg->mlx, prg->wall_darker_ptr);
	mlx_destroy_window(prg->mlx, prg->win);
	system("leaks so_long");
	exit(0);
}
