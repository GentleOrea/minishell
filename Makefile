# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 13:13:35 by ygarrot           #+#    #+#              #
#    Updated: 2018/04/13 12:25:16 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS =  -Wall -Werror -Wextra

SRC_FOLDER = src/

SRC_FP = main.c \
		 ft_cd.c\
		 misc.c \
		 ft_env.c\
		 init.c \
		 list_tools.c \
		 signals.c

#Colors
_RED=\x1b[31m
_GREEN=\x1b[32m
_BLUE=\x1b[94m
_WHITE=\x1b[37m
_END=\x1b[0m

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FP))

INCLUDE =  includes/

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(INCLUDE)
	@printf "                                                        \r"
	@printf " $(_BLUE)Compiling $@$(_END)\r"

$(NAME): $(OBJ)
	@printf "                                                        \r"
	@make -C libft -j
	@gcc $(FLAGS) -o $(NAME) $^ -L libft -l ft -ltermcap
	@printf "                                                        \r"
	@printf "minishell built\n"

test: all clean

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
