/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:24:35 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/26 14:05:47 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "ft_cd.h"

/*
** Dependencies:
**	- char	*env_getenv(const char *name);
**	- int	env_setenv(const char *name, const char *value, int overwrite);
** TEST seems ok. Needs team approval
*/

static int	is_dir(const char *path)
{
	struct stat		statbuf;

	stat(path, &statbuf);
	return (S_ISDIR(statbuf.st_mode));
}

static int	ft_check_dir(char *dir)
{
	if (access(dir, F_OK) != 0)
		return (FT_CD_NOEXIST);
	if (access(dir, X_OK) != 0)
		return (FT_CD_ADENIED);
	if (!is_dir(dir))
		return (FT_CD_NOTADIR);
	return (FT_CD_SUCCESS);
}

static int	ft_cd_tilde(t_data *data)
{
	int		error;

	error = ft_check_dir(data->cmd[1]);
	if (chdir(env_getenv("HOME")) == 0)
	{
		env_setenv("OLDPWD", env_getenv("PWD"), 1);
		env_setenv("PWD", env_getenv("HOME"), 1);
	}
	return (error);
}

static int	ft_cd_dash(t_data *data)
{
	int		error;

	error = ft_check_dir(data->cmd[1]);
	if (chdir(env_getenv("OLDPWD")) == 0)
	{
		tmp = env_getenv("PWD");
		env_setenv("PWD", env_getenv("OLDPWD"), 1);
		env_setenv("OLDPWD", tmp, 1);
	}
	return (error);
}

static int	ft_cd_normal(t_data *data)
{
	int		error;

	error = ft_check_dir(data->cmd[1]);
	if (chdir(data->cmd[1]) == 0 && error == FT_CD_SUCCESS)
	{
		env_setenv("OLDPWD", env_getenv("PWD"), 1);
		env_setenv("PWD", data->cmd[1], 1);
	}
	return (error);
}

int			ft_cd(t_data *data)
{
	int		error;
	char	*tmp;

	error = FT_CD_SUCCESS;
	if (data->cmd[1] == NULL || ft_strcmp(data->cmd[1], "~") == 0)
		error = ft_cd_tilde(data);
	else if (ft_strcmp(data->cmd[1], "-") == 0)
		error = ft_cd_dash(data);
	else if (data->cmd[1] != NULL)
		 error = ft_cd_normal(data);
	else
	if (error != FT_CD_SUCCESS)
		WR(2, "Chdir failed\n");
	return (error);
}

/*
**  int			ft_cd_test(int ac, char **av)
**  {
**  	t_data	data;
**  	char	*cmd[] = {"cd", av[1], NULL};
**  	char	*cmd2[] = {"cd", av[2], NULL};
**  	char	*cmd3[] = {"cd", av[3], NULL};
**
**  	data.cmd = cmd;
**  	ft_printf("env_getenv HOME: %s\n", env_getenv("HOME"));
**  	ft_printf("env_getenv PWD: %s\n", env_getenv("PWD"));
**  	ft_printf("env_getenv OLDPWD: %s\n", env_getenv("OLDPWD"));
**  	ft_printf("\n\ngoing to: %s\n", av[0 + 1]);
**  	ft_cd(&data);
**  	ft_printf("\n\ngetenv HOME: %s\n", env_getenv("HOME"));
**  	ft_printf("env_getenv PWD: %s\n", env_getenv("PWD"));
**  	ft_printf("env_getenv OLDPWD: %s\n", env_getenv("OLDPWD"));
**  	data.cmd = cmd2;
**  	ft_printf("\n\ngoing to: %s\n", av[1 + 1]);
**  	ft_cd(&data);
**  	ft_printf("\n\ngetenv HOME: %s\n", env_getenv("HOME"));
**  	ft_printf("env_getenv PWD: %s\n", env_getenv("PWD"));
**  	ft_printf("env_getenv OLDPWD: %s\n", env_getenv("OLDPWD"));
**  	data.cmd = cmd3;
**  	ft_printf("\n\ngoing to: %s\n", av[2 + 1]);
**  	ft_cd(&data);
**  	ft_printf("\n\ngetenv HOME: %s\n", env_getenv("HOME"));
**  	ft_printf("env_getenv PWD: %s\n", env_getenv("PWD"));
**  	ft_printf("env_getenv OLDPWD: %s\n", env_getenv("OLDPWD"));
**  	return (1);
**  }
*/
