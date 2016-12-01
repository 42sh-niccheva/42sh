/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:00:19 by niccheva          #+#    #+#             */
/*   Updated: 2016/12/01 12:53:59 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_CD_H
# define BUILTIN_CD_H

# include "liboption.h"

int				builtin_cd(int argc, const char **argv, const char **env);
t_command		*builtin_cd_init(void);
int				builtin_cd_symlink(const char *target);
bool			builtin_cd_is_symlink(const char *target);
char			*builtin_cd_clean_path(const char *path, const char *target);

#endif
