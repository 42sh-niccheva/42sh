/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:21:10 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/06 19:06:00 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "termcaps.h"

void	init_prompt(t_prompt *prompt)
{
	prompt->line = ft_strnew(SIZE_LINE);
	ft_bzero(prompt->line, SIZE_LINE);
	prompt->lenght = 0;
	prompt->size_total = SIZE_LINE;
	prompt->num_line_history = 1;
	prompt->cursor_position = 0;
}
