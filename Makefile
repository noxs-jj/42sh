#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/01 12:01:41 by jmoiroux          #+#    #+#              #
#    Updated: 2014/03/21 14:47:50 by jmoiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Makefile parent who call Makefile soon from libft
# add llvm- in CC= line if you need depends update of computer

CC = gcc -Wall -Wextra -Werror

RM = rm -rf

HEADER = sh.h

NAME = 42sh

SRCS =  \
		arraylen.c \
		build_cd.c \
		build_check.c \
		build_echo.c \
		build_exit.c \
		build_setenv.c \
		build_unsetenv.c \
		cd_change_pwd.c \
		cd_dash.c \
		cd_double_dot.c \
		cd_error.c \
		cd_only.c \
		check_cmdparam.c \
		check_exit.c \
		dataptr.c \
		env_copy.c \
		env_envdel.c \
		env_getenv.c \
		env_getvarindex.c \
		env_printenv.c \
		env_putenv.c \
		env_setenv.c \
		env_unsetenv.c \
		exe_buildorsystem.c \
		exe_execve.c \
		ft_ctrl_c.c \
		ft_exit.c \
		ft_is.c \
		ft_replace.c \
		init_start.c \
		lx_cmd_link.c \
		lx_detail.c \
		lx_detail_link.c \
		lx_free_lst.c \
		lx_is_op.c \
		lx_lex_line.c \
		lx_lexer.c \
		lx_pos_op.c \
		main.c \
		prs_parser.c \
		prs_prev_operator.c \
		prs_recurse_left.c \
		prs_recurse_pipe.c \
		prs_recurse_right.c \
		prs_recurse_rright.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) -g $(OBJS) -o $(NAME) -I. -L /usr/lib -ltermcap -lncurses \
-L libft -lft $(HEADER)

%.o: %.c
	@$(CC) -g $(SRC) -I /usr/lib -I /libft -I /includes -c $<

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
