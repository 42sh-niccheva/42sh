/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:56:38 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/02 15:32:20 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "general.h"
# include <termios.h>
# include <unistd.h>
# include <term.h>

# define ESCAPE 27
# define UP 4283163
# define DOWN 4348699
# define LEFT 4479771
# define RIGHT 4414235
# define SPACE 32
# define RETURN 10
# define BACKSPACE 127
# define DELETE 2117294875
# define END 4610843
# define START 4741915
# define CTRL_A 1
# define CTRL_B 2
# define CTRL_D 4
# define CTRL_E 5
# define CTRL_L 12
# define CTRL_N 14

int		termcaps_reset(void);
int		termcaps_init(void);
int		handle_functions(char *buff);

#endif
