#include "header.h"

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

void diplay_enemy_and_player(t_program prg,t_map map)
{
    int i;
    int j;

    i = 0;
     while (i < map.rows)
    {
        j = 0;
        while (map.map_arr[i][j] != '\0')
        {
            if (ft_strchr("H",map.map_arr[i][j]))
            {
                printf("l9it H\n");
                display_helper_with_frame(prg,map,"H",prg.enemy[0].frames_arr[prg.enemy[0].offset]);
                display_helper_with_frame(prg,map,"H",prg.player_anim.frames_arr[prg.player_anim.offset]);
            }
            j++;
        }
        i++;
    }
    
}

void display_map(t_program prg,t_map map,t_player *player)
{
    display_helper_with_frame(prg,map,"0CPXH",prg.wall_ptr);
    display_helper_with_frame(prg,map,"1",prg.wall_darker_ptr);
    display_helper_with_frame(prg,map,"E",prg.door_ptr);
    display_helper_with_frame(prg,map,"C",prg.coin.frames_arr[prg.coin.offset]);
    display_helper_with_frame(prg,map,"P",prg.player_anim.frames_arr[prg.player_anim.offset]);
    display_helper_with_frame(prg,map,"X",prg.enemy[0].frames_arr[prg.enemy[0].offset]);
    display_helper_with_frame(prg,map,"10PCHEX",prg.snow.frames_arr[prg.snow.offset]);
    diplay_enemy_and_player(prg,map);
    //display_helper_with_frame(prg,map,"1",prg.wall_animated.frames_arr[frame_offset]);
}