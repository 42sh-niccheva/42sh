/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:10:17 by niccheva          #+#    #+#             */
/*   Updated: 2016/09/08 10:19:00 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include <unistd.h>

void	sh_quit(int value)
{
	hashtable_delete(g_env);
	_exit(value);
}
