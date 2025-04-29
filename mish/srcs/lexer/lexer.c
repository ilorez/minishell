#include "../../includes/container.h"
#include "../../libft/includes/t_str.h"

/*
typedef	struct	s_tokens{
	t_type	type;
	void	*value;
  struct s_tokens *next;
}	t_tokens;
*/
t_type	ft_set_token(char *ptr, void *value);
char **ft_get_exec(char *cmd);
t_redir *ft_get_redir(char *cmd);
char *ft_get_cmplx_word(char *cmd);

t_tokens *ft_get_tokens(char *cmd)
{
  t_tokens *tk;

  tk = NULL;
  while (*cmd)
  {
    // skip spaces
    while (ft_isspace(*cmd))
      cmd++;
    if (!*cmd)
      break;
    tk = ft_calloc(sizeof(t_tokens), 1);
    tk->type = ft_set_token(cmd, tk->value);
    tk = tk->next;
  }
  return tk;
}

t_type	ft_set_token(char *ptr, void *value)
{
  if (ptr[0] == '|' && *(++ptr) == '|' && ptr++)
		return T_OR;
	if (ptr[0] == '&' && *(++ptr) == '&' && ptr++)
		return T_AND;
	if (ptr[0] == '|' && ptr++)
		return T_PIPE;
	if (ptr[0] == '(' && ptr++)
		return T_LPAR;
	if (ptr[0] == ')' && ptr++)
		return T_RPAR;
  if (*ptr == '<' || *ptr == '>')
  {
    value = (void *)ft_get_redir(ptr);
    return T_REDIR;
  }
  value = (void *)ft_get_exec(ptr);
	return T_EXEC;
}

char **ft_get_exec(char *cmd)
{
  char **arr = ft_calloc(sizeof(char *), 100); // for example: //TODO:t_arr
  int i = 0;
  while (1)
  {
    arr[i] = ft_get_cmplx_word(cmd);
    // check if next char 
    if (!arr[i++])
      break;
  }
  return arr;
}

t_redir *ft_get_redir(char *cmd)
{
  t_redir *rd;

  rd = ft_calloc(sizeof(t_redir), 1);
  if (!rd)
    return (NULL);
  else if (*cmd =='<')
  {
    // rd->fd = 0; // it's 0 by default because we use ft_calloc
    rd->mode = O_RDONLY;
    if (*(++cmd) == '<' && ++cmd)
    {
      // rd->fpath = ft_heredoc(ft_get_cmplx_word(cmd)), 
    }
    // rd->fpath = ft_get_cmplx_word(cmd);
  }
  else
  {
    rd->fd = 1;
    rd->mode = O_RDONLY | O_WRONLY;
    if (*(++cmd) == '>' && cmd++)
        rd->mode |= O_APPEND;
    // rd->fpath = ft_get_cmplx_word(cmd);
  }
  return rd;
}

char *ft_get_cmplx_word(char *cmd)
{
  int open;
  t_str *word;

  word = str_new_empty(5);
  // complex word:
  //  -never start with delim < > | & , otherwase syntax error
  //  -never end with open quotes, otherwise error
  // complex word complete after found <sapce> or <null_term> or <delimiter>
  open = 0;
  while (*cmd)
  {
    if (!open && *cmd == '"')
      // get_quotes_value(word, ++cmd++, 2)
    if (!open && *cmd == '\'')
      // get_quotes_value(word, ++cmd++, 1)// test if ++i++ works
    if (ft_strchr(FT_DELIMITERS, *cmd) || ft_isspace(*cmd))
      break;
    // add current char to current word
    if(str_append(word, *cmd))
      return (str_clean(&word), NULL);
    // here the delimiters ( ) not acceptable
    cmd++;
  }
  if (*cmd == '\(' || *cmd == '\)')
          // show syntax error
  return word;
}


// get_quotes_value
//  for 2:
//    - if it found $ only should accept it as char
