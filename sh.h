/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:16:49 by mlaize            #+#    #+#             */
/*   Updated: 2014/03/11 12:13:23 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft/includes/libft.h"
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# define MAX_PRIORITY 2
# define BUFF 20000000
# define PROMPT "$> "
# define SUCCESS 0
# define ERR_ISDIR 1
# define ERR_NOEXIST 2
# define ERR_DENIED 3
# define ERR_CMDNOTFOUND 4

extern char	**environ;

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
*/

typedef struct		s_cmd
{
	char			*cmd;
	int				i;
	t_more			*more;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_tree
{
	int				type; /* type */
	int				response; /* response of child's action */
	int				ope; /* What operator is it */
	char			*command; /* The command string */
	struct s_tree	*father;
	struct s_tree	*left; /* link to left next node */
	struct s_tree	*right; /* link to right next node */
}					t_tree;


typedef struct	s_data
{
	char		**env; /* contain an env copy */
	char		**argv;
	char		*buff;
	char		*line;
	char		*toexec; /* pat of line, to lunch with execve in s_more */
	t_tree		*tree; /* chain list, contain the cmd line */
	char		*varenv; /* var name before '=' */
	char		*valenv; /* content of the var */
	t_cmd		*lst_line; /* contain the cmd chain list (lexer) */
}				t_data;

typedef struct	s_ope
{
	char		*operand;
	int			code;
	int			priority;
	void		(*f)(t_data *, t_tree *);
}				t_ope;

typedef struct	s_build
{
	char	*str;
	void	(*fptr)(t_data *d);
}				t_build;

/*
static const	t_build[] =
{
	{"cd\n", &ft_cd},
	{"cd ", &ft_cd},
	{"setenv ", &env_callsetenv},
	{"unsetenv ", &env_callunsetenv},
	{"echo ", &build_echo},
	{"exit ", &ft_cd},
	{"exit\n", &ft_cd},
	{'\0', NULL}
}*/

void	build_cd(t_data *d);
void	build_echo(t_data *d);
void	build_exit(t_data *d);
void	env_printenv(t_data *d);
void	env_setenv(t_data *d);
void	build_setenv(t_data *d);
void	build_unsetenv(t_data *d);

static const t_build	tab[] =
{
	{"echo", &build_echo},
	{"exit ", &build_exit},
	{"exit", &build_exit},
	{"env", &env_printenv},
	{"env ", &env_printenv},
	{"setenv", &build_setenv},
	{"unsetenv", &build_unsetenv},
	{"cd", &build_cd},
	{'\0', NULL}
};

/*
static t_ope	list_ope[] =
{
	{"|", 0, 0, NULL},
	{"<", 1, 0, NULL},
	{">>", 2, 1, NULL},
	{">", 3, 1, NULL},
	{"&&", 4, 2, NULL},
	{"||", 5, 2, NULL},
	{NULL, -1, -1, NULL}
};
*/

char	*env_getenv(t_data *d);
char	*ft_getenv(char *str, char **env);

int		build_check(t_data *d);
int		env_getvarindex(t_data *d);
int		exe_execve(t_data *d);
int		ft_get_var_index(char **env, char *str);
int		is_absolute(char *path);
int		is_dir(const char *path);
int		is_dotslash(char *path);
int		lx_is_op(char *str);
int		lx_pos_op(char *str, char *cmp);
int		prs_build_me_tree(char *str, t_tree **tree);
int		prs_cut_last_str(t_tree *tree, t_ope operation);

size_t	arraylen(char **array);

t_cmd	*lx_new_cmd(char *str, int n);

t_more	*lx_new_more(char *str, int n);

t_tree	*prs_create_tree_node(int type, int ope, char *command);

void	*ft_realloc(void *ptr, size_t size);
void	check_exit(t_data *d);
void	env_copy(t_data *d);
void	env_envdel(t_data *d);
void	env_putenv(t_data *d);
void	env_unsetenv(t_data *d);
void	ft_exit(t_data *d, char *s);
void	ft_exit(t_data *d, char *s);
void	ft_ctrl_c(int i);
void	ft_putenv(t_data *d);
void	init_start(t_data *d);
void	lx_add_cmd(t_data *data, t_cmd *new);
void	lx_add_more(t_cmd *op, t_more *new);
void	lx_detail(t_cmd *op);
void	lx_lex_line(char *line, t_data *data);
void	lx_lexer(char *line, t_data *data);
void	prs_parse_my_tree_bro(t_data *data, t_tree *tree);
void	prs_parser_lexer(t_data *data, char *str);
void	prs_parser(t_data *d);
void	lx_full_free(t_data *d);
void	ft_setenv(t_data *d, char *var, char *val);

int		cd_error(char *name);
void	cd_only(t_data *d, char *name);
void	cd_dash(t_data *d, char *name);
void	cd_double_dot(t_data *d);
void	cd_change_pwd(t_data *d, char *add);
void	ft_replace(char tr, char rw, char *str);


#endif
