/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 13:58:34 by scohen            #+#    #+#             */
/*   Updated: 2014/03/19 17:59:59 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		free_vars(char *home, char *pwd, char *oldpwd);

static int		build_cd_check_for_env(t_data *d)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;

	home = ft_getenv("HOME", d->env);
	oldpwd = ft_getenv("OLDPWD", d->env);
	pwd = ft_getenv("PWD", d->env);
	if (oldpwd == NULL || pwd == NULL || home == NULL)
	{
		WR(2, "Cannot run `cd' without HOME or OLDPWD, PWD\n");
		free_vars(home, pwd, oldpwd);
		return (0);
	}
	free_vars(home, pwd, oldpwd);
	return (1);
}

static void		free_vars(char *home, char *pwd, char *oldpwd)
{
	if (home != NULL)
		free(home);
	if (pwd != NULL)
		free(pwd);
	if (oldpwd != NULL)
		free(oldpwd);
}

void			build_cd(t_data *d)
{
	char	**av;

	if (!build_cd_check_for_env(d))
		return ;
	ft_replace('\t', ' ', d->toexec);
	av = ft_strsplit(d->toexec, ' ');
	if (av[1] != NULL && ft_strcmp(av[1], ".") != 0)
	{
		if (ft_strcmp(av[1], "-") == 0)
			cd_dash(d, av[1]);
		else
		{
			if (chdir(av[1]) == -1)
				cd_error(av[1]);
			else
			{
				if (ft_strncmp(av[1], "..", 2) == 0
					&& (av[1][2] == '/' || av[1][2] == '\0'))
					cd_double_dot(d, av[1]);
				else
					cd_change_pwd(d, av[1]);
			}
		}
	}
	if (av[1] == NULL)
		cd_only(d, av[1]);
	free_tabtab(av);
}

void			free_tabtab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		ft_memdel((void **)&tab[i]);
		++i;
	}
	ft_memdel((void **)&tab);
}
