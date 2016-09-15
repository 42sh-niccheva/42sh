/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 14:02:31 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/15 11:49:28 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_builtins.h"

void		header_test(const char *test)
{
	printf("\
######                         ######\n\
#                                   #\n\
#             %-10s            #\n\
#                                   #\n\
######                         ######\n\n", test);
}

void		init(char **env)
{
	g_env = hashtable_create_from_tab((const char **)env, "=");
}

int			main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init(env);
	cd_test();
	echo_test(env);
	env_test();
	exit_test();
	setenv_test(env);
	unsetenv_test(env);

	hashtable_delete(g_env);
	return (0);
}
