/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_builtin_setenv.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:04:23 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 13:59:38 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_BUILTIN_SETENV_H
# define PRIVATE_BUILTIN_SETENV_H

# include "builtin_setenv.h"

int		builtin_setenv_add_key(t_hashtable *elem, const char *key);
int		builtin_setenv_add_value(t_hashtable *elem, const char *key);

#endif
