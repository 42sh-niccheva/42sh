/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:01:44 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/10 10:02:26 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ECHO_H
# define BUILTIN_ECHO_H

# include "liboption.h"

int				builtin_echo(int argc, const char **argv, char **env);
t_command		*builtin_echo_init(void);

#endif
