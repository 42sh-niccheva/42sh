/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:29:08 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/05 17:45:25 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

#include <stdio.h>
int		handle_functions(unsigned int entry, t_prompt *prompt)
{
	int					i;
	static t_functions	functions[] = {
		{LEFT, &handle_arrow_left},
		{RIGHT, &handle_arrow_right},
		{UP, &handle_arrow_up},
		{DOWN, &handle_arrow_down},
		{CTRL_D, &handle_ctrl_d},
		{0, NULL}
	};

	i = 0;
	while (functions[i].function != NULL)
	{
		if (functions[i].value == entry)
			return (functions[i].function(prompt));
		++i;
	}
	handle_add_entry_to(entry, prompt);
	return (1);
}
