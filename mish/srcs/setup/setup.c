#include "../../includes/container.h"


t_data *ft_setup(char **envp)
{
  t_data *data;
  data = ft_calloc(sizeof(t_data));
  if (!data)
    exit(1);
  // here we should create
  // cahr **paths; => whitch is a array of paths from envp->PATH
  // char **new_envp; => as default new_envp = envp, but it's changed in next cases:
  //    - add new var
  //    - delete var
  //    - update var

  // todo functions:
  //      - ft_get_var(char *key): return null or a string
  //      - ... 
  return data;
}
