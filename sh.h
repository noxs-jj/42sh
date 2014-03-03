/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:16:49 by mlaize            #+#    #+#             */
/*   Updated: 2014/03/03 13:06:29 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft/includes/libft.h"
# include <sys/stat.h>
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

typedef struct	s_ope
{
	char		*operand;
	int			code;
	int			priority;
}				t_ope;

typedef struct	s_data
{
	char		**env; /* contain an env copy */
	char		*buff;
	char		*line;
	t_tree		*tree; /* chain list, contain the cmd line */
	char		*varenv; /* var name before '=' */
	char		*valenv; /* content of the var */
}				t_data;

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
	{'\0', NULL}
};

/*
static t_ope	list_ope[] =
{
	{"|", 0, 0},
	{"<", 1, 0},
	{">>", 2, 1},
	{">", 3, 1},
	{"&&", 4, 2},
	{"||", 5, 2},
	{NULL, -1, -1}
};
*/

char	**env_getexe(t_data *d);
char	**ft_getexe(char *str, char **env);
char	*env_getenv(t_data *d);
char	*ft_getenv(char *str, char **env);

int		env_getvarindex(t_data *d);
int		is_absolute(char *path);
int		is_dir(const char *path);
int		is_dotslash(char *path);
int		exe_execve(t_data *d);
int		ft_get_var_index(char **env, char *str);
int		build_check(t_data *d);

size_t	arraylen(char **array);

void	check_exit(t_data *d);
void	env_envdel(t_data *d);
void	env_copy(t_data *d);
void	env_putenv(t_data *d);
void	env_unsetenv(t_data *d);
void	ft_exit(t_data *d, char *s);
void	ft_putenv(t_data *d);
void	*ft_realloc(void *ptr, size_t size);
void	ft_exit(t_data *d, char *s);
void	init_start(t_data *d);

#endif
