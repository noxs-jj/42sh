/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_double_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:03:31 by scohen            #+#    #+#             */
/*   Updated: 2014/03/25 23:33:49 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_count_strstr(char *str, char *cmp)
{
	int		i;
	int		number;
	int		j;

	i = 0;
	number = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (cmp[j] && str[i] && str[i] == cmp[j])
		{
			j++;
			i++;
			if (!(cmp[i]))
				number++;
		}
		i++;
	}
	return (number);
}

static void	cd_double_dot2(char *av, int *i, int *j, char *pwd)
{
	*j = ft_count_strstr(av, "..");
	while (pwd[*i] != '\0')
		(*i)++;
	while (*i != 0 && j != 0)
	{
		if (pwd[*i] == '/')
			(*j)--;
		pwd[*i] = '\0';
		(*i)--;
	}
}

void		cd_double_dot(t_data *d, char *av)
{
	char	*pwd;
	int		i;
	int		tmp;
	int		j;

	tmp = 0;
	i = 0;
	pwd = ft_getenv("PWD", d->env);
	ft_setenv(d, "OLDPWD", pwd);
	if (av[2] == '\0')
	{
		while (pwd[i] != '\0')
		{
			if (pwd[i] == '/')
				tmp = i;
			i++;
		}
		while (i >= tmp)
			pwd[i--] = '\0';
	}
	else if (av[2] == '/')
		cd_double_dot2(av, &i, &j, pwd);
	ft_setenv(d, "PWD", pwd);
	if (pwd != NULL)
		ft_memdel((void **)&pwd);
}
