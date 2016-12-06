/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:29:08 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/06 20:07:45 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

#include <stdio.h>
static int		handle_functions1(unsigned int entry, t_prompt *prompt)
{
	int					i;
	static t_functions	functions[] = {
		{LEFT, &handle_arrow_left},
		{CTRL_B, &handle_arrow_left},
		{RIGHT, &handle_arrow_right},
		{UP, &handle_arrow_up},
		{DOWN, &handle_arrow_down},
		{CTRL_D, &handle_ctrl_d},
		{RETURN, &handle_return},
		{HOME, &handle_start_line},
		{CTRL_A, &handle_start_line},
		{END, &handle_end_line},
		{CTRL_E, &handle_end_line},
		{0, NULL}
	};

	i = 0;
	while (functions[i].function != NULL)
	{
		if (functions[i].value == entry)
			return (functions[i].function(prompt));
		++i;
	}
	return (-1);
}

int				handle_functions(unsigned int entry, t_prompt *prompt)
{
	int		value;

	value = 0;
	if ((value = handle_functions1(entry, prompt)) >= 0)
		return (value);
	handle_add_entry_to(entry, prompt);
	return (1);
}
