/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtins.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 15:06:51 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/08 16:08:34 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BUILTINS_H
# define TEST_BUILTINS_H

# include "libft.h"
# include "hashtable.h"
# include "general.h"
# include <stdio.h>

# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"

void		header_test(const char *test);

void		cd_test(void);
void		echo_test(void);
void		env_test(void);
void		exit_test(void);
void		setenv_test(char **env);
void		unsetenv_test(char **env);

#endif
