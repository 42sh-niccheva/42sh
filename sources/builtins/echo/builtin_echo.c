/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:09:38 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/09 15:38:32 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_echo.h"
#include "hashtable.h"
#include "general.h"

static int		echo_var_env(const char *arg, int *i)
{
	int			start;
	char		*key;
	t_hashtable	*var_env;

	start = *i;
	key = NULL;
	while (arg[*i] == '_' || ft_isalnum(arg[*i]))
		++(*i);
	key = ft_strncpy(key, &arg[start], (*i - start));
	if ((var_env = hashtable_search_key(g_env, key)) != NULL)
		ft_putstr(var_env->value);
	ft_strdel(&key);
	hashtable_delete_entry(&var_env);
	return (0);
}

static int		echo_char_special(const char *arg, int *i)
{
	int					j;
	static const char	chars[] = "abfnrtv";
	static const char	chars_spec[] = "\a\b\f\n\r\t\v";

	if (arg[*i] == 'c')
		return (1);
	j = 0;
	while (j < 7)
	{
		if (arg[*i] == chars[j])
		{
			ft_putchar(chars_spec[j]);
			break ;
		}
		++j;
	}
	if (j == 7)
	{
		ft_putchar('\\');
		--(*i);
	}
	return (0);
}

static int		display_arg(t_command *command, const char *arg)
{
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			++i;
			value = echo_var_env(arg, &i);
		}
		else if (arg[i] == '\\' && is_active(command, "e")
				&& !is_active(command, "E"))
		{
			++i;
			if ((value = echo_char_special(arg, &i)))
				return (1);
		}
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
