/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:55:06 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/16 18:10:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./read_test.h"

// fd
typedef struct s_fd {
  enum {
    IN,
    OUT,
    OUTAPPEND
  } type;
  char *text; // path | EOF
} t_fd;

// simple command
typedef struct s_simple_cmd {
	t_string *cmd;
	char **args;
  t_fd **fd_list; // those at begining and end of command with it's order
} t_simple_cmd;

// tag for quotes
typedef enum s_tag{
  NONE,
  DOUBLE_Q,
  SINGLE_Q
} t_tag;

// is space
int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

// is delmiter " ' | || && > <
int ft_isdelimiter(char c)
{
  if (c == '\'' || c == '"')
    return 1;
  return 0;
}

// get simple cmd
// example: ls hello
t_simple_cmd *get_simple_cmd(char *txt)
{
  t_tag tag;
  t_simple_cmd *full_cmd;
  t_string *args;
  t_string *curr;

  full_cmd = ft_calloc(sizeof(t_simple_cmd), 1);
  full_cmd->cmd = ft_create_empty_str(1);
  if (!full_cmd->cmd)
    return NULL;
  args = ft_create_empty_str(1);
  if (!args)
    return NULL;


  curr = full_cmd->cmd;
  tag = NONE;
  while (*txt)
  {
    while (!tag && curr != args && ft_isspace(*txt))
      txt++;

    while (tag)
    {
      if ((*txt == '\'' && tag == SINGLE_Q) || (*txt == '"' && tag == DOUBLE_Q))
        tag = NONE;
      else
        ft_string_append(curr, *txt);
      txt++;
    }

    while (*txt && !ft_isdelimiter(*txt))
    {
        if (ft_isspace(*txt) && curr != args)
        {
          curr = args;
          txt++;
          continue;
        }
        ft_string_append(curr, *txt);
        txt++;
    }

    if (*txt == '\'')
      tag = SINGLE_Q;
    else if (*txt == '"')
      tag = DOUBLE_Q;
    if (*txt)
      txt++;
  }
  // split it later
  full_cmd->args = ft_split(args->value, ' ');
  return  full_cmd;
}

void print_simple_cmd(t_simple_cmd *cmd)
{
  if (!cmd)
    printf("Error: cmd Empty");
  printf("cmd: %s\n", cmd->cmd->value);
  int i = -1;
  printf("args:[");
  while (cmd->args[++i])
    printf(" %s,", cmd->args[i]);
  printf("]\n");
}

int main()
{
  char *input;
  //rl_clear_history();
  while (1)
  {
    input = readline("command>");
    if (!input) break;
    if (*input)
    {
      add_history(input);
      print_simple_cmd(get_simple_cmd(input));
    }
  }
  return (0);
}

