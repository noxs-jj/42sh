/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_create_tree_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 16:37:09 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/24 18:02:26 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_tree	*prs_create_tree_node(int type, int ope, char *command)
{
	t_tree	*node;

	node = (t_tree *)malloc(sizeof(t_tree));
	node->type = type;
	node->ope = ope;
	node->command = command;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
