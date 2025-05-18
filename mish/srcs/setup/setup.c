#include "../../includes/container.h"
#include <linux/limits.h>
#include <unistd.h>


// TODO:
//  - ENVIR: [-] tested
//      - [x] ft_getenv
//      - [x] ft_setenv
//      - [x] ft_getpaths
//      - [x] ft_unsetenv
//
//  - free [ ] tested
//      - [x] ft_free_all (data, mish)
//
//  - buildins [ ] tested
//      - [x] finish cd echo env exit pwd unset
//      - [x] export buildin
//
//  - executor [ ] tested
//      - [ ] update mish.exit_status 
//      - [ ] link get_paths
//      - [ ] link $?
//      - [ ] link buildins 
//      - [ ] memory leeks
//      - [ ] norminette
//
//  - Signals [ ] tested
//      - [ ] signal kill (killpids)
//  - link
//      - [ ] link with parser
//      - [ ] test
//      - [ ] push

t_mish mish;

t_arr *_create_lenv(char **envp)
{
  int i;
  t_arr *lst_env;
  char cwd[PATH_MAX];


  if (!envp || !*envp)
    return (NULL);
  lst_env = arr_new();
  if (!lst_env)
    return (NULL);
  i = -1;
  while (envp[++i])
    arr_append(lst_env, ft_strdup(envp[i]));
  if (!getcwd(cwd, PATH_MAX))
  {
    perror("setup");
    return (arr_free(lst_env), NULL);
  }
  ft_setenv("PWD", cwd, 1);
  return (lst_env);
}

t_data *ft_setup(int ac, char **av, char **envp)
{
	t_data *data;
  t_arr *lenv;

  (void) ac, (void)av;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		  return (NULL);
  lenv = _create_lenv(envp);
  if (!lenv)
    return (free(data), NULL);
  mish.exit_status = 0;
  mish.envp = lenv;
  getcwd(mish.cwd, PATH_MAX);
	return data;
}
