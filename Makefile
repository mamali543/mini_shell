NAME = minishell

LIBDIR = ft_libft

LIB = ft_libft/*.c

MINIFILES = minishell.c env_tools.c expander.c tools.c convert_list.c parser_tools.c print_functions.c echo.c syntax_error.c parser.c outils.c list_type.c cmd.c path.c

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@gcc $(MINIFILES) $(FLAGS) $(LIB) -o $(NAME) -L/usr/include -lreadline -fsanitize=address -g
fclean:
	@rm -rf minishell

re: fclean all