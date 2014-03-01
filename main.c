/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:35:27 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/01 17:32:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	check_exit(t_data *d)
{
	if (d->line != NULL && d->line != '\0')
	{
		if ((ft_strequ("exit", d->line) == 1) && (d->line[5] == '\0' || d->line[5] == ' '))
			build_exit(d);
	}
}

int		main(void)
{
	t_data	*d;
	pid_t	father;
	
	d = (t_data *)malloc(sizeof(t_data)); /* mettre ft_memalloc? */
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
				check_exit(d);
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
