/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_build_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:39:13 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/25 16:28:37 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** 4 functions
** prs_build_me_tree()<-cut_tree()<-find_last_priority()<-prs_build_me_tree
*/

static t_tree	*prs_parse_by_priority(t_tree *tree, int priority);
static void		cut_tree(t_tree *tree, t_ope operation, int offset);
static int		find_last_priority(char *str, int priority, int *where);

/*
** Create link with arrived command
** TEST
*/

int				prs_build_me_tree(char *str, t_tree **tree)
{
	int			priority;
	t_tree		*error;

	priority = MAX_PRIORITY;
	*tree = prs_create_tree_node(0, -1, str);
	error = 0;
	while (priority >= 0)
	{
		error = prs_parse_by_priority(*tree, priority);
		if (error)
			return (error->ope);
		priority--;
	}
	return (0);
}

/*
** cut parent tree to set left child and right child
** TEST
*/

static void		cut_tree(t_tree *tree, t_ope operation, int offset)
{
	char	*left_part;
	char	*right_part;

	left_part = ft_strsub(tree->command, 0, offset);
	right_part = ft_strsub(tree->command, offset + ft_strlen(operation.operand),
			ft_strlen(tree->command) - offset - ft_strlen(operation.operand));
	printf("le decoupage s'est fais de la maniere suivante [%s] [%s],
			code %d\n", left_part, right_part, operation.code);
	free(tree->command);
	tree->type = 1;
	tree->ope = operation.code;
	tree->left = prs_create_tree_node(0, 0, left_part);
	tree->right = prs_create_tree_node(0, 0, right_part);
}

/*
** find last OPE with indicated priority
** TEST
*/

static int		find_last_priority(char *str, int priority, int *where)
{
	int		i;
	int		n_ope;
	t_ope	ope;

	if (str == NULL || *str == 0)
		return (-2);
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		n_ope = 0;
		while (list_ope[n_ope].priority != -1)
		{
			ope = list_ope[n_ope];
			if (ope.priority == priority &&
					(ft_strstr(str + i, ope.operand) != NULL) &&
					(str[i] != '>' || (str[i] == '>' && str[i - 1] != '>')))
			{
				printf("found, offset %d [%c]\n", i, *(str + i));
				*where = i;
				return (n_ope);
			}
			n_ope++;
		}
		i--;
	}
	return (-1);
}

/*
** Sort by priority
** TEST
*/

static t_tree	*prs_parse_by_priority(t_tree *tree, int priority)
{
	int		ope;
	int		index;
	int		next_priority;
	t_tree	*error;

	ope = find_last_priority(tree->command, priority, &index);
	if (priority == 0 && ope == -1 && tree->type == 0)
		tree->type = 2;
	if (ope == -1)
		return (NULL);
	else if (ope == -2)
		return (tree);
	cut_tree(tree, list_ope[ope], index);
	next_priority = priority;
	while (next_priority >= 0)
	{
		error = prs_parse_by_priority(tree->left, next_priority);
		if (error)
			return (error);
		error = prs_parse_by_priority(tree->right, next_priority);
		if (error)
			return (error);
		next_priority--;
	}
	return (NULL);
}
