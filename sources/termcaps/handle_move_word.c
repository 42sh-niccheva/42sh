/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:05:09 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/07 09:27:19 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		handle_ctrl_b(t_prompt *prompt)
{
	if (!ft_isspace(prompt->line[prompt->cursor_position]))
		handle_arrow_left(prompt);
	while (prompt->cursor_position > 0
			&& ft_isspace(prompt->line[prompt->cursor_position]))
		handle_arrow_left(prompt);
	while (prompt->cursor_position > 0
			&& !ft_isspace(prompt->line[prompt->cursor_position]))
		handle_arrow_left(prompt);
	if (prompt->cursor_position != 0 ||
		(prompt->cursor_position == 0 && ft_isspace(prompt->line[0])))
		handle_arrow_right(prompt);
	return (1);
}

int		handle_ctrl_n(t_prompt *prompt)
{
	if (!ft_isspace(prompt->line[prompt->cursor_position]))
		handle_arrow_right(prompt);
	while (prompt->cursor_position > 0
			&& !ft_isspace(prompt->line[prompt->cursor_position]))
		handle_arrow_right(prompt);
	while (prompt->cursor_position > 0
			&& ft_isspace(prompt->line[prompt->cursor_position]))
		handle_arrow_right(prompt);
	return (1);
}
