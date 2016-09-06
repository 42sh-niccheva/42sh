/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:04:23 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/06 11:27:06 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_SETENV_H
# define BUILTIN_SETENV_H

# include "list.h"
# include "hashtable.h"
# include "general.h"

int		builtin_setenv(int argc, const char **argv, char **env);
int		builtin_setenv_add_key(t_hashtable *elem, const char *key);
int		builtin_setenv_add_value(t_hashtable *elem, const char *key);

#endif
