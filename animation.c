#include "header.h"
#include <sys/time.h> 
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
    static unsigned int coin_frame;
    static unsigned int snow_frame;
    static unsigned int player_frame;
    static struct timeval start_time;
    int frames_per_second = 0;

    prg->frames++;
    if (prg->frames < 0 || prg->frames > 100)
        prg->frames = 0;
    if (coin_frame >= 100)
    {
        coin_frame = snow_frame = player_frame = 0;
    }

    if (prg->frames == 1) {
        gettimeofday(&start_time, NULL);
    }

    if (prg->frames % 5 == 0)
    {
        mlx_clear_window(prg->mlx,prg->win);
        display_map(*prg,prg->map,&(prg->player));
        prg->coin.offset = coin_frame++ % 5;
        prg->snow.offset = snow_frame++ % 5;;
        prg->player_anim.offset = player_frame++ % 8;
    } 
    

        // Calculate FPS every 100 frames
    if (prg->frames % 100 == 0) {
        struct timeval end_time;
        gettimeofday(&end_time, NULL);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                              (end_time.tv_usec - start_time.tv_usec) / 1e6;

        frames_per_second = 100 / elapsed_time;
        printf("Frames Per Second: %d\n", frames_per_second);

        // Reset start time for the next interval
        gettimeofday(&start_time, NULL);
    }
    handle_status_printed(prg);
    //usleep(25000);
    return (0);
}
