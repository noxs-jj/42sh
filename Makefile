#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/01 12:01:41 by jmoiroux          #+#    #+#              #
#    Updated: 2014/03/01 12:02:04 by jmoiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


# Makefile parent who call Makefile soon from libft
# add llvm- in CC= line if you need depends update of computer

CC = llvm-gcc -Wall -Wextra -Werror

RM = rm -rf

HEADER = sh.h

NAME = 42sh

SRCS = 

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
