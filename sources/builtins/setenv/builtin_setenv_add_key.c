/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv_add_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:55:52 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/11 17:02:12 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashtable.h"

int		builtin_setenv_add_key(t_hashtable *elem, const char *key)
{
	int		value;

	value = 0;
	if (ft_strapply_predicate(key, &ft_isalnum))
	{
		elem->key = ft_strdup(key);
	}
	else
	{
		value = -1;
	}
	return (value);
}
