/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:35:27 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/07 18:33:52 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**
**
*/

/*static void	ft_print(t_data *d)
{
	t_cmd *tmp;
	t_more *tmp2;

	tmp = d->lst_line;
	while (tmp != NULL)
	{
		printf("[%s][%d]\n", tmp->cmd, tmp->i);
		tmp2 = tmp->more;
		while (tmp2 != NULL)
		{
			printf("		[%s][%d]\n", tmp2->str, tmp2->end);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}*/

int		main(void)
{
	t_data	*d;
	int		pid;

	d = (t_data *)malloc(sizeof(t_data));
	if (d == NULL)
		ft_exit(d, "Malloc error struct data (main)\n");
	init_start(d);
	env_copy(d);
	while (1)
	{
		ft_putstr(PROMPT);
		d->line = ft_strnew(BUFF_SIZE);
		if (read(0, d->line, BUFF_SIZE) <= 0)
			ft_exit(d, "");
		d->line = ft_strtrim(d->line);
		check_exit(d);
		if (d->line[0] != '\0')
		{
			pid = fork();
			if (pid == 0)
			{
				lx_lexer(d->line, d);
				prs_parser(d);
				_exit(0);
			}
			else
				wait(NULL);
		}
		ft_memdel((void **)&d->line);
		lx_full_free(d);
	}
}


// int		main(void)
// {
// 	t_data	*d;
// 	pid_t	father;

// 	d = (t_data *)malloc(sizeof(t_data));
// 	if (d == NULL)
// 		ft_exit(d, "Malloc error struct data (main)\n");
// 	init_start(d);
// 	env_copy(d);
// 	while (1)
// 	{
// 		ft_putstr(PROMPT);
// 		get_next_line(0, &d->line);
// 		d->line = ft_strtrim(d->line);
// 		check_exit(d);
// 		lx_lexer(d->cmd, d);
// 		if (build_check(d) != 1)
// 		{
// 			if (d->line[0] != '\0')
// 			{
// 				if ((father = fork()) == -1)
// 					ft_exit(d, "fork error in main\n");
// 				if (father == 0)
// 				{
// 					exe_execve(d);
// 					_exit(1);
// 				}
// 				else
// 					wait(NULL);
// 			}
// 		}
// 		ft_memdel((void **)&d->line);
// 	}
// }
