/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 14:19:46 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/15 14:23:03 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_cd.h"

t_command		*builtin_cd_init(void)
{
	t_command	*command;

	command = new_command("cd", "change the working directory");
	add_option_to(command, new_option("L", "",
								"force symbolic links to be followed"));
	add_option_to(command, new_option("P", "",
								"use the physical directory structure without "
"following symbolic links"));
	return (command);
}
