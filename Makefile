
SRCM	= mandatory/bfs.c mandatory/check_map.c mandatory/check_map2.c mandatory/check_map3.c mandatory/display_map.c mandatory/keyhook.c mandatory/main.c mandatory/movement.c 

SRCB	= bonus/animation.c bonus/attack.c bonus/bfs.c bonus/check_map.c bonus/check_map2.c bonus/check_map3.c bonus/display_map.c bonus/dolphin_moves.c bonus/free_my_game.c \
		bonus/init_game.c bonus/keyhook.c bonus/main.c bonus/movement.c bonus/movement2.c

OBJM	= ${SRCM:.c=.o}

OBJB	= ${SRCB:.c=.o} 

CFLAGS	= -Wall -Werror -Wextra #-g -fsanitize=address
CC		= cc
NAME	= ./so_long
LINKS	= -lmlx -framework OpenGL -framework AppKit
LIBFTA 	= ./includes/libft/libft.a

all:		${NAME}

${LIBFTA} : 
	make -C includes/libft
	make -C includes/libft clean

${NAME}:	${OBJM} ${LIBFTA}
	${CC} ${CFLAGS} ${OBJM} ${LIBFTA} ${LINKS} -o ${NAME}

bonus:		${OBJB} ${LIBFTA}
	${CC} ${CFLAGS} ${OBJB} ${LIBFTA} ${LINKS} -o ${NAME}
	
clean:
	rm -f ${OBJM} ${OBJB}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all bonus clean fclean re
