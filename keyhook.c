#include "header.h"

void playSoundAsync(char *path) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execlp("afplay", "afplay", path, NULL);
    }
    // Parent process continues immediately
}

void check_for_coins(t_program *prg,char next_place)
{
    if (next_place == 'C')
    {
        prg->player.coins_collected++; 
        playSoundAsync("sounds/collect_coin.mp3");
        mlx_string_put(prg->mlx,prg->win, 0, 0, 0xFFFFFFFF, "MOVES : 7");
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
    }
    playSoundAsync("sounds/move_sound.mp3");
    prg->player.moves++;
    printf("Moves -> %d!\n",prg->player.moves);
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
        mlx_destroy_image(prg->mlx,prg->player.img_ptr);
        display_player(*prg,prg->map,"./textures/wall.xpm",&(prg->player));
        prg->player.x = prg->player.x + offset;
        display_player(*prg,prg->map,"./textures/player.xpm",&(prg->player));    
        prg->map.map_arr[prg->player.y][prg->player.x] = 'P'; 
        prg->map.map_arr[prg->player.y][prg->player.x - offset] = '0';
    }
    playSoundAsync("sounds/move_sound.mp3");
    prg->player.moves++;
    printf("Moves -> %d!\n",prg->player.moves);
    return (1);
}


int	key_hook(int keycode,t_program *prg)
{
    if (keycode == 53 ) //ESC
        exit(0);
    if (keycode == 13 || keycode == 126)
        handle_player_move_vertical(prg,-1);
    if (keycode == 1 || keycode == 125)
        handle_player_move_vertical(prg,1);
    if (keycode == 2 || keycode == 124)
        handle_player_move_horizontal(prg,1);
    if (keycode == 0 || keycode == 123)
        handle_player_move_horizontal(prg,-1);

    //printMap(prg->map.map_arr,prg->map.rows,prg->map.colums);
	return (0);
}

int	close_prg(t_program *prg)
{
    free_my_map(prg->map.map_arr,prg->map.rows);
    printf("closing the program\n");
	exit(0);
}
