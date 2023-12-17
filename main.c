/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:37 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/17 11:43:26 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int print_error(char *str)
{
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

void read_map(char *map)
{
    char *buffer;
    char **my_map = NULL;
    int i = 0;
    int rows_allocated = 0;
    int fd = open(map,O_RDONLY);
    
    if (fd == -1)
        print_error("Map Not Found!");
    while ((buffer = get_next_line(fd)))
    {
        my_map = ft_realloc(my_map,(rows_allocated + 1) * sizeof(char *),(rows_allocated) * sizeof(char *));
        my_map[i] = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
        if (!my_map[i])
            print_error("Allocation failed");
        ft_strlcpy(my_map[i],buffer,ft_strlen(buffer) + 1);
        free(buffer);
        i++;
        rows_allocated++;
    }
    int j = 0;
    while(j < i)
    {
        printf("%c", my_map[j][20]);
        j++;
    }
     // Free the allocated memory
    for (j = 0; j < i; j++)
    {
        free(my_map[j]);
    }
    free(my_map);
    // if (buffer)
    //     printf("%s",buffer);
    close(fd);
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
    read_map(argv[1]);

    prg.mlx = mlx_init();
    prg.win = mlx_new_window(prg.mlx,640,480,"Window xXx");

    // void *img;
    // int img_width = 0;
    // int img_height = 0 ;

    // img = mlx_xpm_file_to_image(prg.mlx,"./textures/LAVAROCKS.xpm",&img_width,&img_height);
    // if (!img)
    //     print_error("Failed to read img");
    // mlx_put_image_to_window(prg.mlx,prg.win,img,0,50);



    mlx_key_hook(prg.win,key_hook,&prg);
    mlx_hook(prg.win, 17, 0, close_prg, &prg);
    mlx_loop(prg.mlx);
}
