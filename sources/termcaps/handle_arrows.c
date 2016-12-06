/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arrows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:26:16 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/06 19:04:36 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		handle_arrow_left(t_prompt *prompt)
{
	if (prompt->cursor_position > 0)
	{
		--(prompt->cursor_position);
		tputs(tgetstr("le", NULL), 1, tputs_char);
	}
	return (1);
}

int		handle_arrow_right(t_prompt *prompt)
{
	if (prompt->cursor_position < (int)ft_strlen(prompt->line))
	{
		++(prompt->cursor_position);
		if ((prompt->cursor_position + 1) % get_ncolumns_term() == 0)
			tputs(tgetstr("do", NULL), 1, tputs_char);
		else
			tputs(tgetstr("nd", NULL), 1, tputs_char);
	}
	return (1);
}

char	*get_entry_history_at(t_prompt *prompt, int i)
{
	char	*history;

	history = get_history_line_from(i);
	if (history != NULL)
	{
		ft_bzero(prompt->line, prompt->size_total);
		ft_memcpy(prompt->line, history, ft_strlen(history));
	}
	return (history);
}

int		handle_arrow_up(t_prompt *prompt)
{
	char	*history;

/*	if (prompt->num_line_history == 0)
	{
		++(prompt->num_line_history);
		add_history(prompt->line);
		}*/
	history = get_entry_history_at(prompt, prompt->num_line_history + 1);
	if (history != NULL)
	{
		++(prompt->num_line_history);
		tputs(tgetstr("dl", NULL), 1, tputs_char);
		tputs(tgetstr("cr", NULL), 1, tputs_char);
		tputs(prompt->line, 1, tputs_char);
		tputs(tgetstr("cr", NULL), 1, tputs_char);
		prompt->cursor_position = 0;
		ft_strdel(&history);
	}
	return (1);
}

int		handle_arrow_down(t_prompt *prompt)
{
	char	*history;

	history = get_entry_history_at(prompt, prompt->num_line_history - 1);
	if (history != NULL)
	{
		--(prompt->num_line_history);
		tputs(tgetstr("dl", NULL), 1, tputs_char);
		tputs(tgetstr("cr", NULL), 1, tputs_char);
		tputs(prompt->line, 1, tputs_char);
		tputs(tgetstr("cr", NULL), 1, tputs_char);
		prompt->cursor_position = 0;
		ft_strdel(&history);
	}
	return (1);
}
