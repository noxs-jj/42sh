/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:16:49 by mlaize            #+#    #+#             */
/*   Updated: 2014/03/26 11:54:57 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft/includes/libft.h"
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

# define MAX_PRIORITY 2
# define BUFF 20000000
# define PROMPT "$> "
# define SUCCESS 0
# define ERR_ISDIR 1
# define ERR_NOEXIST 2
# define ERR_DENIED 3
# define ERR_CMDNOTFOUND 4

/*
**	type :	0 = for sort
**			1 = operator
**			2 = command
**			3 = response
*/

/*
** str : contain the cmd + arg
** end : contain the op after str, 1 = |, 2 = <, 3 = >, 4 = >>
*/

typedef struct		s_more
{
	char			*str;
	int				end;
	struct s_more	*next;
	struct s_more	*prev;
}					t_more;

/*
** cmd : contain the line after the split (";", "&&" and "||")
** i : 1 if the op next is "&&", 2 if "||", else 0
** more : contain the detail of cmd
** exedone  1 EXECSUCCESS / 0 EXECERROR
*/

typedef struct		s_cmd
{
	char			*cmd;
	int				i;
	int				exedone;
	t_more			*more;
	struct s_cmd	*next;
}					t_cmd;

/*
** - env from argv on main.c
** - contain an env copy
** - used for env
** - line command bufered
** - pat of line, to lunch with execve in s_more
** - chain list, contain the cmd line
** - var name before '='
** - content of the var
** - contain the cmd chain list (lexer)
** - contain the backup of output and input
** - status of last cmdline chainlink 0 cmd success / < 0 cmd fail
** - if cmd running 1 yes 0 no used for CTRL + 1
*/

typedef struct		s_data
{
	char			**envmain;
	char			**cenv;
	char			**argv;
	char			*line;
	char			*toexec;
	char			*varenv;
	char			*valenv;
	t_cmd			*lst_line;
	int				statprev;
	int				cmdrun;
	t_cmd			*current;
}					t_data;

typedef struct		s_build
{
	char			*str;
	void			(*fptr)(t_data *d);
}					t_build;

void				build_cd(t_data *d);
void				build_echo(t_data *d);
void				build_exit(t_data *d);
void				env_printenv(t_data *d);
void				env_setenv(t_data *d);
void				build_setenv(t_data *d);
void				build_unsetenv(t_data *d);

static const t_build	g_tab[] =
{
	{
		"echo", &build_echo
	},
	{
		"exit ", &build_exit
	},
	{
		"exit", &build_exit
	},
	{
		"env", &env_printenv
	},
	{
		"env ", &env_printenv
	},
	{
		'\0', NULL
	}
};

/*
** Used for exe_execve
*/

typedef struct		s_searchexe
{
	char			**path;
	char			*var;
	char			*tmp;
	char			*tofree;
	size_t			i;
}					t_searchexe;

char				*env_getenv(t_data *d);
char				*ft_getenv(char *str, char **env);

int					build_check(t_data *d);
int					cd_error(char *name);
int					check_cmdparam(t_data *d, t_more *link);
int					env_getvarindex(t_data *d);
int					exe_build_system(t_data *d);
int					exe_execve(t_data *d);
int					ft_get_var_index(char **env, char *str);
int					is_absolute(char *path);
int					is_dir(const char *path);
int					is_dotslash(char *path);
int					lx_is_op(char *str);
int					lx_pos_op(char *str, char *cmp);
int					recurse_left(t_data *d, t_more *link);
int					recurse_pipe(t_data *d, t_more *link, int fd);
int					recurse_right(t_data *d, t_more *link);
int					recurse_rright(t_data *d, t_more *link);

size_t				arraylen(char **array);

t_cmd				*lx_new_cmd(char *str, int n);
t_more				*lx_new_more(char *str, int n);
t_data				*dataptr(t_data *d);

void				cd_change_pwd(t_data *d, char *add);
void				cd_dash(t_data *d, char *name);
void				cd_double_dot(t_data *d, char *av);
void				cd_only(t_data *d, char *name);
void				check_exit(t_data *d);
void				env_copy(t_data *d);
void				env_envdel(t_data *d);
void				env_putenv(t_data *d);
void				env_unsetenv(t_data *d);
void				free_tabtab(char **tab);
void				ft_ctrl_c(int i);
void				ft_exit(t_data *d, char *s);
void				ft_exit(t_data *d, char *s);
void				ft_putenv(t_data *d);
void				ft_replace(char tr, char rw, char *str);
void				ft_setenv(t_data *d, char *var, char *val);
void				init_start(t_data *d);
void				lx_add_cmd(t_data *data, t_cmd *new);
void				lx_add_more(t_cmd *op, t_more *new);
void				lx_detail(t_cmd *op);
void				lx_full_free(t_data *d);
void				lx_lex_line(char *line, t_data *data);
void				lx_lexer(char *line, t_data *data);
void				prev_operator(t_data *d, t_more *link);
void				prs_parser(t_data *d);
void				prs_parser_lexer(t_data *data, char *str);

#endif
