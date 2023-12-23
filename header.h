/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:46 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/23 09:51:11 by idhaimy          ###   ########.fr       */
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
	int		frames;
	int 	img_widght;
	int 	img_height;
	unsigned int		offset;
	void 	**frames_arr[60];
}		t_animation;

typedef struct s_player 
{
	int x;
	int y;
	int coins_collected;
	void 	*img_ptr;
	int		moves;
	int 	left_or_right;
}			t_player;

typedef struct s_map
{
	int		coin;
	int		exit;
	int		player_pos;
	int		rows;
	int		colums;
	char	**map_arr;
}			t_map;

typedef struct s_program
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	t_map 	map;
	t_player player;
	int 	frames;
	void  	*wall_ptr;
	void 	*wall_darker_ptr;
	void 	*door_ptr;

	
	t_animation coin;
	t_animation wall_animated;
	t_animation snow;
	t_animation player_anim;
	t_animation enemy[5];
}			t_program;


typedef struct s_position
{
	int		x_row;
	int		y_colum;
}			t_position;


int			key_hook(int keycode,t_program *prg);
int			close_prg(t_program *);
void		validate_map(char **my_map, int rows);
void		check_map_character(char **my_map, int rows,t_program *prg);
void		free_my_map(char **my_map, int rows);
int			print_error(char *str);
t_position	get_entity_pos(char **map, int rows, char c);
void		floodfill_checker(char **map, int rows, int colums,
				t_position entity);
void		check_map_if_enclosed(char **my_map, int rows, int colums);
void		check_if_all_coins_reachable(char **real_map, char **fake_map,
				int rows);
char		**create_copy_map(char **map, int rows, int colums);
void 	display_map(t_program prg,t_map map,t_player *player);

void handle_all_move(t_program *prg);
void check_for_coins(t_program *prg,char next_place);
int check_for_ending(t_program *prg,char next_place);
int handle_player_move_vertical(t_program *prg,int offset);
int handle_player_move_horizontal(t_program *prg,int offset);
void playSoundAsync(char *path);
int 		ft_animation(t_program *prg);
void handle_status_printed(t_program *prg);

void init_player_left(t_program *prg);
void init_player_right(t_program *prg);

void printMap(char **map, int rows, int columns);

#endif