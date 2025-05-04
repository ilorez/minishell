/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:18:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/04 09:52:05 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

// ==================================
// macors
// ==================================

#define FT_NAME "minishell> "
#define FT_DELIMITERS "$<>()|&"

// ==================================
// includes
// ==================================

#include <stdbool.h>

// ==================================
// types
// ==================================

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

typedef struct s_ast {
  t_type type;
  void *value;
  struct s_ast *left; //possible types: 1- exec (char *) 2- redir (t_redir *) 3-others (t_cmd *) 
  struct s_ast *right; // -t_ast *
} t_ast;

typedef struct s_redir {
  char *fpath;
  int fd; // 0 for < and 1 for >
  int mode; 
  t_ast *cmd; // another struct of commands that the rediriction happen on it
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
  char **paths; // double pointer array of paths 
  t_ast *ast;
  bool is_bg;
} t_data;

#endif
