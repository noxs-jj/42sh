/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:35:27 by vjacquie          #+#    #+#             */
/*   Updated: 2014/02/28 18:12:57 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		main(void)
{
	t_data	*d;
	pid_t	*father;
	
	d = (t_data *)malloc(sizeof(t_data)); /* mettre ft_memalloc? */
	ft_envcpy(d);
	while (1)
	{
		ft_putstr(PROMPT);
		read(0, d->line, BUFF);
		if (build_check(d) != 1)
		{
			if ((father = fork) == -1)
				ft_exit(d, "fork error in main\n");
			if (father == 0)
			{
				ft_test_exec(d);
			}
			else
				wait(NULL);
		}
		ft_memdel((void **)&d->line);
	}
}
