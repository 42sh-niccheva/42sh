/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:42:54 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/01 16:46:28 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_env.h"

t_command	*builtin_env_init(void)
{
	t_command	*command;

	command = new_command("env", "set environment and execute command, "
						"or print environment");
	add_option_to(command, new_option("i", "",
				"Execute the utility with only those environment variables "
				"specified by name=value options."));
	return (command);
}
