/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:35:27 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/03 13:07:01 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**
**
*/

int		main(void)
{
	t_data	*d;
	pid_t	father;

	d = (t_data *)malloc(sizeof(t_data));
	if (d == NULL)
		ft_exit(d, "Malloc error struct data (main)\n");
	init_start(d);
	env_copy(d);
	while (1)
	{
		ft_putstr(PROMPT);
		get_next_line(0, &d->line);
		d->line = ft_strtrim(d->line);
		check_exit(d);
		if (d->line[0] != '\0' && build_check(d) != 1)
		{
			if ((father = fork()) == -1)
				ft_exit(d, "fork error in main\n");
			if (father == 0)
			{
				exe_execve(d);
				_exit(1);
			}
			else
			{
				wait(NULL);
				check_exit(d);
			}
		}
		ft_memdel((void **)&d->line);
	}
}
