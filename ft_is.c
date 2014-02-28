/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 18:46:43 by nmohamed          #+#    #+#             */
/*   Updated: 2014/02/28 19:38:52 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				is_dir(const char *path)
{
	struct stat		statbuf;

	stat(path, &statbuf);
	return (S_ISDIR(statbuf.st_mode));
}

int				is_absolute(char *path)
{
	if (path[0] == '/')
		return (1);
	return (0);
}

int				is_dotslash(char *path)
{
	if (path[0] == '.' && path[1] == '/')
		return (1);
	return (0);
}
