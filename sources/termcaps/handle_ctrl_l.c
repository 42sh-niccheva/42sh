/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ctrl_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:45:34 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/07 14:04:55 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		handle_ctrl_l(t_prompt *prompt)
{
	tputs(tgetstr("cl", NULL), 1, tputs_char);
	tputs(prompt->line, 1, tputs_char);
	return (1);
}
