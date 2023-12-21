/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:37 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/21 12:54:59 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int print_error(char *str)
{
    printf("Error\n");
    printf("%s",str);
    exit(0);
}

void *ft_realloc(void *ptr, size_t size,size_t old_size)
{
    void *new_ptr;

    if (ptr == NULL)
        return malloc(size);
    if (!size)
        return ptr;
    new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;
    ft_memcpy(new_ptr, ptr, old_size);
    free(ptr);

    return new_ptr;
}

void read_map(char *argv,t_program *prg,t_map *map)
{
    char *buffer;
    char **my_map = NULL;
    int i = 0;
    int rows_allocated = 0;
    int fd = open(argv,O_RDONLY);
    
    if (fd == -1)
        print_error("Map Not Found!");
    while ((buffer = get_next_line(fd)))
    {
        my_map = ft_realloc(my_map,(rows_allocated + 1) * sizeof(char *),(rows_allocated) * sizeof(char *));
        if (buffer[ft_strlen(buffer) - 1] == '\n')
            buffer[ft_strlen(buffer) - 1] = '\0';
        my_map[i] = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
        if (!my_map[i])
            print_error("Allocation failed");
        ft_strlcpy(my_map[i],buffer,ft_strlen(buffer) + 1);
        free(buffer);
        i++;
        rows_allocated++;
    }
    validate_map(my_map,rows_allocated);
    check_map_character(my_map,rows_allocated,prg);
    check_map_if_enclosed(my_map,rows_allocated,ft_strlen(my_map[0]));
    floodfill_checker(my_map,rows_allocated,ft_strlen(my_map[0]),get_entity_pos(my_map,rows_allocated,'P'));
    prg->height = ft_strlen(my_map[0]) * 64;
    prg->width = rows_allocated * 64;
    map->map_arr = my_map;
    map->rows = rows_allocated;
    map->colums = ft_strlen(my_map[0]);
    close(fd);
}

void init_coin(t_program *prg)
{
    prg->coin.frames_arr[0] = mlx_xpm_file_to_image(prg->mlx,"./animation/coin/coin0.xpm",&(prg->coin.img_widght),&(prg->coin.img_height));
    prg->coin.frames_arr[1] = mlx_xpm_file_to_image(prg->mlx,"./animation/coin/coin1.xpm",&(prg->coin.img_widght),&(prg->coin.img_height));
    prg->coin.frames_arr[2] = mlx_xpm_file_to_image(prg->mlx,"./animation/coin/coin2.xpm",&(prg->coin.img_widght),&(prg->coin.img_height));
    prg->coin.frames_arr[3] = mlx_xpm_file_to_image(prg->mlx,"./animation/coin/coin3.xpm",&(prg->coin.img_widght),&(prg->coin.img_height));
    prg->coin.frames_arr[4] = mlx_xpm_file_to_image(prg->mlx,"./animation/coin/coin4.xpm",&(prg->coin.img_widght),&(prg->coin.img_height));
    prg->coin.frames_arr[5] = mlx_xpm_file_to_image(prg->mlx,"./animation/coin/coin5.xpm",&(prg->coin.img_widght),&(prg->coin.img_height));
}

int main(int argc,char *argv[])
{
    t_program prg;

    printf("Welcome to my game\n");
    if (argc < 2)
        print_error("Missing map !!");
    else if (argc > 2)
        print_error("Two Many Argument. Only one map needed!");
    else if (!ft_strnstr(argv[1],".ber",ft_strlen(argv[1])))
        print_error("Wrong Map Extention , '.ber' are the only extentions supported!!");
    read_map(argv[1],&prg,&(prg.map));
    prg.mlx = mlx_init();
    prg.win = mlx_new_window(prg.mlx,prg.height,prg.width,"Window xXx");
    prg.player.moves = 0;
    prg.frames = 0;
    init_coin(&prg);
    display_map(prg,prg.map,&(prg.player),0);

    mlx_string_put(prg.mlx,prg.win, 0, 0, 0xFFFFFFFF, "MOVES : 0");
    mlx_string_put(prg.mlx,prg.win, (prg.map.colums - 1.5) * 64, 0, 0xFFFFFFFF, "COINS : 0");
    
    mlx_key_hook(prg.win,key_hook,&prg);
    mlx_loop_hook(prg.mlx,ft_animation,&prg);
    mlx_hook(prg.win, 17, 0, close_prg, &prg);
    mlx_loop(prg.mlx);
    system("leaks so_long");
}
