/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:16:49 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/28 16:09:38 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft/includes/libft.h"
# define MAX_PRIORITY 2

extern char			**environ;

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

typedef struct	s_data
{
	char		**c_env;
	char		**env;
	t_tree		*tree;
}				t_data;

int		prs_build_me_tree(char *str, t_tree **tree);
int		prs_cut_last_str(t_tree *tree, t_ope operation);
int		prs_parser_lexer(char *str);

void	read_me_tree_mothafocka(t_tree*);

t_tree	*prs_create_tree_node(int type, int ope, char *command);

#endif
