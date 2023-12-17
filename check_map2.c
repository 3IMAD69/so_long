#include "header.h"

void floodfill_recursive(char **map,int rows, int colums,t_position entity)
{
    if (entity.x_row < 0 || entity.y_colum < 0 || entity.x_row >= rows || entity.y_colum >= colums 
        || map[entity.x_row][entity.y_colum] != '1' || map[entity.x_row][entity.y_colum] != 'E')
        return ;
    map[entity.x_row][entity.y_colum] = '7';
    floodfill_recursive(map,rows,colums,entity.x_row - 1,entity.y_colum);
    floodfill_recursive(map,rows,colums,entity.x_row + 1,entity.y_colum);
    floodfill_recursive(map,rows,colums,entity.x_row,entity.y_colum - 1);
    floodfill_recursive(map,rows,colums,entity.x_row,entity.y_colum + 1);
}

void floodfill_checker(char **map,int rows, int colums,t_position entity)
{
    floodfill_recursive(map,rows,colums,entity);
}

t_position get_entity_pos(t_map map,int rows,char c)
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
            j++
        }
        j++;  
    }
    return (entity);
}

