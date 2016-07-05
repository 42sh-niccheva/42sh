/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 14:02:31 by niccheva          #+#    #+#             */
/*   Updated: 2016/07/01 16:49:08 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_builtins.h"

void		init(void)
{

}

int			main(void)
{
	init();
	cd_test();
	echo_test();
	env_test();
	exit_test();
	setenv_test();
	unsetenv_test();
	return (0);
}
