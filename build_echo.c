/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:05:40 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/01 18:09:39 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** test ok
** First we check if the str is null or if the ft_strsplit haven't work
** We write all arg until the end of cmd
** We write a '\n' at the end if needed
*/

void	build_echo(t_data *d)
{
	char	**cmd;
	int		i;
	int		j;

	if (d->line == NULL)
		ft_exit(d, "Null str in build_echo\n");
	cmd = ft_strsplit(d->line, ' ');
	if (cmd == NULL)
		ft_exit(d, "Error in echo split\n");
	i = 0;
	if (cmd[1] != '\0')
	{
		(ft_strcmp(cmd[1], "-n") == 0) ? (i = 2) : (i = 1);
		while (cmd[i] && ft_strcmp(cmd[i], "-n") == 0)
			i++;
		while (cmd[i])
		{
			j = 0;
			while (cmd[i][j])
			{
				if (cmd[i][j] == 34 || cmd[i][j] == 39)
					j++;
				else if (cmd[i][j])
					ft_putchar(cmd[i][j]);
				j++;
			}
			i++;
			if (cmd[i])
				ft_putchar(' ');
		}
	}
	if (cmd[1] == '\0' || ft_strcmp(cmd[1], "-n") != 0)
		ft_putchar('\n');
}
