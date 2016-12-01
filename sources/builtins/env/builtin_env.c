/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:16:39 by niccheva          #+#    #+#             */
/*   Updated: 2016/12/01 17:13:38 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_env.h"
#include "general.h"

static void	add_var_env(int i, const char **argv, t_hashtable **env)
{
	while (argv[i])
	{
		if (ft_strchr(argv[i], '=') == NULL)
			break ;
		hashtable_add(*env, hashtable_new_elem(argv[i], "="));
		++i;
	}
}

static bool	env_execution(int i, const char **argv)
{
	while (argv[++i])
	{
		if (!ft_strchr(argv[i], '='))
			return (true);
	}
	return (false);
}

int			builtin_env(int argc, const char **argv, char **env)
{
	t_command	*command;
	t_hashtable	*new_env;
	int			i;

	(void)argc;
	command = builtin_env_init();
	if (!parse_command(argv, command))
		return (0);
	if (!is_active(command, "i"))
		new_env = hashtable_create_from_tab((const char **)env, "=");
	else
		new_env = hashtable_new("", "");
	i = skip_options(argv);
	add_var_env(i, argv, &new_env);
	if (!env_execution(i, argv))
		hashtable_display_with_delim(new_env, "=");
	return (0);
}
