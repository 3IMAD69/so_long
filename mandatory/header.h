/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:46 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 14:39:34 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../includes/libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	int			x;
	int			y;
	int			coins_collected;
	void		*img_ptr;
	int			moves;
}				t_player;

typedef struct s_map
{
	int			coin;
	int			exit;
	int			player_pos;
	int			rows;
	int			colums;
	char		**map_arr;
}				t_map;

typedef struct s_program
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	int			fd;
	void		*wall;
	void		*wall2;
	void		*player_texture;
	void		*door;
	void		*coin;
	t_map		map;
	t_player	player;
}				t_program;

typedef struct s_position
{
	int			x_row;
	int			y_colum;
}				t_position;

typedef struct s_queue
{
	t_position	*queue;
	int			front;
	int			rear;
	int			exit_found;
	int			total_bfs_coins;
}				t_queue;

int				key_hook(int keycode, t_program *prg);
int				close_prg(t_program *prg);
void			validate_map(char **my_map, int rows, int fd);
void			check_map_character(char **my_map, int rows, t_program *prg);
void			free_my_map(char **my_map, int rows, int fd);
int				print_error(char *str);
t_position		get_entity_pos(char **map, int rows, char c);
void			check_map_if_enclosed(char **my_map, int rows, int colums,
					int fd);
char			**create_copy_map(char **map, int rows, int colums);
void			display_map(t_program prg, t_map map, t_player *player);
void			display_player(t_program prg, void *frame, t_player *player);
void			handle_all_move(t_program *prg);
void			check_for_coins(t_program *prg, char next_place);
int				check_for_ending(t_program *prg, char next_place);
int				handle_player_move_vertical(t_program *prg, int offset);
int				handle_player_move_horizontal(t_program *prg, int offset);
void			play_sound_async(char *path);
int				get_coins_count(char **real_map, int rows);
void			bfs_checker(t_program *prg, int rows, int colums);
int				bfs(t_program *prg, char **map, int total_coins);
void			free_my_game(t_program *prg);
void			read_map_helper(char ***my_map, char *buffer, int i);
void			*ft_realloc(void *ptr, size_t size, size_t old_size);

#endif