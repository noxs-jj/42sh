/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:35:27 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/19 16:51:04 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	prompt_exit(t_data *d);

int			main(void)
{
	t_data	*d;

	if (!(d = (t_data *)malloc(sizeof(t_data))))
		ft_exit(d, "Malloc error struct data (main)\n");
	init_start(d);
	while (1)
	{
		prompt_exit(d);
		lx_lexer(d->line, d);
		prs_parser(d);
		ft_memdel((void **)&d->line);
		lx_full_free(d);
	}
}

static void	prompt_exit(t_data *d)
{
	char	*tmp;

	ft_putstr(PROMPT);
	d->line = ft_strnew(BUFF_SIZE);
	if (read(0, d->line, BUFF_SIZE) <= 0 && errno != EINTR)
		ft_exit(d, "End of transmission\n");
	tmp = d->line;
	d->line = ft_strtrim(d->line);
	ft_memdel((void **)&tmp);
	check_exit(d);
}
