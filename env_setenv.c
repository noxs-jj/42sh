/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:39:35 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 19:51:30 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_setenv(char ***env, char *var, char *val)
{
	char	*tmp;

	if (ft_getenv(var, *env) == NULL)
		ft_putenv(env, var, val);
	else
	{
		*env = ft_realloc(*env, sizeof(char *) * (arraylen(*env) + 1));
		if ((tmp = malloc(ft_strlen(var) + ft_strlen(val) + 1)) != NULL)
		{
			tmp = ft_strcpy(tmp, var);
			tmp = ft_strcat(tmp, "=");
			tmp = ft_strcat(tmp, val);
		}
		else
		{
			ft_putendl("Malloc error: could not allocate variable (setenv)");
			return ;
		}
		(*env)[ft_get_var_index(*env, var)] = tmp;
	}
}

void		env_setenv(t_data *d)
{
	ft_setenv(&d->env, d->varenv, d->valenv);
}

/*
int		main(int ac, char **av, char **old_env)
{
	char	**env;
	char	**tofree;

	tofree = env = ft_envcpy(old_env);
	puts("\n\n\n\n\n\n\n\nBefore\n-------------------------------------------");
	ft_printenv(env);
	puts("Set\n----------------------------------------------");
	ft_setenv(&env, av[1], av[2]);
	ft_setenv(&env, av[1], av[2]);
	ft_setenv(&env, av[1], av[2]);
	ft_setenv(&env, av[1], av[2]);
	ft_printenv(env);
	puts("Unset\n--------------------------------------------");
	ft_unsetenv(av[1], env);
	ft_printenv(env);
	ft_envdel(&env);
	(void)ac;
	(void)av;
	return (0);
}
*/
