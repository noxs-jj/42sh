/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:23:55 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/28 14:01:45 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int 	main(int argc, char **argv)
{
	if (argc == 2)
		prs_parser_lexer(NULL, argv[1]);
	return (0);
}

void	prs_parser_lexer(t_data *data, char *str)
{
	char	**trees;
	t_tree	*tree;
	int		error;
	int		i;

	trees = ft_strsplit(str, ';');
	i = 0;
	error = -1;
	if (data == NULL)
		data = (t_data *)ft_memalloc(sizeof(t_data));
	while (trees[i])
	{
		error = prs_build_me_tree(trees[i], &tree);
		if (error != -1)
		{
			printf("parse error near %d\n", error);
			return ;
		}
		data->tree = tree;
		prs_parse_my_tree_bro(data, tree);
		i++;
	}
}
