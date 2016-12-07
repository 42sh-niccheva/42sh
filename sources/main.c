#include "termcaps.h"
#include "general.h"
#include "history.h"
#include <limits.h>

#include <stdio.h>
int main(int ac, char **av, const char **env)
{
	char		buff[4];
	t_prompt	prompt;

	(void)ac;
	(void)av;
	init_history();
	add_history("ligne 1");
	add_history("ligne 2");
	add_history("ligne 3");
	add_history("ligne 4");
	add_history("ligne 5");
	add_history("  ligne 5           oruhg erug herhg e g    ergeg       ");
	g_env = hashtable_create_from_tab(env, "=");
	if (!termcaps_init())
		return (1);
	init_prompt(&prompt);
	while (42)
	{
		ft_bzero(buff, 4);
		read(0, buff, 3);
//		printf("%d\n", *(unsigned int *)buff);
		if (!handle_functions(*(unsigned int *)buff, &prompt))
			break ;
	}
	if (!termcaps_reset())
		return (1);
	delete_history();
	return (0);
}
