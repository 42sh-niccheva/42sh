/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_add_entry_to.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:56:04 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/07 14:05:16 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static void		shift_end_from(char *line, int position)
{
	int		cursor;

	cursor = ft_strlen(line);
	while (cursor > position)
	{
		line[cursor] = line[cursor - 1];
		--cursor;
	}
}

/*void			back_cursor_to_position(int time)
{
	int i;

	i = 0;
	while (i < time)
	{
		tputs(tgetstr("le", NULL), 1, tputs_char);
		++i;
	}
	}*/

static void		increase_prompt(t_prompt *prompt)
{
	char	*save;

	prompt->size_total += SIZE_LINE;
	save = ft_strnew(prompt->size_total);
	ft_bzero(save, prompt->size_total);
	ft_memcpy(save, prompt->line, prompt->lenght);
}

void			handle_add_entry_to(unsigned int entry, t_prompt *prompt)
{
	char	*line;
	int		position;

	if (!ft_isprint(entry))
		return ;
	if ((prompt->lenght + 1) >= prompt->size_total)
		increase_prompt(prompt);
	line = prompt->line;
	position = prompt->cursor_position;
	shift_end_from(line, position);
	line[position] = entry;
	++(prompt->lenght);
	++(prompt->cursor_position);
	tputs(tgetstr("sc", NULL), 1, tputs_char);
	tputs(&line[position], 1, tputs_char);
	tputs(tgetstr("rc", NULL), 1, tputs_char);
	tputs(tgetstr("nd", NULL), 1, tputs_char);
//	back_cursor_to_position(ft_strlen(line) - position);
}
