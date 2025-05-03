#include "../../includes/container.h"
#include "../../libft/includes/t_str.h"

static void _get_quote_value(t_str *word, char *cmd, char quote)
{
  while (*cmd && *cmd != '"')
        str_append(word, *cmd++);
}

char *ft_get_quoted_word(char *cmd)
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
    {
      _get_quote_value(word, cmd, '"');
      continue;
    }
    if (!open && *cmd == '\'')
    {
      while (*cmd && *cmd != '\'')
        str_append(word, *cmd++);
      continue;
    }
    // check if the current char is a delimiter or space
    if (ft_strchr(FT_DELIMITERS, *cmd) || ft_isspace(*cmd))
      break;
    // add current char to current word
    if(!str_append(word, *cmd))
      return (str_clean(&word), NULL);
    cmd++;
  }
  return str_extract(&word);
}
