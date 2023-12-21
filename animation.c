#include "header.h"

// ft_coin_animation(t_animation *coin)
// {
//     static int frame;

//     if (frame % 5 == 0)
//     {
//         coin->frames_arr[1];
//     }
//     else
//         coin

//     frame++;
// }


int ft_animation(t_program *prg)
{
    int max = 50;
    static int i = 0;
    prg->frames++;
    mlx_clear_window(prg->mlx,prg->win);
    if (prg->frames < 0)
        prg->frames = 0;
    if (prg->frames % 5 == 0)
    {
        printf ("Mera Kola 50 frames %d\n",prg->frames);
        display_map(*prg,prg->map,&(prg->player),3);
    }
    else
        display_map(*prg,prg->map,&(prg->player),0);
    printf("%d\n",i);
    return (0);
}