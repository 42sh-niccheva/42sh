/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 10:46:03 by llapillo          #+#    #+#             */
/*   Updated: 2016/09/06 11:21:28 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "hashtable.h"
# include "builtins/builtin_cd.h"
# include "builtins/builtin_echo.h"
# include "builtins/builtin_env.h"
# include "builtins/builtin_exit.h"
# include "builtins/builtin_setenv.h"
# include "builtins/builtin_unsetenv.h"

t_hashtable		*g_env;

#endif
