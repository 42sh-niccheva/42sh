/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapillo <llapillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:56:38 by llapillo          #+#    #+#             */
/*   Updated: 2016/12/06 19:22:16 by llapillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "general.h"
# include "history.h"
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <term.h>
# include <limits.h>

# define SIZE_LINE 4096
# define ESCAPE 27
# define UP 4283163
# define DOWN 4348699
# define LEFT 4479771
# define RIGHT 4414235
# define SPACE 32
# define RETURN 10
# define BACKSPACE 127
# define DELETE 126
# define END 4610843
# define HOME 4741915
# define CTRL_A 1
# define CTRL_B 2
# define CTRL_D 4
# define CTRL_E 5
# define CTRL_L 12
# define CTRL_N 14

typedef struct s_prompt		t_prompt;
typedef struct s_functions	t_functions;

/*
** lenght: Size of user's entry
** size_total: Size buffer
** cursor_position: position of the cursor in the buffer
*/

struct		s_prompt
{
	char	*line;
	char	*save;
	int		lenght;
	int		size_total;
	int		num_line_history;
	int		cursor_position;
};

struct		s_functions
{
	unsigned int	value;
	int				(*function)(t_prompt *);
};

int			termcaps_reset(void);
int			termcaps_init(void);
void		init_prompt(t_prompt *prompt);
int			get_ncolumns_term(void);
int			handle_functions(unsigned int key, t_prompt *prompt);
int			handle_ctrl_d(t_prompt *prompt);
void		handle_add_entry_to(unsigned int entry, t_prompt *prompt);
int			handle_arrow_left(t_prompt *prompt);
int			handle_arrow_right(t_prompt *prompt);
int			handle_arrow_up(t_prompt *prompt);
int			handle_arrow_down(t_prompt *prompt);
int			tputs_char(int c);

#endif
