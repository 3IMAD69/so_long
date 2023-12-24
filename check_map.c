#include "header.h"


void free_my_map(char **my_map,int rows)
{
    int i = 0;
    while (i < rows)
    {
        free(my_map[i]);
        i++;
    }
    free(my_map);
}

void validate_map(char **my_map,int rows)
{
    int col_size;
    int i;

    i = 1;
    if (rows == 0)
        print_error("Invalid_map");
    if (my_map[0] == NULL || my_map[0] == '\0')
    {
        free_my_map(my_map,rows);
        print_error("Invalid Map!!");
    }
    col_size = ft_strlen(my_map[0]);
    while (i < rows)
    {
        if (ft_strlen(my_map[i]) != col_size)
        {
            free_my_map(my_map,rows);
            print_error("Invalid Row In Map!!");
        }
        i++;
    }
    
}

void checker_character_helper(char **my_map,t_map *map,int rows)
{
    if (map->coin == 0 || map->exit != 1 || map->player_pos != 1)
    {
        free_my_map(my_map,rows);
        if (map->coin == 0)
            print_error("No Coin Found!!");
        print_error("Map is Invalid !!");
    }
}
int init_my_player(t_player *player,int x, int y)
{
    player->x = x;
    player->y = y;
    return (1);
}

void check_map_character(char **my_map,int rows,t_program *prg)
{
    int i;
    int j;

    i = 0;
    ft_memset(&(prg->map),0,sizeof(t_map));
    while (i < rows)
    {
        j = 0;
        while (my_map[i][j] != '\0')
        {
            if (!ft_strchr("01CEPXY",my_map[i][j]))
            {
                free_my_map(my_map,rows);
                print_error("Character Not Allowed !!");
            }
            prg->map.exit += (my_map[i][j] == 'E');
            prg->map.coin += (my_map[i][j] == 'C');
            prg->map.player_pos += (my_map[i][j] == 'P') && init_my_player(&(prg->player),j,i);
            j++;
        }
        i++;
    }
    checker_character_helper(my_map,&(prg->map),rows);
}

