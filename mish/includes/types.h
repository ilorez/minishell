/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:18:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/28 12:27:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
#define FT_NAME "minishell> "

// tokens 
typedef enum	s_type{
	T_ROOT,
	T_LPAR,
	T_RPAR,
	T_AND,
	T_OR,
	T_PIPE,
  T_REDIR,
	T_EXEC,
	T_EOL
}	t_type;

typedef struct s_cmd {
  t_type type;
  void *left; //possible types: 1- exec (char **) 2- redir (t_redir *) 3-others (t_cmd *) 
  void *right; // -t_cmd *
} t_cmd;

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
