#include "header.h"

void free_coin(t_program *prg)
{
    int i;

    i = 0;
    while (i <= 4)
    {
        mlx_destroy_image(prg->mlx,prg->coin.frames_arr[i]);
        i++;
    }
}

void free_snow(t_program *prg)
{
    int i;

    i = 0;
    while (i <= 4)
    {
        mlx_destroy_image(prg->mlx,prg->snow.frames_arr[i]);
        i++;
    }
}

int free_player(t_program *prg,int limit)
{
    int i;

    i = 0;
    while (i <= limit)
    {
        mlx_destroy_image(prg->mlx,prg->player_anim.frames_arr[i]);
        i++;
    }
    return (1);
}

void free_death_scene(t_program *prg)
{
    int i;

    i = 0;
    while (i <= 125)
    {
        mlx_destroy_image(prg->mlx,prg->death_scene.frames_arr[i]);
        i++;
    }
}

void free_dolphin(t_program *prg)
{
    int i;

    i = 0;
    while (i <= 6)
    {
        mlx_destroy_image(prg->mlx,prg->dolphin_anim.frames_arr[i]);
        i++;
    }
}
void free_enemy(t_program *prg)
{
    int i;

    i = 0;
    while (i <= 17)
    {
        mlx_destroy_image(prg->mlx,prg->enemy[0].frames_arr[i]);
        mlx_destroy_image(prg->mlx,prg->enemy[1].frames_arr[i]);
        i++;
    }
}
void free_door(t_program *prg)
{
    int i;

    i = 0;
    while (i <= 58)
    {
        mlx_destroy_image(prg->mlx,prg->door_animation.frames_arr[i]);
        i++;
    }
}




void free_my_game(t_program *prg)
{
    int i;

    i = 0;
    //mlx_clear_window(prg->mlx, prg->win);
    free(prg->dolphins_direction);
    free_my_map(prg->map.map_arr,prg->map.rows);
    free_coin(prg);
    free_snow(prg);
    free_player(prg,11);
    free_enemy(prg);
    free_dolphin(prg);
    mlx_destroy_image(prg->mlx,prg->wall_ptr);
    mlx_destroy_image(prg->mlx,prg->wall_darker_ptr);
     //free_death_scene(prg);
     mlx_destroy_window(prg->mlx,prg->win);
    //free(prg->mlx);
    //free(prg);
    system("leaks so_long");
    exit(0);
}
