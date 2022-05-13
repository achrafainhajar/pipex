SRC = pipex.c tools.c tools2.c 42-GNL/get_next_line.c 42-GNL/get_next_line_utils.c
SRC_BONUS = pipex_bonus.c tools.c tools2.c 42-GNL/get_next_line.c 42-GNL/get_next_line_utils.c
NAME = pipex
NAME_BONUS = pipex_bonus

all : $(NAME)
$(NAME):
		@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)
bonus:
	@gcc -Wall -Wextra -Werror $(SRC_BONUS) -o $(NAME_BONUS) 

fclean:
	rm -rf $(NAME) $(NAME_BONUS)
re:fclean all