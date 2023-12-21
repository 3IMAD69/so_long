#include "header.h"


void display_helper(t_program prg,t_map map,char *path,char *characters)
{
    int i;
    int j;
    int img_width;
    int img_height;
    void *img_ptr;

    i = 0;
    img_width = 0;
    img_height = 0;
    img_ptr = mlx_xpm_file_to_image(prg.mlx, path, &img_width, &img_height);
    while (i < map.rows)
    {
        j = 0;
        while (map.map_arr[i][j] != '\0')
        {
            if (ft_strchr(characters,map.map_arr[i][j]))
            {
                mlx_put_image_to_window(prg.mlx,prg.win,img_ptr,(j * 64),(i * 64));
            }
            j++;
        }
        i++;
    }
}

void display_helper_with_frame(t_program prg,t_map map,char *characters,void *frame)
{
    int i;
    int j;
    int img_width;
    int img_height;

    i = 0;
    img_width = 0;
    img_height = 0;
    while (i < map.rows)
    {
        j = 0;
        while (map.map_arr[i][j] != '\0')
        {
            if (ft_strchr(characters,map.map_arr[i][j]))
            {
                mlx_put_image_to_window(prg.mlx,prg.win,frame,(j * 64),(i * 64));
            }
            j++;
        }
        i++;
    }
}


void display_player(t_program prg,t_map map,char *path,t_player *player)
{
    int i;
    int j;
    int img_width;
    int img_height;
    void *img_ptr;

    i = 0;
    img_width = 0;
    img_height = 0;
    img_ptr = mlx_xpm_file_to_image(prg.mlx, path, &img_width, &img_height);
    player->img_ptr = img_ptr;
    mlx_put_image_to_window(prg.mlx,prg.win,img_ptr,(player->x * 64),(player->y * 64));
}

void display_map(t_program prg,t_map map,t_player *player,int frame_offset)
{
    display_helper(prg,map,"./textures/wall.xpm","0CP");
    display_helper(prg,map,"./textures/wall3.xpm","1");
    display_helper(prg,map,"./textures/door.xpm","E");
    //display_helper(prg,map,"./textures/chicken.xpm","C");
    //display_helper(prg,map,"./animation/coin/coin0.xpm","C");
    display_helper_with_frame(prg,map,"C",prg.coin.frames_arr[frame_offset]);
    display_player(prg,map,"./textures/player.xpm",player);
    
}