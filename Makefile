NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -rf

SRC = ./src/minishell.c\
	  ./src/parsing/ft_prompt.c\
	  ./src/parsing/ft_separate.c\
	  ./src/env/env.c\
	  ./src/env/env_tools.c\
	  ./src/signals/signals.c\
	  ./src/builtin/cd.c\
	  ./src/parsing/ft_pars.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) ./libft/libft.a -o $(NAME) -lreadline

clean:
	$(RM) $(OBJ)
fclean:clean
	$(RM) $(NAME)
re: fclean all
