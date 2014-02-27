/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:24:35 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/26 15:44:47 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "ft_cd.h"

/*
** Dependencies:
**	- char	*env_getenv(const char *name, t_data *d);
**	- int	env_setenv(const char *name, const char *value, t_data *d);
** TESTING
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

static int	ft_cd_tilde(t_data *data, char **cmd)
{
	int		error;

	error = ft_check_dir(cmd[1]);
	if (chdir(env_getenv("HOME", data)) == 0)
	{
		env_setenv("OLDPWD", env_getenv("PWD", data), data);
		env_setenv("PWD", env_getenv("HOME", data), data);
	}
	return (error);
}

static int	ft_cd_dash(t_data *data, char **cmd)
{
	int		error;
	char	*tmp;

	error = ft_check_dir(cmd[1]);
	if (chdir(env_getenv("OLDPWD", data)) == 0)
	{
		tmp = env_getenv("PWD", data);
		env_setenv("PWD", env_getenv("OLDPWD", data), data);
		env_setenv("OLDPWD", tmp, data);
	}
	return (error);
}

static int	ft_cd_normal(t_data *data, char **cmd)
{
	int		error;

	error = ft_check_dir(cmd[1]);
	if (chdir(cmd[1]) == 0 && error == FT_CD_SUCCESS)
	{
		env_setenv("OLDPWD", env_getenv("PWD", data), data);
		env_setenv("PWD", cmd[1], data);
	}
	return (error);
}

int			ft_cd(t_data *data, char *str)
{
	int		error;
	char	**cmd;

	cmd = ft_strsplit(str, ' ');
	error = FT_CD_SUCCESS;
	if (cmd[1] == NULL || ft_strcmp(cmd[1], "~") == 0)
		error = ft_cd_tilde(data, cmd);
	else if (ft_strcmp(cmd[1], "-") == 0)
		error = ft_cd_dash(data, cmd);
	else if (cmd[1] != NULL)
		 error = ft_cd_normal(data, cmd);
	if (error != FT_CD_SUCCESS)
		WR(2, "Chdir failed\n");
	return (error);
}

void		ft_cd_test(int ac, char **av)
{
	t_data	data;
	char	*cmd = "cd /";
	char	*cmd2 = "cd ~";
	char	*cmd3 = "cd -";

	ft_printf("getenv HOME: %s\n", getenv("HOME"));
	ft_printf("getenv PWD: %s\n", getenv("PWD"));
	ft_printf("getenv OLDPWD: %s\n", getenv("OLDPWD"));
	ft_printf("\n\ngoing to: %s\n", av[0 + 1]);
	ft_cd(&data, cmd);
	ft_printf("\n\ngetenv HOME: %s\n", getenv("HOME"));
	ft_printf("getenv PWD: %s\n", getenv("PWD"));
	ft_printf("getenv OLDPWD: %s\n", getenv("OLDPWD"));
	ft_printf("\n\ngoing to: %s\n", av[1 + 1]);
	ft_cd(&data, cmd2);
	ft_printf("\n\ngetenv HOME: %s\n", getenv("HOME"));
	ft_printf("getenv PWD: %s\n", getenv("PWD"));
	ft_printf("getenv OLDPWD: %s\n", getenv("OLDPWD"));
	ft_printf("\n\ngoing to: %s\n", av[2 + 1]);
	ft_cd(&data, cmd3);
	ft_printf("\n\ngetenv HOME: %s\n", getenv("HOME"));
	ft_printf("getenv PWD: %s\n", getenv("PWD"));
	ft_printf("getenv OLDPWD: %s\n", getenv("OLDPWD"));
	(void)av;
	(void)ac;
}

int		main(int ac, char **av)
{
	ft_cd_test(ac, av);
	return (0);
}
