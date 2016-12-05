/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_openread_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:16:29 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/05 11:44:54 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		fd_openread_file(const char *pathname)
{
	int			fd;
	struct stat	info;

	fd = -1;
	if ((access(pathname, F_OK) < 0) || (access(pathname, R_OK) < 0))
		ft_perror("access");
	else
	{
		if (stat(pathname, &info) < 0)
			ft_perror("stat");
		else if (S_ISREG(info.st_mode))
		{
			fd = open(pathname, O_RDONLY);
			if (fd < 0)
				ft_perror("open");
		}
		else
		{
			ft_putstr_fd(pathname, 2);
			ft_putendl_fd(": Not a regular file", 2);
		}
	}
	return (fd);
}
