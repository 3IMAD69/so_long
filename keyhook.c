#include "header.h"

int handle_player_move_vertical(t_program *prg,int offset)
{
    if (prg->map.map_arr[prg->player.y + offset][prg->player.x] == '1')
        return (0);
    mlx_destroy_image(prg->mlx,prg->player.img_ptr);
    display_player(*prg,prg->map,"./textures/wall.xpm",&(prg->player));
    prg->player.y = prg->player.y + offset;
    display_player(*prg,prg->map,"./textures/player.xpm",&(prg->player));    
    prg->map.map_arr[prg->player.y][prg->player.x] = 'P'; 
    prg->map.map_arr[prg->player.y - offset][prg->player.x] = '0';
    prg->player.moves++;
    printf("Moves -> %d!\n",prg->player.moves);
    return (1);
}

int handle_player_move_horizontal(t_program *prg,int offset)
{
    if (prg->map.map_arr[prg->player.y][prg->player.x + offset] == '1')
        return (0);
    mlx_destroy_image(prg->mlx,prg->player.img_ptr);
    display_player(*prg,prg->map,"./textures/wall.xpm",&(prg->player));
    prg->player.x = prg->player.x + offset;
    display_player(*prg,prg->map,"./textures/player.xpm",&(prg->player));    
    prg->map.map_arr[prg->player.y][prg->player.x] = 'P'; 
    prg->map.map_arr[prg->player.y][prg->player.x - offset] = '0';
    prg->player.moves++;
    printf("Moves -> %d!\n",prg->player.moves);
    return (1);
}


int	key_hook(int keycode,t_program *prg)
{
    // if (keycode == 53) //ESC
    //     exit(0);
    // if (keycode == 13 || keycode == 126)
    //     prg->player.moves += handle_player_move_up(prg);
    // if (keycode == 1 || keycode == 125)
    //     prg->player.moves += handle_player_move_down(prg);
    // if (keycode == 2 || keycode == 124)
    //     prg->player.moves += handle_player_move_right(prg);
    // if (keycode == 0 || keycode == 123)
    //     prg->player.moves += handle_player_move_left(prg);

    if (keycode == 53) //ESC
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

int	close_prg(void)
{
    printf("closing the program\n");
	exit(0);
}
