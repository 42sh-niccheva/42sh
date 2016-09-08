/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:18:06 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 15:47:23 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_unsetenv.h"
#include "general.h"
#include "hashtable.h"

int		builtin_unsetenv(int argc, const char **argv, char **env)
{
	t_hashtable	*entry;

	(void)env;
	if (argc == 1)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": Too few arguments.", 2);
		return (1);
	}
	entry = NULL;
	while (argc > 1)
	{
		--argc;
		if ((entry = hashtable_search_key(g_env, argv[argc])) != NULL)
		{
			hashtable_delete_entry(&entry);
		}
	}
	return (0);
}
