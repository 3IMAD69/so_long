/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:46 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/27 09:53:18 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "includes/get_next_line/get_next_line.h"
# include "includes/libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_animation
{
	int				frames;
	int				img_widght;
	int				img_height;
	unsigned int	offset;
	void			*frames_arr[200];
}					t_animation;

typedef struct s_player
{
	int				x;
	int				y;
	int				coins_collected;
	void			*img_ptr;
	int				moves;
	int				left_or_right;
}					t_player;

typedef struct s_map
{
	int				coin;
	int				exit;
	int				player_pos;
	int				rows;
	int				colums;
	char			**map_arr;
}					t_map;

typedef struct s_program
{
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	t_map			map;
	t_player		player;
	int				frames;
	void			*wall_ptr;
	void			*wall_darker_ptr;
	int				*dolphins_direction;
	int				game_status;
	t_animation		coin;
	t_animation		wall_animated;
	t_animation		snow;
	t_animation		player_anim;
	t_animation		enemy[2];
	t_animation		dolphin_anim;
	t_animation		death_scene;
	t_animation		door_animation;
	int				player_attacking;
}					t_program;

typedef struct s_frames
{
	unsigned int	coin_frame;
	unsigned int	snow_frame;
	unsigned int	player_frame;
	unsigned int	enemy_frame;
	unsigned int	door_frame;
	unsigned int	dolphin_frame;
	int				death_frame;
}					t_frames;

typedef struct s_position
{
	int				x_row;
	int				y_colum;
}					t_position;

int					key_hook(int keycode, t_program *prg);
int					close_x(int keycode, t_program *prg);
void				validate_map(char **my_map, int rows);
void				check_map_character(char **my_map, int rows,
						t_program *prg);
void				free_my_map(char **my_map, int rows);
int					print_error(char *str);
t_position			get_entity_pos(char **map, int rows, char c);
void				floodfill_checker(char **map, int rows, int colums,
						t_position entity);
void				check_map_if_enclosed(char **my_map, int rows, int colums);
void				check_if_all_coins_reachable(char **real_map,
						char **fake_map, int rows);
char				**create_copy_map(char **map, int rows, int colums);
void				display_map(t_program prg, t_map map, t_player *player);

void				handle_all_move(t_program *prg);
void				check_for_coins(t_program *prg, char next_place);
int					check_for_ending(t_program *prg, char next_place);
int					handle_player_move_vertical(t_program *prg, int offset);
int					handle_player_move_horizontal(t_program *prg, int offset);
void				play_sound_async(char *path);
int					ft_animation(t_program *prg);
void				handle_status_printed(t_program *prg);

void				init_player_left(t_program *prg);
void				init_player_right(t_program *prg);
void				init_move_player(t_program *prg);
void				init_second_enemy(char **my_map, int rows);
char				get_enemy_type(t_program prg, t_map map);
void				move_dolphin(t_program *prg);
void				init_dolphins_direction_arr(t_program *prg, char **my_map,
						int rows);
void				free_my_game(t_program *prg);

void				handle_attack(int keycode, t_program *prg);
void				init_player_attack_right(t_program *prg);
void				init_player_attack_left(t_program *prg);
int					free_frames(t_program *prg, t_animation *animation,
						int size);
void				handle_frames_attack(t_program *prg);
void				validate_and_init(char **my_map, int i, t_program *prg,
						t_map *map);
void				read_map_helper(char ***my_map, char *buffer, int i);
void				*ft_realloc(void *ptr, size_t size, size_t old_size);
#endif