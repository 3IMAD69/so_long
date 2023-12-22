#include "header.h"

void playSoundAsync(char *path) {
    // Use "afplay" in the background with "&" to run asynchronously
    char command[256];

    //snprintf(command, sizeof(command), "afplay %s &", path);
    ft_strlcpy(command,"afplay ",sizeof(command));
    ft_strlcat(command,path,sizeof(command));
    ft_strlcat(command," &",sizeof(command));
    system(command);
}

void handle_status_printed(t_program *prg)
{
    char *coins_char;
    char *moves_char;

    moves_char = ft_itoa(prg->player.moves);
    mlx_string_put(prg->mlx,prg->win, 0, 0, 0xFFFFFFFF, ft_strjoin("MOVES : ",moves_char));
    coins_char = ft_itoa(prg->player.coins_collected);
    mlx_string_put(prg->mlx,prg->win, (prg->map.colums - 1.5) * 64, 0, 0xFFFFFFFF, ft_strjoin("COINS : ",ft_itoa(prg->player.coins_collected)));
    free(coins_char);
    free(moves_char);
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
