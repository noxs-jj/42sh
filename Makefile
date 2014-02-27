#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 11:22:36 by jmoiroux          #+#    #+#              #
#    Updated: 2014/02/26 18:48:50 by jmoiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


# Makefile parent who call Makefile soon from libft
# add llvm- in CC= line if you need depends update of computer

CC = llvm-gcc -Wall -Wextra -Werror

RM = rm -rf

HEADER = sh.h

NAME = 42sh

SRCS = \
build_check.c \
cut_tree.c \
env_copy.c \
env_tabheight.c \
env_tablen.c \
ft_cd.c \
ft_exit.c \
prs_build_tree.c \
prs_parse.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(OBJS) -o $(NAME) -I. -L /usr/lib -ltermcap -lncurses \
-L libft -lft $(HEADER)

%.o: %.c
	@$(CC) $(SRC) -I /usr/lib -I /libft -I /includes -c $<

clean:
	@$(RM) $(OBJS)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
