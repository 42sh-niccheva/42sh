/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:09:38 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 13:28:04 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_echo.h"

static void		display_arg(t_command *command, const char *arg)
{
	char	*new_arg;

	new_arg = NULL;
	if (is_active(command, "e") && !is_active(command, "E"))
		ft_putstr(arg);
	else
		ft_putstr(ft_strreplace(arg, "\\", "\\"));
	if (new_arg)
		ft_strdel(&new_arg);
}

int				builtin_echo(int argc, const char **argv, char **env)
{
	t_command	*command;
	int			i;

	(void)argc;
	(void)env;
	command = builtin_echo_init();
	if (parse_command(argv, command))
	{
		if (is_active(command, "help"))
			details_of_command(command);
		else
		{
			i = skip_options(argv);
			while (argv[i])
			{
				display_arg(command, argv[i]);
				if (argv[++i])
					ft_putchar(' ');
			}
			if (!is_active(command, "n"))
				ft_putchar('\n');
		}
	}
	return (0);
}
