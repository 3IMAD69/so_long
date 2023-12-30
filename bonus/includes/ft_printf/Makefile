
SRC		= ft_print_p.c ft_print_str.c ft_print_u.c ft_print_x.c ft_printf.c \
			ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

OBJ		= ${SRC:.c=.o}

CFLAGS	= -Wall -Werror -Wextra
CC		= cc
NAME	= libftprintf.a

all:		${NAME}

${NAME}:	${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o:		%.c
	${CC} ${CFLAGS} -c $< -o $@
	
clean:
	rm -f ${OBJ} ${OBJB}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re
