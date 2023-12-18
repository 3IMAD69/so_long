#include "header.h"


void display_helper(t_program prg,t_map map,char *path,char character)
{
    int i;
    int j;
    int img_width;
    int img_height;
    void *img_ptr;

    i = 0;
    img_width = 0;
    img_height = 0;
    img_ptr = mlx_xpm_file_to_image(prg.mlx, path, &img_width, &img_height);
    while (i < map.rows)
    {
        j = 0;
        while (map.map_arr[i][j] != '\0')
        {
            if (map.map_arr[i][j] == character)
            {
                mlx_put_image_to_window(prg.mlx,prg.win,img_ptr,(j * 64),(i * 64));
            }
            j++;
        }
        i++;
    }
}



void display_map(t_program prg,t_map map)
{
    display_helper(prg,map,"./textures/wall.xpm",'0');
    display_helper(prg,map,"./textures/wall2.xpm",'1');
    display_helper(prg,map,"./textures/door.xpm",'E');
}