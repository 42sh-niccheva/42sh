/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:09:38 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/06 13:28:04 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtin_echo.h"

t_command		*builtin_echo_init(void)
{
	t_command	*command;

	command = new_command("echo", "display a line of text");
	add_option_to(command, new_option("n", "",
								"do not output the trailing newline"));
	add_option_to(command, new_option("e", "",
								"enable interpretation of backslash escapes"));
	add_option_to(command, new_option("E", "",
								"disable interpretation of backslash escapes "
								"(default)"));
	add_option_to(command, new_option("", "help",
								"display this help and exit"));
	return (command);
}
