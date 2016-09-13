/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:09:38 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/13 15:28:44 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_echo.h"
#include "hashtable.h"
#include "general.h"

static void		echo_char_octal(const char *num, char *result, int pow, int len)
{
	int		p;
	int		i;

	p = 1;
	i = pow;
	if (len < 0)
		return ;
	while (i > 0)
	{
		p *= 8;
		--i;
	}
	*result += ((num[len] - 48) * p);
	echo_char_octal(num, result, ++pow, --len);
}

static int		echo_char_num(const char *arg, int *i)
{
	char	*num;
	int		start;
	char	result;
	int		j;

	j = 0;
	start = ++(*i);
	result = 0;
	while (arg[*i] && ft_isdigit(arg[*i]) && (*i - start) < 3)
		++(*i);
	num = ft_strnew(*i - start);
	num = ft_strncpy(num, &arg[start], (*i - start));
	echo_char_octal(num, &result, 0, ft_strlen(num) - 1);
	ft_putchar(result);
	ft_strdel(&num);
	--(*i);
	return (0);
}

static int		echo_char_special(const char *arg, int *i)
{
	int					j;
	static const char	chars[] = "abfnrtv";
	static const char	chars_spec[] = "\a\b\f\n\r\t\v";

	if (arg[*i] == 'c')
		return (1);
	else if (arg[*i] == '0')
		return (echo_char_num(arg, i));
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
		if (arg[i] == '\\' && is_active(command, "e")
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
