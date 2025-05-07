#include <stdio.h>
#include "./libft/includes/libft.h"

#define FT_DELIMITERS "$<>()|&"

static int _get_quote_value(t_str *word, char **cmd, char quote)
{

  str_append(word, *(*cmd)++);
  while (**cmd && **cmd != quote)
        str_append(word, *(*cmd)++);
  if (!*cmd)
    return (0);
  str_append(word, *(*cmd)++);
  return (1);
}

char *ft_get_quoted_word(char *cmd)
{
  t_str *word;
  int err;

  word = str_new_empty(5);
  // complex word:
  //  -never start with delim < > | & , otherwase syntax error
  //  -never end with open quotes, otherwise error
  // complex word complete after found <sapce> or <null_term> or <delimiter>
  err = 0;
  while (*cmd)
  {
    if (*cmd == '"')
    {
      if (!_get_quote_value(word, &cmd, '"'))
        err = 2;
      continue;
    }
    if (*cmd == '\'')
    {
      if (!_get_quote_value(word, &cmd, '\''))
        err = 1;
      continue;
    }
    // check if the current char is a delimiter or space
    if (ft_strchr(FT_DELIMITERS, *cmd) || ft_isspace(*cmd))
      break;
    // add current char to current word
    str_append(word, *cmd++);
  }
  if (err)
    printf("not closed quotes");
  return (str_extract(&word));
}

void ft_test_case(char *cmd)
{
  char *res = ft_get_quoted_word(cmd);
  if (res) {
        printf("Input: %-20s ➜ Extracted: \"%s\"\n", cmd, res);
        free(res); 
  } else { 
       printf("Input: %-20s ➜ Extracted: NULL\n", cmd);
  }
}

int main(void)
{
    printf("🔍 Testing ft_get_quoted_word:\n\n");

    ft_test_case("hello world");
    ft_test_case("\"quoted word\" rest");
    ft_test_case("'single quoted' word");
    ft_test_case("noquote123 rest");
    ft_test_case("hello>");
    ft_test_case("<infile");
    ft_test_case("hello|world");
    ft_test_case("\"unterminated quote");
    ft_test_case("normal_text | command");
    ft_test_case("(grouped) command");
    ft_test_case("  spaced_text");
    ft_test_case("''");
    ft_test_case("\"\"");
    ft_test_case("multi\"part\"text");

    return 0;
}
