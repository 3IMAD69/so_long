/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:46 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/18 12:49:09 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H


#include "includes/libft/libft.h"
#include "includes/get_next_line/get_next_line.h"

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>

typedef struct	s_program {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}				t_program;

typedef struct	s_map {
	int space;
	int wall;
	int coin;
	int exit;
	int player_pos;
	int rows;
	int colums;
}				t_map;

typedef struct s_position {
	int x_row;
	int y_colum;
}				t_position;


int	key_hook(int keycode, t_program *vars);
int	close_prg(void);
void validate_map(char **my_map,int rows);
void check_map_character(char **my_map,int rows);
void free_my_map(char **my_map,int rows);
int print_error(char *str);
t_position get_entity_pos(char **map,int rows,char c);
void floodfill_checker(char **map,int rows, int colums,t_position entity);
void check_map_if_enclosed(char **my_map,int rows,int colums);
void check_if_all_coins_reachable(char **real_map,char **fake_map,int rows);
char **create_copy_map(char **map,int rows,int colums);
#endif