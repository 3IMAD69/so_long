#include "header.h"

void display_map(t_program prg,t_map map)
{
    int i;
    int j;
    void *space;
    int img_width = 0;
    int img_height = 0;
    int offset = 64;
    space = mlx_xpm_file_to_image(prg.mlx, "./textures/wall.xpm", &img_width, &img_height);
    i = 0;
    while (i < map.rows)
    {
        j = 0;
        while (map.map_arr[i][j] != '\0')
        {
            if (map.map_arr[i][j] == '1')
            {
                mlx_put_image_to_window(prg.mlx,prg.win,space,(j * offset),(i * offset));
            }
            j++;
        }
        i++;
    }
}