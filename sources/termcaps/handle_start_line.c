/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_start_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:57:57 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/06 20:01:29 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		handle_start_line(t_prompt *prompt)
{
	tputs(tgetstr("cr", NULL), 1, tputs_char);
	prompt->cursor_position = 0;
	return (1);
}
