#include "general.h"
#include "builtins/builtin_env.h"

int main(int argc, char **argv, char **env)
{
	int		ac;
	char	**av;

	g_env = hashtable_create_from_tab((const char **)env, "=");
	(void)argc;
	(void)argv;
	av = (char **)malloc(sizeof(char *) * 5);

	ft_putendl("env");
	av[0] = ft_strdup("env");
	av[1] = 0;
	av[2] = 0;
	av[3] = 0;
	av[4] = 0;
	ac = 1;
	builtin_env(ac, (const char **)av, env);

	ft_putendl("\n\nenv tutu=test toto=pouet");
	av[0] = ft_strdup("env");
	av[1] = ft_strdup("tutu=test");
	av[2] = ft_strdup("toto=pouet");
	av[3] = 0;
	av[4] = 0;
	ac = 3;
	builtin_env(ac, (const char **)av, env);

	ft_putendl("\n\nenv -i tutu=test toto=pouet");
	av[0] = ft_strdup("env");
	av[1] = ft_strdup("-i");
	av[2] = ft_strdup("tutu=test");
	av[3] = ft_strdup("toto=pouet");
	av[4] = 0;
	ac = 4;
	builtin_env(ac, (const char **)av, env);
	return(0);
}
