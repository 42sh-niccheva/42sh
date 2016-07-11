/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv_add_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:55:52 by llapillo          #+#    #+#             */
/*   Updated: 2016/07/11 17:04:51 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashtable.h"

int		builtin_setenv_add_value(t_hashtable *elem, const char *value)
{
	int		response;

	response = 0;
	if (ft_strapply_predicate(value, &ft_isalnum))
	{
		elem->value = ft_strdup(value);
	}
	else
	{
		response = -1;
	}
	return (response);
}
