/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_end_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:57:57 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/06 20:16:32 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		handle_end_line(t_prompt *prompt)
{
	while (prompt->line[prompt->cursor_position])
	{
		tputs(tgetstr("nd", NULL), 1, tputs_char);
		++(prompt->cursor_position);
	}
	return (1);
}
