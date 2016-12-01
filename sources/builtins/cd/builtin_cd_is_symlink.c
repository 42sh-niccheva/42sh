/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_is_symlink.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:30:35 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/01 11:49:26 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_cd.h"
#include <stdbool.h>
#include <sys/stat.h>

bool	builtin_cd_is_symlink(const char *target)
{
	struct stat		buf;
	int				result;

	result = lstat(target, &buf);
	return (result == 0);
}
