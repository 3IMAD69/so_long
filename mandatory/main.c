/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:37 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 11:06:26 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_realloc(void *ptr, size_t size, size_t old_size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

void	validate_and_init(char **my_map, int i, t_program *prg, t_map *map)
{
	validate_map(my_map, i, prg->fd);
	check_map_character(my_map, i, prg);
	check_map_if_enclosed(my_map, i, ft_strlen(my_map[0]), prg->fd);
	prg->height = ft_strlen(my_map[0]) * 64;
	prg->width = i * 64;
	map->map_arr = my_map;
	map->rows = i;
	map->colums = ft_strlen(my_map[0]);
	bfs_checker(prg, i, ft_strlen(my_map[0]));
}

void	read_map(char *argv, t_program *prg, t_map *map)
{
	char	*buffer;
	char	**my_map;
	int		i;

	i = 0;
	my_map = NULL;
	prg->fd = open(argv, O_RDONLY);
	if (prg->fd == -1)
		print_error("Map Not Found!");
	buffer = get_next_line(prg->fd);
	while (buffer)
	{
		read_map_helper(&my_map, buffer, i);
		i++;
		buffer = get_next_line(prg->fd);
	}
	validate_and_init(my_map, i, prg, map);
	close(prg->fd);
}

void	init_game(t_program *prg)
{
	int	image_width;
	int	image_height;

	prg->wall = mlx_xpm_file_to_image(prg->mlx, "./textures/wall.xpm",
			&image_width, &image_height);
	prg->wall2 = mlx_xpm_file_to_image(prg->mlx, "./textures/wall2.xpm",
			&image_width, &image_height);
	prg->coin = mlx_xpm_file_to_image(prg->mlx, "./textures/coin.xpm",
			&image_width, &image_height);
	prg->door = mlx_xpm_file_to_image(prg->mlx, "./textures/door.xpm",
			&image_width, &image_height);
	prg->player_texture = mlx_xpm_file_to_image(prg->mlx,
			"./textures/player.xpm", &image_width, &image_height);
}

int	main(int argc, char *argv[])
{
	t_program	prg;

	printf("Welcome to my game\n");
	if (argc < 2)
		print_error("Missing map !!");
	else if (argc > 2)
		print_error("Two Many Argument. Only one map needed!");
	else if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		print_error("Wrong Map Extention '.ber'");
	read_map(argv[1], &prg, &(prg.map));
	prg.mlx = mlx_init();
	prg.win = mlx_new_window(prg.mlx, prg.height, prg.width,
			"So_long Mandatory Edition");
	prg.player.moves = 0;
	init_game(&prg);
	display_map(prg, prg.map, &(prg.player));
	mlx_key_hook(prg.win, key_hook, &prg);
	mlx_hook(prg.win, 17, 0, close_prg, &prg);
	mlx_loop(prg.mlx);
}
