NAME = so_long
SRC = main.c keyhook.c check_map.c check_map2.c check_map3.c display_map.c movement.c animation.c dolphin_moves.c free_my_game.c attack.c movement2.c init_game.c bfs.c \
	includes/libft/ft_strnstr.c includes/libft/ft_strjoin.c includes/libft/ft_itoa.c includes/libft/ft_strdup.c includes/libft/ft_strlen.c includes/libft/ft_strlcpy.c includes/libft/ft_memcpy.c\
	includes/libft/ft_strncmp.c includes/libft/ft_strchr.c includes/libft/ft_memset.c includes/libft/ft_calloc.c includes/libft/ft_bzero.c includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c \
	includes/libft/ft_strlcat.c
OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wall -Wextra #-g -fsanitize=address
LINKS = -lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

# $(NAME): $(OBJ)
# 	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
# 	gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
# 	@echo $(GREEN)"- Compiled -"$(NONE)
# 	@rm $(OBJ)
# 	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

# $(OBJ): $(SRC)
# 	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
# 	gcc $(FLAGS) -c $(SRC)

# exe: all
# 	@echo "     - Executing $(NAME)... \n"
# 	@./$(NAME)
# 	@echo "\n     - Done -"

# clean:
# 	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
# 	@rm -rf $(OBJ)

# fclean: clean
# 	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
# 	@rm -rf $(NAME)

# re: fclean all

# -g -fsanitize=address
$(NAME):  	$(SRCS)
	gcc $(FLAGS) $(LINKS) $(SRC) -o $(NAME)
	@echo "\033[0;32mso_long is ready\033[0m"

clean:
	@$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
