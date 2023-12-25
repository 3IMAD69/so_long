#include "header.h"

void attack_vertical(t_program *prg,int offset)
{
    char attacking_place;
    char my_place;

    attacking_place = prg->map.map_arr[prg->player.y + offset][prg->player.x];
    my_place = prg->map.map_arr[prg->player.y][prg->player.x];
    if (attacking_place == 'Y' && free_player(prg,7))
    {
        init_player_attack(prg);
        prg->map.map_arr[prg->player.y + offset][prg->player.x] = '0';
    }
}

void attack_horizontal(t_program *prg,int offset)
{
    char attacking_place;
    char my_place;

    attacking_place = prg->map.map_arr[prg->player.y][prg->player.x + offset];
    my_place = prg->map.map_arr[prg->player.y][prg->player.x];
    if (attacking_place == 'Y' && free_player(prg,7))
    {
        prg->map.map_arr[prg->player.y][prg->player.x + offset] = '0';
        init_player_attack(prg);
    }
}


void handle_attack(int keycode ,t_program *prg)
{
    printMap(prg->map.map_arr,prg->map.rows,prg->map.colums);
    if (keycode == 126)
        attack_vertical(prg,-1);
    if (keycode == 125)
        attack_vertical(prg,1);
    if (keycode == 124)
        attack_horizontal(prg,1);
    if (keycode == 123)
        attack_horizontal(prg,-1);
    printMap(prg->map.map_arr,prg->map.rows,prg->map.colums);
}