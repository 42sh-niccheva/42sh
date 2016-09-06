/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:17:18 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 14:03:58 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_setenv.h"
#include "hashtable.h"

static int		builtin_setenv_add(int argc, const char **argv)
{
	t_hashtable	*elem_hashtable;
	int			value;

	elem_hashtable = NULL;
	value = -1;
	if ((elem_hashtable = hashtable_new_elem(NULL, NULL)) != NULL)
	{
		value = builtin_setenv_add_key(elem_hashtable, argv[1]);
		if (argc == 3 && value == 0)
		{
			value = builtin_setenv_add_value(elem_hashtable, argv[2]);
		}
		if (value == 0)
		{
			list_add_tail(&(elem_hashtable->list), &(g_env->list));
		}
		else
		{
			hashtable_delete_entry(&elem_hashtable);
		}
	}
	return (value);
}

static int		builtin_setenv_modify(int argc, const char **argv,
									t_hashtable *elem)
{
	int		value;

	value = 0;
	if (argc == 3)
		hashtable_modify_elem(elem, argv[1], argv[2]);
	else
		hashtable_modify_elem(elem, argv[1], "");
	return (value);
}

int				builtin_setenv(int argc, const char **argv, char **env)
{
	int			value;
	t_hashtable	*elem_hashtable;

	(void)env;
	value = 0;
	elem_hashtable = NULL;
	if (argc > 3)
	{
		ft_putendl_fd("setenv: Too many arguments.", 2);
		value = -1;
	}
	else if (argc == 1)
		hashtable_display_with_delim(g_env, "=");
	else
	{
		if ((elem_hashtable = hashtable_search_key(g_env, argv[1])) != NULL)
		{
			value = builtin_setenv_modify(argc, argv, elem_hashtable);
		}
		else
		{
			value = builtin_setenv_add(argc, argv);
		}
	}
	return (value);
}
