/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:06:33 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/02 15:08:26 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		termcaps_init(void)
{
	struct termios	term;
	t_hashtable		*elem;

	if ((elem = hashtable_search_key(g_env, "TERM")) == NULL)
		return (false);
	if (tgetent(NULL, elem->value) <= 0)
		return (false);
	if (tcgetattr(0, &term) == -1)
		return (false);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (false);
	return (true);
}
