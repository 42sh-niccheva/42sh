/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 14:53:45 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/08 15:40:19 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_builtins.h"
#include "builtins/builtin_setenv.h"
#include <unistd.h>

#define PHASE "SETENV: "

void		setenv_test(char **env)
{
	char	**args;
	t_hashtable		*elem;

	args = (char **)malloc(sizeof(args) * 4);
	args[0] = ft_strdup("setenv");
	args[1] = ft_strdup("key");
	args[2] = ft_strdup("value");
	args[3] = 0;

//	printf("%s•\e[m ", KRED);
//	printf("%s•\e[m \n", KGRN);

	/*
	**	Add new value in environment
	*/
	builtin_setenv(3, (const char **)args, env);
	elem = hashtable_search_key(g_env, "key");
	if (elem)
		printf("%s•\e[m ", KGRN);
	else
		printf("%s•\e[m ", KRED);
	printf("%ssetenv key value \n\t=> search key in env:\n\tresult   %s=%s\
\n\texpected key=value\n\n",
		   PHASE, elem->key, elem->value);

	/*
	**	Modify value in environment
	*/
	ft_strdel(&args[2]);
	args[2] = ft_strdup("newvalue");

	builtin_setenv(3, (const char **)args, env);
	elem = hashtable_search_key(g_env, "key");
	if (elem && ft_strequ(elem->value, "newvalue"))
		printf("%s•\e[m ", KGRN);
	else
		printf("%s•\e[m ", KRED);
	printf("%ssetenv key newvalue \n\t=> search key in env:\n\tresult   %s=%s\
\n\texpected key=newvalue\n\n",
		   PHASE, elem->key, elem->value);

	/*
	**	Modify value in environment
	*/
	ft_strdel(&args[2]);

	builtin_setenv(2, (const char **)args, env);
	elem = hashtable_search_key(g_env, "key");
	if (elem && ft_strequ(elem->value, ""))
		printf("%s•\e[m ", KGRN);
	else
		printf("%s•\e[m ", KRED);
	printf("%ssetenv key \n\t=> search key in env:\n\tresult   %s=%s\
\n\texpected key=\n\n",
		   PHASE, elem->key, elem->value);

	/*
	**	Use setenv with too many arguments
	*/
	ft_strdel(&args[2]);
	int value;

	printf("%ssetenv key value tutu\n",
		   PHASE);
	value = builtin_setenv(4, (const char **)args, env);
	ft_putendl("");

	/*
	**	View environment
	*/
	ft_strdel(&args[1]);

	printf("%ssetenv \n\t=>\n",
		   PHASE);
	builtin_setenv(1, (const char **)args, env);


	ft_strdel(&args[0]);
	ft_strdel(&args[1]);
	ft_strdel(&args[2]);
	ft_strdel(&args[3]);
	free(args);
}
