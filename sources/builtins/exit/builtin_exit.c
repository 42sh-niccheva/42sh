/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:10:17 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/10 10:20:49 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_exit.h"
#include <stdlib.h>

int		builtin_exit(int argc, const char **argv, char **env)
{
	int		value;

	if (argc < 3)
	{
		value = get_value(argc, argv, env);
		if (value >= 0)
			quit("exit", value);
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else
		ft_putendl_fd("exit: too many arguments.", 2);
	return (-1);
}
