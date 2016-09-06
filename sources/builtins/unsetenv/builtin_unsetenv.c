/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:18:06 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 15:28:09 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_unsetenv.h"

int		builtin_unsetenv(int argc, const char **argv, char **env)
{
	(void)env;
	while (argc > 1)
	{
		--argc;
		if (hashtable_search_key(g_env, argv[argc]) != NULL) {

		}
	}
	return (0);
}
