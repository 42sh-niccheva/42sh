/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:10:17 by niccheva          #+#    #+#             */
/*   Updated: 2016/07/11 17:18:03 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_exit.h"

int		builtin_exit(int argc, const char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	return 0;
}
