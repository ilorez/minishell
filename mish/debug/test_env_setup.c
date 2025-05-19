#include "./debug.h"
// Replace with actual header where t_data, t_arr, etc. are defined

int	main(int ac, char **av, char **envp)
{
	char **paths;
	char *home;
	int i;

  ft_setup_mish(ac, av, envp);
  ft_setenv("HMZA", "LHBIL", 1);
	printf("Testing ft_getenv:\n");
	home = ft_getenv("HMZA");
	if (home)
		printf("HMZA=%s\n", home);
	else
		printf("HMZA not found\n");
	printf("\nTesting ft_getpaths:\n");
	paths = ft_getpaths();
	if (paths)
	{
		for (i = 0; paths[i]; i++)
			printf("PATH[%d] = %s\n", i, paths[i]);
	}
	else
	{
		printf("No paths found\n");
	}
  ft_setenv("HMZA", "LHBIL 2", 1);

  ft_unsetenv("PATH");
  arr_print_str(mish.envp);
	// Free resources
	arr_free(mish.envp);  // if you have arr_free to clean up t_arr
	return (0);
}
