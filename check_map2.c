#include "header.h"

void floodfill_recursive(char **map,int rows, int colums,int xrow,int ycolum)
{
    if (xrow < 0 || ycolum < 0 || xrow>= rows || ycolum >= colums 
        || map[xrow][ycolum] != '1' || map[xrow][ycolum] != 'E')
        return ;
    map[xrow][ycolum] = '7';
    floodfill_recursive(map,rows,colums,xrow - 1,ycolum);
    floodfill_recursive(map,rows,colums,xrow + 1,ycolum);
    floodfill_recursive(map,rows,colums,xrow,ycolum - 1);
    floodfill_recursive(map,rows,colums,xrow,ycolum + 1);
}

void floodfill_checker(char **map,int rows, int colums,t_position entity)
{
    floodfill_recursive(map,rows,colums,entity.x_row,entity.y_colum);
}

t_position get_entity_pos(char **map,int rows,char c)
{
    int i;
    int j;
    t_position entity;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (c == map[i][j])
            {
                entity.x_row = i;
                entity.y_colum = j;
            }
            j++;
        }
        i++;  
    }
    return (entity);
}

