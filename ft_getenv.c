/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:39:35 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/27 16:03:44 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	**ft_envcpy(char **env)
{
	char	**new;
	size_t	len;
	size_t	i;

	i = 0;
	len = arraylen(env);
	new = (char **)ft_memalloc(len * (sizeof(char *) + 2));
	if (new == NULL)
	{
		ft_putendl("Malloc error: could not copy environement");
		return (NULL);
	}
	while (i < len)
	{
		new[i] = ft_strdup(env[i]);
		++i;
	}
	new[i] = ft_strdup("\0");
	new[i + 1] = NULL;
	return (new);
}

/*
** Return values:
** NULL if *str is not found in **env
** Otherwise, returns an allocated COPY of the string found in **env
*/

char	*ft_getenv(char *str, char **env)
{
	size_t	i;
	char	*tmp;

	if ((tmp = ft_memalloc(ft_strlen(str) + 1)) != NULL)
	{
		tmp = ft_strcpy(tmp, str);
		tmp = ft_strcat(tmp, "=");
	}
	else
	{
		ft_putendl("Malloc error: could not allocate tmp");
		return (NULL);
	}
	i = 0;
	while (*env[i] != '\0' && ft_strncmp(env[i], tmp, ft_strlen(tmp)) != 0)
	{
		++i;
	}
	free(tmp);
	if (env[i][0] == '\0')
		return (NULL);
	return (ft_strdup(ft_strchr(env[i], '=')) + 1);
}

/*
** Takes the ADDRESS of a string of strings
** Frees each strings one by one
** Frees main string of strings
** Set value of the main pointer to NULL
*/

void	ft_putenv(char ***env, char *var, char *val)
{
	char	*tmp;

	if ((tmp = ft_memalloc(ft_strlen(var) + ft_strlen(val) + 1)) != NULL)
	{
		tmp = ft_strcpy(tmp, var);
		tmp = ft_strcat(tmp, "=");
		tmp = ft_strcat(tmp, val);
	}
	else
	{
		ft_putendl("Malloc error: could not allocate new variable");
		return ;
	}
	*env = ft_realloc(*env, sizeof(char *) * (arraylen(*env) + 1));
	(*env)[arraylen(*env)] = tmp;
}

int		ft_get_var_index(char **env, char *str)
{
	size_t	i;
	char	*tmp;

	if ((tmp = ft_memalloc(ft_strlen(str) + 1)) != NULL)
	{
		tmp = ft_strcpy(tmp, str);
		tmp = ft_strcat(tmp, "=");
	}
	else
	{
		ft_putendl("Malloc error: could not allocate tmp");
		return (-1);
	}
	i = 0;
	while (*env[i] != '\0' && ft_strncmp(env[i], tmp, ft_strlen(tmp)) != 0)
	{
		++i;
	}
	free(tmp);
	if (env[i][0] == '\0')
		return (-1);
	return (i);
}

void	ft_setenv(char ***env, char *var, char *val)
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

/*
int		main(int ac, char **av, char **old_env)
{
	char	**env;
	char	**tofree;
	char	*var;

	tofree = env = ft_envcpy(old_env);
	ft_printenv(env);
	var = ft_getenv(env, av[1]);
	puts(var);
	ft_envdel(&env);
	(void)ac;
	(void)av;
	return (0);
}

int		main(int ac, char **av, char **old_env)
{
	char	**env;
	char	**tofree;

	tofree = env = ft_envcpy(old_env);
	//ft_printenv(env);
	ft_setenv(&env, av[1], av[2]);
	ft_printenv(env);
	ft_envdel(&env);
	(void)ac;
	(void)av;
	return (0);
}
*/

