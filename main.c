/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:35:27 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/15 14:33:43 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	prompt_exit(t_data *d);

int			main(void)
{
	t_data	*d;
//	int		pid;

	if (!(d = (t_data *)malloc(sizeof(t_data))))
		ft_exit(d, "Malloc error struct data (main)\n");
	init_start(d);
	while (1)
	{
		prompt_exit(d);
//		if (d->line[0] != '\0')
//		{
//			if ((pid = fork()) < 0)
//			WR(2, "Fork error (main)\n");
//			if (pid == 0)
//			{
		lx_lexer(d->line, d);
		prs_parser(d);
//				_exit(0);
//			}
//			else
		while (waitpid(WAIT_ANY, NULL, WNOHANG) != -1)
			;
//		}
		ft_memdel((void **)&d->line);
		lx_full_free(d);
	}
}

static void	prompt_exit(t_data *d)
{
	char	*tmp;

	ft_putstr(PROMPT);
	d->line = ft_strnew(BUFF_SIZE);
	if (read(0, d->line, BUFF_SIZE) <= 0)
		WR(2, "Read error (main)\n");
	tmp = d->line;
	d->line = ft_strtrim(d->line);
	ft_memdel((void **)&tmp);
	check_exit(d);
}

/*
static void	ft_print(t_data *d)
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
}
*/
