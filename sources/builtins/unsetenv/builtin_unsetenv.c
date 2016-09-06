/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:18:06 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 15:42:06 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_unsetenv.h"
#include "general.h"
#include "hashtable.h"

int		builtin_unsetenv(int argc, const char **argv, char **env)
{
	t_hashtable	*entry;

	(void)env;
	entry = NULL;
	while (argc > 1)
	{
		--argc;
		if ((entry = hashtable_search_key(g_env, argv[argc])) != NULL) {
			hashtable_delete_entry(&entry);
		}
	}
	return (0);
}
