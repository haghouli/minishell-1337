
SANI	= -fsanitize=address -g3
CMP_PATH = -I ~/Users/mtadlaou/goinfre/homebrew/Cellar/readline/8.2.1/include  -L /Users/mtadlaou/goinfre/homebrew/Cellar/readline/8.2.1/lib -lreadline
NAME	= minishell
CFLAGS	= -Wall -Wextra -Werror
CC 		= cc

SRC		= ./main.c \
		./utiles/is_built_in.c \
		./utiles/ft_unset.c \
		./utiles/ft_export.c \
		./utiles/arr_op.c \
		./utiles/is_exec.c \
		./utiles/fill_env.c \
		./utiles/error_print.c\
		./utiles/path_op.c \
		./utiles/execute.c \
		./utiles/exec_all.c \
		./lst/ft_lstsort_env.c \
		./lst/ft_lstadd_front_env.c \
		./lst/ft_lstdelone_env.c \
		./lst/ft_lstiter_env.c \
		./lst/ft_lstclear_env.c \
 		./lst/ft_lstlast_env.c \
		./lst/ft_lstnew_env.c \
		./lst/ft_lstadd_back_env.c \
		./lst/ft_lstsize_env.c \
		./lst/ft_lstmap_env.c \
		./utiles/signals.c \
		./utiles/exec_builtin.c \
		./utiles/exec_single_cmd.c \
		./utiles/ft_echo.c \
		./utiles/closes.c \
		./lst/ft_lstadd_back_bonus.c \
		./lst/ft_lstadd_front_bonus.c \
		./utiles/ft_exit.c \
		./utiles/ft_pwd.c \
		./utiles/ft_cd.c \
		./utiles/ft_env.c \
		./utiles/change_last_exec.c \
		./utiles/clear_lst.c \
		./utiles/export_utiles.c \
		./utiles/start.c \
		./utiles/check_path.c \


O_SRC	= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(O_SRC) lib
	$(CC) $(CFLAGS) $(CMP_PATH) ./ms/libft/libft.a ./ms/parsing.a $(O_SRC) -lreadline -o $(NAME)

lib:
	make -C ./ms/

clean : 
	make clean -C ./ms/
	rm -f $(O_SRC)

fclean : clean
	make clean -C ./ms/
	rm -f $(NAME)

re : fclean all 