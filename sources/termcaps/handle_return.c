/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:45:34 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/06 20:31:05 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		handle_return(t_prompt *prompt)
{
	tputs(tgetstr("do", NULL), 1, tputs_char);
	if (!ft_strequ(ft_strtrim(prompt->line), ""))
		add_history(prompt->line);
	ft_bzero(prompt->line, prompt->lenght);
	prompt->lenght = 0;
	prompt->num_line_history = 0;
	return (1);
}
