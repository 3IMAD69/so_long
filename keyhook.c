#include "header.h"

int	key_hook(int keycode, t_program *vars)
{
    if (keycode == 53) //ESC
        exit(0);
	printf("Hello from key_hook %d!\n",keycode);
	return (0);
}

int	close_prg(void)
{
    printf("closing the program\n");
	exit(0);
}
