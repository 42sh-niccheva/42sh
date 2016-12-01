/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_clean_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:47:58 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/01 14:24:22 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_cd.h"
#include "hashtable.h"
#include "general.h"

char	*change_path(char **path, const char *target, char *start, char *end)
{
	char	*new_path;
	char	*elem;
	char	*tmp;

	new_path = NULL;
	elem = ft_strsub(target, start - target, end - start);
	if (ft_strequ(elem, ".."))
		new_path = ft_strsub(*path, 0, ft_strrchr(*path, '/') - *path);
	else if (ft_strequ(elem, "."))
		new_path = ft_strdup(*path);
	else
	{
		tmp = ft_strjoin(*path, "/");
		new_path = ft_strjoin(tmp, elem);
		ft_strdel(&tmp);
	}
	ft_strdel(path);
	ft_strdel(&elem);
	return (new_path);
}

char	*new_path_with(const char *path, const char *target)
{
	char	*new_path;
	char	*ptr_start;
	char	*ptr_end;
	char	*tmp;

	new_path = ft_strdup(path);
	if (new_path[ft_strlen(new_path) - 1] == '/')
		new_path[ft_strlen(new_path) - 1] = 0;
	ptr_start = (char *)target;
	while ((ptr_end = ft_strchr(ptr_start, '/')) != NULL)
	{
		new_path = change_path(&new_path, target, ptr_start, ptr_end);
		ptr_start = ptr_end + 1;
	}
	tmp = ft_strjoin(new_path, "/");
	ft_strdel(&new_path);
	new_path = tmp;
	tmp = ft_strjoin(new_path, ptr_start);
	ft_strdel(&new_path);
	new_path = tmp;
	return (new_path);
}

char	*clean_target(const char *target)
{
	char	*new_target;
	char	*tmp;
	int		i;

	i = 0;
	new_target = ft_strdup(target);
	while (ft_strstart_with(new_target, "./"))
	{
		tmp = ft_strdup(new_target + 2);
		ft_strdel(&new_target);
		new_target = tmp;
	}
	i = ft_strlen(new_target);
	while (--i > 0)
	{
		if (new_target[i] == '/')
			new_target[i] = 0;
		else
			break ;
	}
	return (new_target);
}

char	*builtin_cd_clean_path(const char *path, const char *target)
{
	char	*new_path;
	char	*new_target;

	new_path = NULL;
	new_target = clean_target(target);
	new_path = new_path_with(path, new_target);
	return (new_path);
}
