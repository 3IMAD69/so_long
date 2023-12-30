/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:30:23 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 16:05:02 by idhaimy          ###   ########.fr       */
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

int	key_hook(int keycode, t_program *prg)
{
	if (keycode == 53)
		free_my_game(prg);
	if (keycode == 13 || keycode == 126)
		handle_player_move_vertical(prg, -1);
	if (keycode == 1 || keycode == 125)
		handle_player_move_vertical(prg, 1);
	if (keycode == 2 || keycode == 124)
		handle_player_move_horizontal(prg, 1);
	if (keycode == 0 || keycode == 123)
		handle_player_move_horizontal(prg, -1);
	return (0);
}

int	close_prg(t_program *prg)
{
	free_my_map(prg->map.map_arr, prg->map.rows, prg->fd);
	ft_printf("closing the program\n");
	exit(0);
}

void	free_my_game(t_program *prg)
{
	free_my_map(prg->map.map_arr, prg->map.rows, prg->fd);
	mlx_destroy_image(prg->mlx, prg->wall);
	mlx_destroy_image(prg->mlx, prg->wall2);
	mlx_destroy_image(prg->mlx, prg->coin);
	mlx_destroy_image(prg->mlx, prg->door);
	mlx_destroy_image(prg->mlx, prg->player_texture);
	mlx_destroy_window(prg->mlx, prg->win);
	exit(0);
}

int	print_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s", str);
	exit(0);
}
