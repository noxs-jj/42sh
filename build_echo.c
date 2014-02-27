/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:05:40 by vjacquie          #+#    #+#             */
/*   Updated: 2014/02/27 13:46:04 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** test ok
** First we check if the str is null or if the ft_strsplit haven't work
** We write all arg until the end of cmd
** We write a '\n' at the end if needed
*/

void	build_echo(t_data *d, char *str)
{
	char	**cmd;
	int		i;

	if (str == NULL)
		ft_exit(d, "Null str in build_echo\n");
	cmd = ft_strsplit(str, ' ');
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
			ft_putstr(cmd[i]);
			i++;
			if (cmd[i])
				ft_putchar(' ');
		}
	}
	if (cmd[1] == '\0' || ft_strcmp(cmd[1], "-n") != 0)
		ft_putchar('\n');
}
