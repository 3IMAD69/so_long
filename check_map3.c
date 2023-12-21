#include "header.h"

char **create_copy_map(char **map,int rows,int colums)
{
    char **copy_map;
    int i;

    i = 0;
    copy_map = (char **)malloc(rows * sizeof(char *));
    while (i < rows)
    {
        copy_map[i] = (char *)malloc(colums + 1 * sizeof(char));
        ft_strlcpy(copy_map[i],map[i],colums + 1);
        i++;
    }
    return (copy_map);
}

void check_if_all_coins_reachable(char **real_map,char **fake_map,int rows)
{
    int i;
    int j;
    i = 0;
    while (i < rows)
    {
        j = 0;
        while (real_map[i][j] != '\0')
        {
            if (real_map[i][j] == 'C' && fake_map[i][j] != '7')
            {
                free_my_map(real_map,rows);
                free_my_map(fake_map,rows);
                print_error("Coins Are Not Reachable!!");
            }
            j++;
        }
        i++;
    }
}