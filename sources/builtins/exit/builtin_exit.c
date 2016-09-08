/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:10:17 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/08 13:18:26 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_exit.h"
#include <stdlib.h>

int		builtin_exit(int argc, const char **argv, char **env)
{
	int		value;

	(void)env;
	value = 0;
	if (argc > 2)
		value = -1;
	else if (argc == 2)
	{
		if (argv[1][0] != '-' && !ft_strapply_predicate(argv[1], &ft_isdigit))
			value = -1;
		else if (argv[1][0] == '-'
				&& !ft_strapply_predicate(argv[1] + 1, &ft_isdigit))
			value = -1;
		else
			value = ((256 + ft_atoi(argv[1])) % 256);
	}
	if (value < 0)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": Expression Syntax.", 2);
		value = 1;
	}
	else
		sh_quit(value);
	return (value);
}
