/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:06:53 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/02/28 17:06:25 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int		ft_pipex_left(char **cmd, int *pid, char **env, int *fd)
{
	pid[0] = fork();
	if (pid[0] < 0)
	{
		ft_putendl_fd("FORK ERROR (LEFT)", 2);
		return (-2);
	}
	if (pid[0] == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(cmd[0], cmd, env);
		exit(1);
	}
	return (1);
}

static int		ft_pipex_right(char **cmd, int *pid, char **env, int *fd)
{
	int				tmp;

	tmp = -2;
	pid[1] = fork();
	if (pid[1] < 0)
	{
		ft_putendl_fd("FORK ERROR (RIGHT)", 2);
		return (-2);
	}
	if (pid[1] == 0)
	{
		if ((tmp = open("/tmp/.jjmnmmlvjsc.pipe",
			O_CREAT | O_WRONLY, 0777)) < 0)
		{
			ft_putendl_fd("open error", 2);
			return (-1);
		}
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(tmp, 1);
		execve(cmd[0], cmd, env);
		exit(1);
	}
	else if (pid[1] > 0)
		wait(NULL);
	return (1);
}

void			ope_pipe(t_tree *t, t_data *d)
{
	char			**cmd[2];
	int				pid[2];
	int				fd[2];

	cmd[0] = ft_strsplit(t->left->command, ' ');
	cmd[1] = ft_strsplit(t->right->command, ' ');
	if (pipe(fd) < 0)
	{
		t->response = 1;
		return ;
	}
	if (ft_pipex_left(cmd[0], pid, d->env, fd) < 0)
	{
		t->response = 1;
		return ;
	}
	if (ft_pipex_right(cmd[1], pid, d->env, fd) < 0)
	{
		t->response = 1;
		return ;
	}
	t->command = ft_strdup("cat /tmp/.jjmnmmlvjsc.pipe");
	t->type = 2;
	t->response = 0;
}
