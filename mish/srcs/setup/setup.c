#include "../../includes/container.h"


t_data *ft_setup(char **envp)
{
	t_data *data;
	char	*path;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(1);
	path = getenv("PATH"); // this function is allowed  
	data->paths = ft_split(path, ':');

	// char **new_envp; => as default new_envp = envp, but it's changed in next cases:
	//    - add new var ==>this one I guess we have the export function !!
	//    - delete var ==> where we would need this one !?
	//    - update var ==> the exprot function should handle this one !

	//NOTE: if we want all the env variable the main fun passes it dirarclty  

	return data;
}
