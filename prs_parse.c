/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:23:55 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/25 16:39:50 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**
** TEST
*/

int	main(int argc, char **argv)
{
	if (argc == 2)
		prs_parser_lexer(argv[1]);
	return (0);
}

int	prs_parser_lexer(char *str)
{
	char	**trees;
	t_tree	*tree;
	int		i;
	int		codex;

	trees = ft_strsplit(str, ';');
	i = 0;
	codex = 0;
	while (trees[i])
	{
		codex = prs_build_me_tree(trees[i], &tree);
		read_me_tree_mothafocka(tree);
		if (codex)
			return (codex);
		i++;
	}
	return (0);
}
