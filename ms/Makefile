# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 10:59:36 by mtadlaou          #+#    #+#              #
#    Updated: 2023/03/29 15:18:47 by mtadlaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= parsing.a
CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra

SRC =   ./parsing/herdoc.c ./parsing/new_split.c  ./parsing/tools.c ./parsing/tools1.c \
	   ./parsing/tools2.c ./parsing/tools3.c ./parsing/ft_remove.c \
	   ./parsing/expander.c ./parsing/get_next_line.c \
	   ./parsing/open_files.c ./parsing/quote.c \
	   ./parsing/syntax_error.c ./parsing/herdoc_utiles.c \
	   ./parsing/herdoc_utiles1.c ./parsing/open_files_utiles.c\
	   ./parsing/tools4.c ./parsing/syntax_error_utils.c\
	   ./parsing/syntax_checker.c

OBJ 	= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	ar -rc $(NAME) $(OBJ)

clean :
	make clean -C ./libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all
