/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 14:53:45 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/15 11:49:03 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_builtins.h"
#include "builtins/builtin_echo.h"
#include <unistd.h>

#define PHASE "ECHO: "

void		echo_test(char **env)
{
	char	**args;

	header_test("ECHO");

	args = (char **)malloc(sizeof(args) * 4);
	args[0] = ft_strdup("echo");
	args[1] = ft_strdup("test");
	args[2] = ft_strdup(" echo");
	args[3] = 0;

	printf("%secho test \" echo\" \nresult/expected \n", PHASE);
	builtin_echo(3, (const char **)args, env);
	system("echo test \" echo\"");
	ft_putendl("\n");

	ft_strdel(&args[1]);
	ft_strdel(&args[2]);
	args[1] = ft_strdup("-e");
	args[2] = ft_strdup("test\\040\\t\\0164est");

	printf("%secho -e 'test\\040\\t\\0164est' \nresult/expected \n", PHASE);
	builtin_echo(3, (const char **)args, env);
	system("echo 'test\\040\\t\\0164est'");
	ft_putendl("\n");

	ft_strdel(&args[1]);
	args[1] = ft_strdup("-E");

	printf("%secho -E 'test\\040\\t\\0164est' \nresult/expected \n", PHASE);
	builtin_echo(3, (const char **)args, env);
	printf("test\\040\\t\\0164est\n\n");

	ft_strdel(&args[1]);
	ft_strdel(&args[2]);
	args[1] = ft_strdup("-e");
	args[2] = ft_strdup("test\\n\\t\\vtest");

	printf("%secho -e 'test\\n\\t\\vtest' \nresult/expected \n", PHASE);
	builtin_echo(3, (const char **)args, env);
	system("echo 'test\\n\\t\\vtest'");
	ft_putendl("\n");

	ft_strdel(&args[1]);
	args[1] = ft_strdup("-E");

	printf("%secho -E 'test\\n\\t\\vtest' \nresult/expected \n", PHASE);
	builtin_echo(3, (const char **)args, env);
	printf("test\\n\\t\\vtest\n\n");
	ft_strdel(&args[0]);
	ft_strdel(&args[1]);
	ft_strdel(&args[2]);
	ft_strdel(&args[3]);
	free(args);
}
