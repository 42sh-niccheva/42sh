/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_symlink.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:50:47 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/01 12:56:48 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_cd.h"
#include "hashtable.h"
#include "general.h"

static void	change_var_env(const char *var_name, const char *value)
{
	t_hashtable	*var;

	var = hashtable_search_key(g_env, var_name);
	if (var)
	{
		ft_strdel(&(var->value));
		var->value = ft_strdup(value);
	}
	else
		hashtable_add(g_env, hashtable_new(var_name, value));
}

int		builtin_cd_symlink(const char *target)
{
	char	*path;
	char	*new_path;

	path = NULL;
	path = getcwd(NULL, 0);
	if (chdir(target) < 0)
	{
		ft_perror("cd");
		return (1);
	}
	change_var_env("OLDPWD", path);
	new_path = builtin_cd_clean_path((const char *)path, target);
	ft_strdel(&path);
	path = new_path;
	change_var_env("PWD", path);
	return (0);
}
