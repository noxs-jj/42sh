/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:25 by scohen            #+#    #+#             */
/*   Updated: 2014/03/11 18:02:29 by scohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		cd_error(char *name)
{
	if (is_dir(name) == 0)
		return (ft_printf("42sh : %s : is not a directory.\n", name));
	if (access(name, F_OK) == -1)
		return (ft_printf("42sh : %s : directory not found.\n", name));
	if (access(name, X_OK) == -1)
		return (ft_printf("42sh : %s : permission denied.\n", name));
	return (0);
}
