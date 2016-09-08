/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 14:53:45 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/08 16:18:51 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_builtins.h"
#include "builtins/builtin_setenv.h"
#include "builtins/builtin_unsetenv.h"

#define PHASE "UNSETENV: "

void		unsetenv_test(char **env)
{
	char	**args;

	ft_putendl("\n");
	header_test("UNSETENV");

	args = (char **)malloc(sizeof(args) * 6);
	args[0] = ft_strdup("unsetenv");
	args[1] = ft_strdup("key2");
	args[2] = 0;
	args[3] = 0;
	args[4] = 0;
	args[5] = 0;

	/*
	**	Add some key
	*/
	builtin_setenv(2, (const char **)args, env);

	ft_strdel(&args[1]);
	args[1] = ft_strdup("key3");
	builtin_setenv(2, (const char **)args, env);

	ft_strdel(&args[1]);
	args[1] = ft_strdup("key4");
	builtin_setenv(2, (const char **)args, env);

	printf("## %sBefore unset variables in environment\n", PHASE);
	ft_strdel(&args[1]);
	builtin_setenv(1, (const char **)args, env);

	args[1] = ft_strdup("key");
	args[2] = ft_strdup("key2");
	args[3] = ft_strdup("key3");
	args[4] = ft_strdup("key4");
	args[5] = ft_strdup("key5");


	printf("\n## %sunsetenv key key2 key3 key4 key5\n", PHASE);
	builtin_unsetenv(6, (const char **)args, env);

	ft_strdel(&args[1]);
	builtin_setenv(1, (const char **)args, env);

	ft_strdel(&args[0]);
	ft_strdel(&args[1]);
	ft_strdel(&args[2]);
	ft_strdel(&args[3]);
	ft_strdel(&args[4]);
	ft_strdel(&args[5]);
	free(args);
}
