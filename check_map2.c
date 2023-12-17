#include "header.h"

void floodfill_recursive(char **map,int rows, int colums,int row_start,int col_start)
{
    if (row_start < 0 || col_start < 0 || row_start >= rows || col_start >= colums 
        || map[row_start][col_start] != '7')
        return ;
    map[row_start][col_start] = '8';
    floodfill_recursive(map,rows,colums,row_start - 1,col_start);
    floodfill_recursive(map,rows,colums,row_start + 1,col_start);
    floodfill_recursive(map,rows,colums,row_start,col_start - 1);
    floodfill_recursive(map,rows,colums,row_start,col_start + 1);
}

void floodfill_checker(char **map,int rows, int colums,int row_start,int col_start)
{
    floodfill_recursive(map,rows,colums,row_start,col_start);
}

