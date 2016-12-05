/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:21:10 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/05 13:23:20 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "termcaps.h"

void	init_prompt(t_prompt *prompt)
{
	ft_bzero(prompt->line, ARG_MAX);
	prompt->num_line_history = 0;
	prompt->cursor_position = 0;
}
