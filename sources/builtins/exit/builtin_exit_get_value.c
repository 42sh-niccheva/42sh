int		builtin_exit_get_value(int argc, const char **argv, char **env)
{
	int		value;

	value = 0;
	if (argc == 2)
	{
		if (!ft_stris_int(argv[1]))
			return (-1);
		value = ((256 + ft_atoi(argv[1])) % 256);
	}
	return (value);
}