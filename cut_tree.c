/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:56:46 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/02/25 16:39:51 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** cut string on parent node, to set left child and right child
** TEST
*/

void	cut_tree(t_tree *tree, t_ope operation, int offset)
{
	char	*left_part;
	char	*right_part;

	//printf("pour la chaine [%s], offset de %d\n", tree->command, offset);
	left_part = ft_strsub(tree->command, 0, offset);
	right_part = ft_strsub(tree->command, offset + ft_strlen(operation.operand),
		ft_strlen(tree->command) - offset - ft_strlen(operation.operand));
	ft_printf("le decoupage s'est fais de la maniere suivante [%s] [%s],
		code %d\n", left_part, right_part, operation.code);
	free(tree->command);
	tree->type = 1;
	tree->ope = operation.code;
	tree->left = prs_create_tree_node(0, 0, left_part);
	tree->right = prs_create_tree_node(0, 0, right_part);
}
