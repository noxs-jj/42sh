/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:06:53 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/02/26 18:46:31 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ope_pipe(t_tree *t, char *file)
{
	int		father;
	int		pfd[2];
	int		fd;
	char	*buff;

	if (t->left != NULL)
	{
		if (fd = open(file, O_WRONLY, O_CREATE, O_TRUNC, 0777) == -1)
		{
			WR(2, "file open Failed (ope_pipe)\n");
			return (-1);
		}

		if (pipe(pfd) == -1)
		{
			WR(2, "Pipe Failed (ope_pipe)\n");
			return (-1);
		}
		close(fd); /* remove this maybe useless */

		if (father = fork() < 0) /* exec fork () and check if failed */
		{
			WR(2, "Fork Failed (ope_pipe)\n");
			return (-1);
		}
		if (father == 0) /* son */
		{
			close(pfd[1]); /* close doors father entry */
			dup2(pfd[1], 1); /* STDOUT 1 go to pfd[1] */
			close(pfd[1]);
			parse_cmd(t->left->command);
		}
		else /* father */
		{
			close(pfd[0]); /* close doors son entry */
			dup2(pfd[0], 0); /* pfd[0] go to STDIN */
			close(pfd[0]);
			if (read(0, &buff, 1) < 0) /* fill buff with result of son's execve */
			{
				WR(2, "Read failed (ope_pipe)");
				return (-1);
			}
			t->command = buff; /* current command take result of son's execve*/
		}
	}
}
