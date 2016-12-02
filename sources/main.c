#include "termcaps.h"
#include "general.h"

int main(int ac, char **av, const char **env)
{
	char	buff[3];

	(void)ac;
	(void)av;
	g_env = hashtable_create_from_tab(env, "=");
	if (!termcaps_init())
		return (1);
	while (42)
	{
		read(0, buff, 3);
		if (!handle_functions(buff))
			break ;
	}
	if (!termcaps_reset())
		return (1);
	return (0);
}
