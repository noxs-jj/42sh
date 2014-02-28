/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:39:13 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/26 18:17:03 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		cut_tree(t_tree *tree, t_ope operation, int offset)
{
	char	*left_part;
	char	*right_part;

	//printf("pour la chaine [%s], offset de %d\n", tree->command, offset);
	if (tree == NULL)
		return ;
	left_part = ft_strsub(tree->command, 0, offset);
	right_part = ft_strsub(tree->command, offset + ft_strlen(operation.operand),
			ft_strlen(tree->command) - offset - ft_strlen(operation.operand));
	printf("le decoupage s'est fait de la maniere suivante [%s] [%s], code %d\n", left_part, right_part, operation.code);
	free(tree->command);
	tree->type = 1;
	tree->ope = operation.code;
	tree->command = NULL;
	tree->left = prs_create_tree_node(0, 0, left_part);
	tree->right = prs_create_tree_node(0, 0, right_part);
	tree->left->father = tree;
	tree->right->father = tree;
}

int		find_last_priority(char *str, int priority, int *where)
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
				printf("found, offset %d [%c] : code %d\n", i, *(str + i), n_ope);
				*where = i;
				return (n_ope);
			}
			n_ope++;
		}
		i--;
		//printf("nope\n");
	}
	return (-1);
}

t_tree	*prs_parse_by_priority(t_tree *tree, int priority)
{
	int		ope;
	int		index;
	t_tree	*error;

	if (tree == NULL || tree->type != 0)
		return (NULL);
	ope = find_last_priority(tree->command, priority, &index);
	if (ope == -1 && priority == 0)
	{
		tree->type = 2;
		return (NULL);
	}
	else if (ope == -1 && priority > 0)
		return (prs_parse_by_priority(tree, priority - 1));
	else if (ope == -2)
		return (tree->father);
	cut_tree(tree, list_ope[ope], index);
	while (priority >= 0)
	{
		error = prs_parse_by_priority(tree->left, priority);
		if (error)
			return (error);
		error = prs_parse_by_priority(tree->right, priority);
		if (error)
			return (error);
		priority--;
	}
	return (NULL);
}	

int				prs_build_me_tree(char *str, t_tree **tree)
{
	t_tree		*error;

	*tree = prs_create_tree_node(0, -1, str);
	error = 0;
	error = prs_parse_by_priority(*tree, MAX_PRIORITY);
		if (error != NULL)
			return (error->ope);
	return (-1);
}
