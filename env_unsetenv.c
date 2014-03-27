/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:08:01 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/27 15:06:18 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	env_unsetenv2(void)
{
	ft_putstr_fd("env is null | ft_getenv\n", 2);
	_exit(1);
}

static void	env_unsetenv3(t_data *d, char *tofree)
{
	if (tofree != NULL)
		ft_strdel(&tofree);
	if (d->varenv != NULL)
		ft_strdel(&d->varenv);
}

void		env_unsetenv(t_data *d)
{
	char	*tofree;
	int		i;

	i = 0;
	tofree = NULL;
	if (d->cenv == NULL)
		env_unsetenv2();
	while (d->cenv[i] != NULL
		&& ft_strncmp(d->cenv[i], d->varenv, ft_strlen(d->varenv)) != 0)
		++i;
	if (d->cenv[i] != NULL)
	{
		tofree = d->cenv[i];
		while (d->cenv[i] != NULL)
		{
			d->cenv[i] = d->cenv[i + 1];
			++i;
		}
		d->cenv[i] = NULL;
	}
	env_unsetenv3(d, tofree);
}
