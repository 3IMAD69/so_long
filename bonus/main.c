/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:37 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 16:09:18 by idhaimy          ###   ########.fr       */
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

void	init_entity(t_program *prg, t_animation *animation, char *folderr,
		int frames)
{
	int		i;
	char	file_path[100];
	char	*number;

	i = 0;
	animation->offset = 0;
	while (i <= frames)
	{
		number = ft_itoa(i);
		ft_strlcpy(file_path, folderr, sizeof(file_path));
		ft_strlcat(file_path, number, sizeof(file_path));
		ft_strlcat(file_path, ".xpm", sizeof(file_path));
		animation->frames_arr[i] = mlx_xpm_file_to_image(prg->mlx, file_path,
				&(animation->img_widght), &(animation->img_height));
		free(number);
		i++;
	}
}

void	init_all_entities(t_program *prg)
{
	init_entity(prg, &(prg->coin), "./bonus/animation/coin/coin", 4);
	init_entity(prg, &(prg->snow), "./bonus/animation/snow/snow", 4);
	init_entity(prg, &(prg->enemy[0]), "./bonus/animation/enemy/bear_trap/bear",
		17);
	init_entity(prg, &(prg->enemy[1]), "./bonus/animation/enemy/fire_trap/fire",
		17);
	init_entity(prg, &(prg->death_scene),
		"./bonus/animation/death_scene/death_scene", 125);
	init_entity(prg, &(prg->dolphin_anim),
		"./bonus/animation/enemy/dolphin/dolphin", 6);
	init_entity(prg, &(prg->door_animation), "./bonus/animation/door/door", 58);
}

int	main(int argc, char *argv[])
{
	t_program	prg;

	ft_printf("Welcome to my game\n");
	if (argc < 2)
		print_error("Missing map !!");
	else if (argc > 2)
		print_error("Two Many Argument. Only one map needed!");
	else if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		print_error("Wrong Map Extention!");
	read_map(argv[1], &prg, &(prg.map));
	prg.mlx = mlx_init();
	prg.win = mlx_new_window(prg.mlx, prg.height, prg.width,
			"So_long Bonus Edition");
	prg.player.moves = 0;
	prg.player.coins_collected = 0;
	prg.frames = 0;
	prg.game_status = 1;
	prg.player_attacking = 0;
	init_all_entities(&prg);
	init_player_right(&prg);
	init_move_player(&prg);
	mlx_key_hook(prg.win, key_hook, &prg);
	mlx_loop_hook(prg.mlx, ft_animation, &prg);
	mlx_hook(prg.win, 17, 0, close_prg, &prg);
	mlx_loop(prg.mlx);
}
