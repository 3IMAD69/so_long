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
    static unsigned int coin_frame;
    static unsigned int snow_frame;
    static unsigned int player_frame;

    prg->frames++;
    mlx_clear_window(prg->mlx,prg->win);
    if (prg->frames < 0)
        prg->frames = 0;
    if (prg->frames % 5 == 0)
    {
        printf ("Mera Kola 50 frames %d\n",prg->frames);

        display_map(*prg,prg->map,&(prg->player));
        // coin_frame++;
        // snow_frame++;
        // player_frame++;
        //(coin_frame == 5) && (coin_frame = 0);
        //(snow_frame == 5) && (snow_frame = 0);
        //(player_frame == 8) && (player_frame = 0);
        prg->coin.offset = coin_frame++ % 5;
        prg->snow.offset = snow_frame++ % 5;;
        prg->player_anim.offset = player_frame++ % 8;
        printf("coin frame %d\n",coin_frame);
    }
    else
        display_map(*prg,prg->map,&(prg->player));
    handle_status_printed(prg);
    return (0);
}
