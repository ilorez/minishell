/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:18:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/27 17:06:59 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
#define FT_NAME "minishell> "

// tokens 
typedef enum	e_type{
	ROOT,
	LPAR,
	RPAR,
	AND,
	OR,
	PIPE,
  REDIR,
	WORD,
	EOL
}	t_type;

typedef struct s_hdoc {
  char *eof;
} t_hdoc;

typedef struct s_cmd {
  t_type type;
  void *left;
  void *right;
} t_cmd;

typedef struct s_exec 
{
  char **argv;
} t_exec;

typedef struct s_redir {
  char *fpath;
  int fd; // 0 for < and 1 for >
  int mode; 
  t_cmd *cmd; // another struct of commands that the rediriction happen on it
} t_redir;

typedef	struct	s_tokens{
	t_type	type;
	void	*value;
  struct s_tokens *next;
}	t_tokens;

//t_tokens **tokens;

// data container 
// Note: this is what will be passsed to execute function
typedef struct s_data {
  char *curr_dir;
  char *paths;
  t_cmd *ast;
  bool is_bg;
} t_data;

#endif
