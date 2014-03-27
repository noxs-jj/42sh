/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:05:40 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/27 15:22:06 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** We write all arg until the end of cmd
** We write a '\n' at the end if needed
** print the string until ' ', '\t', 34 or 39
** return the actual place
** search "-n", if found, recall the function until it find an other char
*/

static int	is_option(char *str, int j)
{
	int		i;

	i = j;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] && str[i + 1] == 'n'
			&& ((!str[i + 2]) || str[i + 2] == ' '
				|| str[i + 2] == '\t'))
		{
			i += 2;
			return (is_option(str, i));
		}
		if (str[i] != ' ' && str[i] != '\t')
			return (j);
		i++;
	}
	return (j);
}

static int	ft_print_echo(char *str, int i)
{
	int		quote;

	quote = (str[i] == 34 ? 34 : 0);
	quote = (str[i] == 39 ? 39 : quote);
	if (quote == 0)
	{
		while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else if (quote != 0)
	{
		i++;
		while (str[i] != '\0' && str[i] != quote)
		{
			ft_putchar(str[i]);
			i++;
		}
		return (i);
	}
	return (i);
}

void		build_echo(t_data *d)
{
	int		i;
	int		first;

	i = 4;
	first = 0;
	if (d->toexec[i])
	{
		i = is_option(d->toexec, i);
		while (d->toexec[i])
		{
			while (d->toexec[i] == ' ' || d->toexec[i] == '\t')
				i++;
			if (first == 1 && d->toexec[i] != '\0')
				ft_putchar(' ');
			if (d->toexec[i])
				i = ft_print_echo(d->toexec, i);
			if (d->toexec[i])
				i++;
			first = 1;
		}
	}
	if (is_option(d->toexec, 4) == 4)
		ft_putchar('\n');
}
