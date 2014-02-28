/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:03:28 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/28 16:51:33 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	prs_parse_my_tree_bro(t_data *data, t_tree *tree)
{
	if (tree->left == NULL && tree->right == NULL && tree->type == 2)
	{
		//exec_cmd(tree->command);
		return ;
	}
	if (tree->left->type == 1)
		prs_parse_my_tree_bro(data, tree->left);
	if (tree->right->type == 1 &&
				((tree->ope != 4 && tree->ope != 5) ||
				 (tree->ope == 4 && tree->left->response == 0) ||
				 (tree->ope == 5 && tree->left->response == 1)))
		prs_parse_my_tree_bro(data, tree->right);
	if (list_ope[tree->ope].f == NULL)
		printf("fuckin error NULL Function \n");
	else
		list_ope[tree->ope].f(data, tree);
	if (tree == data->tree && tree->type == 2)
		exec_cmd(tree->command);
}
