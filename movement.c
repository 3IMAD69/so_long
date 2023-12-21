#include "header.h"

void handle_all_move(t_program *prg)
{
    int img_width;
    int img_height;
    void *img_ptr;
    char *moves_char;

    playSoundAsync("sounds/move_sound.mp3");
    prg->player.moves++;
    printf("Moves -> %d!\n",prg->player.moves);
    //img_ptr = mlx_xpm_file_to_image(prg->mlx, "./textures/wall3.xpm", &img_width, &img_height);
    //mlx_put_image_to_window(prg->mlx,prg->win,img_ptr,0,0); 
    //mlx_put_image_to_window(prg->mlx,prg->win,img_ptr,64,0); 
    //moves_char = ft_itoa(prg->player.moves);
    //mlx_string_put(prg->mlx,prg->win, 0, 0, 0xFFFFFFFF, ft_strjoin("MOVES : ",moves_char));
}

void check_for_coins(t_program *prg,char next_place)
{
    int img_width;
    int img_height;
    void *img_ptr;
    char *coins_char;

    if (next_place == 'C')
    {
        prg->player.coins_collected++; 
        //playSoundAsync("sounds/collect_coin.mp3");
        //img_ptr = mlx_xpm_file_to_image(prg->mlx, "./textures/wall3.xpm", &img_width, &img_height);
        //mlx_put_image_to_window(prg->mlx,prg->win,img_ptr,(prg->map.colums * 64) - 64,0);
        //mlx_put_image_to_window(prg->mlx,prg->win,img_ptr,prg->map.colums * 64,0); 
        coins_char = ft_itoa(prg->player.coins_collected);
        mlx_string_put(prg->mlx,prg->win, (prg->map.colums - 1.5) * 64, 0, 0xFFFFFFFF, ft_strjoin("COINS : ",ft_itoa(prg->player.coins_collected)));
        free(coins_char);
    }
}

int check_for_ending(t_program *prg,char next_place)
{
    if (next_place == 'E' && prg->player.coins_collected == prg->map.coin)
    {
        playSoundAsync("sounds/door-slam.mp3");
        printf("You won!");
        //free_my_map(prg->map.map_arr,prg->map.rows);
        //system("leaks so_long");
        exit(0);
    }
    else if (next_place == 'E' && prg->player.coins_collected != prg->map.coin)
    {
        playSoundAsync("sounds/door-locked.mp3");
        return (0);
    }
    else 
        return (1);
}

int handle_player_move_vertical(t_program *prg,int offset)
{
    char next_place;

    next_place = prg->map.map_arr[prg->player.y + offset][prg->player.x];
    if (next_place == '1')
        return (0);
    check_for_coins(prg,next_place);
    if (check_for_ending(prg,next_place) == 1)
    {
        mlx_destroy_image(prg->mlx,prg->player.img_ptr);
        display_player(*prg,prg->map,"./textures/wall.xpm",&(prg->player));
        prg->player.y = prg->player.y + offset;
        display_player(*prg,prg->map,"./textures/player.xpm",&(prg->player));    
        prg->map.map_arr[prg->player.y][prg->player.x] = 'P'; 
        prg->map.map_arr[prg->player.y - offset][prg->player.x] = '0';
        handle_all_move(prg);
    }
    return (1);
}

int handle_player_move_horizontal(t_program *prg,int offset)
{
    char next_place;

    next_place = prg->map.map_arr[prg->player.y][prg->player.x + offset];
    if (next_place == '1')
        return (0);
    check_for_coins(prg,next_place);
    if (check_for_ending(prg,next_place) == 1)
    {
       // mlx_destroy_image(prg->mlx,prg->player.img_ptr);
        //display_player(*prg,prg->map,"./textures/wall.xpm",&(prg->player));
        prg->player.x = prg->player.x + offset;
       // display_player(*prg,prg->map,"./textures/player.xpm",&(prg->player));    
        prg->map.map_arr[prg->player.y][prg->player.x] = 'P'; 
        prg->map.map_arr[prg->player.y][prg->player.x - offset] = '0';
        handle_all_move(prg);
    }
    return (1);
}

