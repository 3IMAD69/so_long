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
            prg->player_anim.offset = 0;
            //init_player_death(prg);
            mlx_clear_window(prg->mlx,prg->win);
            printf("player Offset %d",prg->player_anim.offset);
            exit(0);
        }
    }
}
int ft_animation(t_program *prg)
{
    static unsigned int coin_frame;
    static unsigned int snow_frame;
    static unsigned int player_frame;
    static unsigned int enemy_frame;
    static unsigned int dolphin_frame;
    static int death_frame;
    static struct timeval start_time;
    int frames_per_second = 0;
    struct timeval end_time;

    prg->frames++;
    if (prg->frames < 0 || prg->frames >= 1000)
        prg->frames = 0;
    if (coin_frame >= 100)
    {
        coin_frame = snow_frame = player_frame = enemy_frame = 0;
    }

    if (prg->frames == 1) {
        gettimeofday(&start_time, NULL);
    }
    if (prg->game_status == 1)
    {
        if (prg->frames % 5 == 0)
        {
            mlx_clear_window(prg->mlx,prg->win);
            //display_map(*prg,prg->map,&(prg->player));
            // handle_status_printed(prg);
            prg->coin.offset = coin_frame++ % 5;
            prg->snow.offset = snow_frame++ % 5;
            prg->player_anim.offset = player_frame++ % 8;
            prg->dolphin_anim.offset = dolphin_frame++ % 7;
            
        }
        handle_enemy(prg,&enemy_frame);
        // Calculate FPS every 100 frames
        if (prg->frames % 50 == 0)
        {
            printf("frame li fih db move dplhin %d\n",prg->frames);
            move_dolphin(prg);
        }
        if (prg->frames % 100 == 0) {
            gettimeofday(&end_time, NULL);
            double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                                (end_time.tv_usec - start_time.tv_usec) / 1e6;

            frames_per_second = 100 / elapsed_time;
            printf("Frames Per Second: %d\n", frames_per_second);

            // Reset start time for the next interval
            gettimeofday(&start_time, NULL);
        }
        handle_status_printed(prg);
    }
    else
    {
        if (death_frame == 0)
            playSoundAsync("sounds/you-died.mp3");
        
        mlx_clear_window(prg->mlx, prg->win);
        printf("death Frame => %d \n",death_frame);
        mlx_put_image_to_window(prg->mlx, prg->win, prg->death_scene.frames_arr[death_frame], ((prg->map.colums) - 3.75) * 32, ((prg->map.rows) - 3.75) * 32);
        if (death_frame >= 125)
        {
            sleep(2);
            exit(0);
        }
        else
                death_frame++;
        
    }
    
    //mlx_do_sync(prg->mlx);
    //usleep(25000);
    return (0);
}

// int test_death_scene(t_program *prg)
// {
//     static int death_frame;
//     static int frames;

//     frames++;


//     if (frames % 30 == 0) {
//         mlx_clear_window(prg->mlx, prg->win);
//         //mlx_put_image_to_window(prg->mlx, prg->win, prg->death_scene.frames_arr[0], x, y);
//         //mlx_put_image_to_window(prg->mlx, prg->win, prg->death_scene.frames_arr[0], ((prg->map.rows/60)-4)*30, ((prg->map.colums/60)-3)*30);
//         mlx_put_image_to_window(prg->mlx, prg->win, prg->death_scene.frames_arr[death_frame], ((prg->map.colums) - 3.75) * 32, ((prg->map.rows) - 3.75) * 32);
//         if (death_frame >= 99)
//         {
//             death_frame = 0;
//             exit(0);
//         }
//         else
//             death_frame++;
//     }

//     return (0);
// }
