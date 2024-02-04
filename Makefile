NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = ./src/minishell.c\
	  ./src/parsing/ft_prompt.c\
	  ./src/env/env.c\
	  ./src/env/env_tools.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) ./libft/libft.a -o $(NAME) -lreadline

clean:
	$(RM) $(OBJ)
fclean:clean
	$(RM) $(NAME)
re: fclean all
