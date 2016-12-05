/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ncolumns_term.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:58:28 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/05 17:59:18 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int		get_ncolumns_term(void)
{
	struct ttysize	term;

	ioctl(0, TIOCGWINSZ, &term);
	return (term.ts_cols);
}
