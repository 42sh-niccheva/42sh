/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:43:31 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/05 11:06:10 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		fd_create_file(const char *pathname)
{
	int		fd;

	fd = -1;
	if (!access(pathname, F_OK) && (access(pathname, W_OK) < 0))
		ft_perror("access");
	else
	{
		fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd < 0)
			ft_perror("open");
	}
	return (fd);
}
