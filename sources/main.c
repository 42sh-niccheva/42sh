#include "general.h"
#include "builtins/builtin_cd.h"

int main(int argc, char **argv, const  char **env) {
	int			ac;
	char		**av;
	t_hashtable	*entry;
	char		*first_pwd;

	(void)argc;
	(void)argv;
	(void)ac;
	(void)av;
	first_pwd = getcwd(NULL, 0);
	g_env = hashtable_create_from_tab(env, "=");
	av = (char **)malloc(sizeof(char *) * 4);
	av[0] = ft_strdup("cd");
	av[1] = ft_strdup("test");
	av[2] = ft_strdup("");
	av[3] = 0;
	entry = hashtable_search_key(g_env, "PWD");
	if (entry != NULL)
		ft_putendl(entry->value);

	ft_putendl("\nTest without arg:");
	ac = 2;
	builtin_cd(ac, (const char **)av, env);
	entry = hashtable_search_key(g_env, "PWD");
	if (entry != NULL)
		ft_putendl(entry->value);

	chdir(first_pwd);

	ft_putendl("\nTest with -P:");
	av[1] = ft_strdup("-P");
	av[2] = ft_strdup("test");
	ac = 3;
	builtin_cd(ac, (const char **)av, env);
	entry = hashtable_search_key(g_env, "PWD");
	if (entry != NULL)
		ft_putendl(entry->value);

	chdir(first_pwd);

	ft_putendl("\nTest with -L:");
	av[1] = ft_strdup("-L");
	av[2] = ft_strdup(".././././42sh/././././test/////////");
	ac = 3;
	builtin_cd(ac, (const char **)av, env);
	entry = hashtable_search_key(g_env, "PWD");
	if (entry != NULL)
		ft_putendl(entry->value);

	ft_putendl("\nTest with unknown dir:");
	av[1] = ft_strdup("tutu");
	ac = 3;
	builtin_cd(ac, (const char **)av, env);

	return (0);
}
