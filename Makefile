#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/01 12:01:41 by jmoiroux          #+#    #+#              #
#    Updated: 2014/03/03 13:06:39 by jmoiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


# Makefile parent who call Makefile soon from libft
# add llvm- in CC= line if you need depends update of computer

CC = llvm-gcc -g -Wall -Wextra -Werror

RM = rm -rf

HEADER = sh.h

NAME = 42sh

SRCS = \
arraylen.c \
build_check.c \
build_echo.c \
build_exit.c \
build_setenv.c \
build_unsetenv.c \
check_exit.c \
env_copy.c \
env_envdel.c \
env_getenv.c \
env_getvarindex.c \
env_printenv.c \
env_putenv.c \
env_setenv.c \
env_unsetenv.c \
exe_execve.c \
exe_getexe.c \
ft_exit.c \
ft_is.c \
ft_realloc.c \
init_start.c \
main.c

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

exe:
	@clear
	@echo "--------clang compil-------"
	@clang -Wall -Werror -Wextra -g -o $(NAME) libft.a $(SRCS)

re: fclean all

.PHONY: all clean fclean re
