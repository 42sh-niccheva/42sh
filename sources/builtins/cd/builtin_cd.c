/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:08:57 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/16 14:17:24 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_cd.h"
#include "hashtable.h"
#include "general.h"
#include <errno.h>
#include <sys/syslimits.h>

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

static int	cd_move_to(const char *target)
{
	char *path;

	path = NULL;
	path = getcwd(path, PATH_MAX);
	if (chdir(target) < 0)
	{
		ft_perror("cd");
		return (1);
	}
	change_var_env("OLDPWD", path);
	ft_strdel(&path);
	path = getcwd(path, PATH_MAX);
	change_var_env("PWD", path);
	return (0);
}

static int	cd_to_var_env(const char *program, const char *var_env)
{
	t_hashtable	*var;

	var = hashtable_search_key(g_env, var_env);
	if (var && (!ft_strequ(var->value, "") || ft_strequ(var_env, "HOME")))
	{
		if (ft_strequ(var->value, ""))
			return (0);
		if (ft_strequ(var_env, "OLDPWD"))
			ft_putendl(var->value);
		return (cd_move_to(var->value));
	}
	else
	{
		ft_putstr_fd(program, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(var_env, 2);
		ft_putendl_fd(" not set.", 2);
		return (1);
	}
	return (0);
}

int			builtin_cd(int argc, const char **argv, char **env)
{
	t_command	*command;
	int			i;

	(void)env;
	command = builtin_cd_init();
	if (argc == 1)
		return (cd_to_var_env(argv[0], "HOME"));
	else if (ft_strequ(argv[1], "-"))
		return (cd_to_var_env(argv[0], "OLDPWD"));
	if (!parse_command(argv, command))
		return (0);
	else
	{
		i = skip_options(argv);
		return (cd_move_to(argv[i]));
	}
	return (0);
}
