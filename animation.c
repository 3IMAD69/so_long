#include "header.h"
#include <sys/time.h> 

void handle_enemy(t_program *prg, unsigned int *enemy_frame)
{
    if (prg->frames % 18 == 0)
    {
        prg->enemy[0].offset = (*enemy_frame)++ % 18;
        prg->enemy[1].offset = (*enemy_frame)++ % 18;
        if (prg->enemy[0].offset >= 15 && prg->map.map_arr[prg->player.y][prg->player.x] == 'H')
        {
            printf("player Offset %d",prg->player_anim.offset);
            prg->player_anim.offset = 0;
            prg->game_status = 0;
        }
    }
}

void handle_end_game(t_program *prg,int *death_frame)
{
    if (*death_frame == 0)
           playSoundAsync("sounds/you-died.mp3");
    mlx_clear_window(prg->mlx, prg->win);
    mlx_put_image_to_window(prg->mlx, prg->win, prg->death_scene.frames_arr[*death_frame], ((prg->map.colums) - 3.75) * 32, ((prg->map.rows) - 3.75) * 32);
    if (*death_frame >= 125)
    {
        sleep(2);
        free_my_game(prg);
        system("leaks so_long");
        exit(0);
    }
    else
        (*death_frame)++;
}
int ft_animation(t_program *prg)
{
    static t_frames frm;
    
    if ((prg->frames++) == 0)
        ft_memset(&frm,0,sizeof(frm));
    if (frm.coin_frame >= 100)
        ft_memset(&frm,0,4*4);
    if (prg->game_status == 1)
    {
        if (prg->frames % 5 == 0)
        {
            mlx_clear_window(prg->mlx,prg->win);
            display_map(*prg,prg->map,&(prg->player));
            prg->coin.offset = frm.coin_frame++ % 5;
            prg->snow.offset = frm.snow_frame++ % 5;
            prg->player_anim.offset = frm.player_frame++ % 8;
            prg->dolphin_anim.offset = frm.dolphin_frame++ % 7;
        }
        handle_enemy(prg,&(frm.enemy_frame));
        if (prg->frames % 50 == 0)
            move_dolphin(prg);
        handle_status_printed(prg);
    }
    else
        handle_end_game(prg,&(frm.death_frame));
    return (0);
}
