/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:09:38 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/09 12:29:59 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_echo.h"

static int		echo_char_special(const char *arg, int *i)
{
	if ()
	return (0);
}

static int		display_arg(t_command *command, const char *arg)
{
/* 	char	*new_arg; */

/* 	new_arg = NULL; */
/* 	if (!is_active(command, "e") && is_active(command, "E")) */
/* 		ft_putstr(arg); */
/* 	else */
/* 	{ */
/* 		new_arg = ft_strreplace(arg, "\\\\", "\\"); */
/* 		ft_putstr(new_arg); */
/* 	} */
/* 	if (new_arg) */
/* 		ft_strdel(&new_arg); */
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
			value = echo_var_env(arg, &i);
		else if (arg[i] == '\\')
			value = echo_char_special(arg, &i);
		else
			ft_putchar(arg[i]);
		++i;
	}
	return (value);
}

int				builtin_echo(int argc, const char **argv, char **env)
{
	t_command	*command;
	int			i;

	(void)argc;
	(void)env;
	command = builtin_echo_init();
	if (!parse_command(argv, command))
		return (0);
	if (is_active(command, "help"))
		details_of_command(command);
	else
	{
		i = skip_options(argv);
		while (argv[i])
		{
			if (display_arg(command, argv[i]))
				return (0);
			if (argv[++i])
				ft_putchar(' ');
		}
		if (!is_active(command, "n"))
			ft_putchar('\n');
	}
	return (0);
}
