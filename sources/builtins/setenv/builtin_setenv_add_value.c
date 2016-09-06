/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv_add_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:55:52 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/06 14:03:23 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashtable.h"

int		builtin_setenv_add_value(t_hashtable *elem, const char *value)
{
	elem->value = ft_strdup(value);
	return (0);
}
