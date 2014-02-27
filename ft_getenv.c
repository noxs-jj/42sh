/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:39:35 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/27 15:29:58 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

size_t	arraylen(char **array)
{
	size_t	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL && array[i][0] != '\0')
			++i;
	}
	else
		ft_putendl("Could not get length of NULL array");
	return (i);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_memalloc(size));
	if (size == 0)
		return (ptr);
	new_ptr = ft_memalloc(size);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}

char	**env_cpy(char **env)
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

char	*env_getenv(char *str, char **env)
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

void	env_del(char ***env)
{
	char	***p;

	p = env;
	while (**env)
	{
		free(**env);
		**env = NULL;
		++*env;
	}
	free(**p);
	*p = NULL;
}


void	env_putenv(char ***env, char *var, char *val)
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
	(*env)[arraylen(*env)] = tmp;
}

int		env_search(char **env, char *str)
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

void	env_setenv(char ***env, char *var, char *val)
{
	char	*tmp;

	if (env_getenv(var, *env) == NULL)
		env_putenv(env, var, val);
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
		(*env)[env_search(*env, var)] = tmp;
	}
}

void	env_print(char **env)
{
	while (*env && **env)
	{
		ft_putendl(*env);
		++env;
	}
}

/*
int		main(int ac, char **av, char **old_env)
{
	char	**env;
	char	**tofree;
	char	*var;

	tofree = env = env_cpy(old_env);
	env_print(env);
	var = env_getenv(env, av[1]);
	puts(var);
	env_del(&env);
	(void)ac;
	(void)av;
	return (0);
}

int		main(int ac, char **av, char **old_env)
{
	char	**env;
	char	**tofree;

	tofree = env = env_cpy(old_env);
	//env_print(env);
	env_setenv(&env, av[1], av[2]);
	env_print(env);
	env_del(&env);
	(void)ac;
	(void)av;
	return (0);
}
*/

