/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:08:57 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/15 17:47:42 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_cd.h"
#include "hashtable.h"
#include "general.h"

static void	cd_move_to(const char *target)
{
	t_hashtable	*var;

	chdir(target);
}

static int	cd_to_var_env(const char *var_env)
{
	t_hashtable	*var;

	var = hashtable_search_key(g_env, var_env);
	if (var && (!ft_strequ(var->value, "") || ft_strequ(var_env, "HOME")))
	{
		if (ft_strequ(var_env, "HOME"))
			return (0);
		cd_move_to(var->value);
	}
	else
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(var_env, 2);
		ft_putendl_fd(" not set.", 2);
	}
}

int			builtin_cd(int argc, const char **argv, char **env)
{
	t_command	*command;
	int			i;

	(void)env;
	builtin_cd_init();
	if (ft_strequ(argv[1], "-"))
		return (cd_to_var_env("OLDPWD"));
	else if (argc == 1)
		return (cd_to_var_env("HOME"));
	if (!parse_command(argv, command))
		return (0);
	else
	{
		i = skip_options(argv);
		cd_move_to(argv[i]);
	}
	return (0);
}
