/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:18:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/26 15:29:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
#define FT_PROMPT "minishell> "

// relations between commands
typedef enum s_rel {
  END,
  PIPE,
  OR,
  AND
} t_rel;

typedef struct s_cmd {
  t_rel type;
  void *left;
  void *right;
} t_cmd;

typedef struct s_exec 
{
  char **argv;
  char **env;

} t_exec;

// env
typedef struct s_env {
  char *key;
  char *value;
} t_env;


typedef struct s_prompt {
  char *prompt;
  char *path;
} t_prompt;

typedef struct s_redir {
  char *fpath;
  int fd; // 0 for < and 1 for >
  int mode; 
  t_cmd *cmd; // another struct of commands that the rediriction happen on it
} t_redir;

// data container 
// Note: this is what will be passsed to execute function
typedef struct s_data {
  t_prompt prompt;
  t_env **vars;
  t_redir **fd_list; // those at begining and end of command with it's order
} t_data;

#endif
