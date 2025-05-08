

#include "../../includes/container.h"

void ft_add_var_value(t_str *str, char *cmd);
int ft_add_squote_value(t_str *str, char *cmd)
{
  while (*cmd && *cmd != '\'')
    str_append(str, *cmd);
  return (*cmd);
}

int ft_add_dquote_value(t_str *str, char *cmd)
{
  while (*cmd && *cmd != '\"')
  {
    if (*cmd == '$')
      ft_add_var_value(str, cmd);
    
      


    str_append(str, *cmd);
  }
  return (*cmd);
}

// notes
// - because the subject doesn't require to handle $# $@ $! ... $<symbol>
// - expet for $?
// - and because the symbols use for specifique regions in bash
// - and the user can create a variable conatin symbols
// - so in our minishell we will just print them
void ft_add_var_value(t_str *str, char *cmd)
{
  t_str *name;

  if (*cmd == '?')
  {
    str_append_list(str, ft_get_exit_status());
    cmd++;
    return ;
  }
  name = str_new_empty(4);
  if (!name)
    return ;
  while (ft_isalnum(*cmd) || *cmd == '_') // [A-Za-z9-0] and <underscore>
    str_append(name, *cmd++);
  if (name->value[0])
    str_append_list(str, ft_get_var(name->value));
  else
    str_append(str, '$');
  str_clean(&name);
}

