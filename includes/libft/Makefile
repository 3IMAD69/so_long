
SRC		= ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
				ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c \
				../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c \
				../ft_printf/ft_print_p.c ../ft_printf/ft_print_str.c ../ft_printf/ft_print_u.c ../ft_printf/ft_print_x.c ../ft_printf/ft_printf.c \
				../ft_printf/ft_putchar_fd.c ../ft_printf/ft_putnbr_fd.c ../ft_printf/ft_putstr_fd.c ../ft_printf/ft_strlen.c

SRCB	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ		= ${SRC:.c=.o}

OBJB	= ${SRCB:.c=.o} 

CFLAGS	= -Wall -Werror -Wextra
CC		= cc
NAME	= libft.a

all:		${NAME}

${NAME}:	${OBJ}
	ar rcs ${NAME} ${OBJ}

bonus: 	${OBJB}

${OBJB}:${SRCB}
	${CC} ${CFLAGS} -c $^ 
	ar rcs ${NAME} ${OBJB}

%.o:		%.c
	${CC} ${CFLAGS} -c $< -o $@
	
clean:
	rm -f ${OBJ} ${OBJB}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all bonus clean fclean re
