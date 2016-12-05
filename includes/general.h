/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 10:46:03 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/05 11:35:35 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "libft.h"
# include "list.h"
# include "hashtable.h"

t_hashtable		*g_env;

void	sh_quit(int value);
int		fd_create_file(const char *pathname);
int		fd_append_file(const char *pathname);
int		fd_openread_file(const char *pathname);

#endif
