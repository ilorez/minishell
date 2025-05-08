/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 04:59:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/08 10:37:00 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

// ==================================
// macors
// ==================================

# define FT_NAME "minishell> "
# define FT_DELIMS "<>()|&"

// ==================================
// includes
// ==================================

# include <stdlib.h>

// ==================================
// types
// ==================================

// tokens
typedef enum s_type
{
	T_ROOT, // token
	T_LPAR, // token
	T_RPAR, // token
	T_AND,
	T_OR,
	T_PIPE,
	T_LESS, // token
	T_LLESS, // token
	T_GREAT, // token
	T_GGREAT, // token
	T_WORD, // token
  T_REDIR,// ast
  T_EXEC, // ast
  T_SUBSH, // ast
	T_EOL,
	T_UNKNOW
}					t_type;

typedef struct s_ast
{
	t_type			type;
	void			*value;
	struct s_ast	*left;
	// possible types: 1- exec (char *) 2- redir (t_redir *) 3-others (t_cmd *)
	struct s_ast *right; // -t_ast *
}					t_ast;

typedef struct s_word
{
	char			*ptr;
	size_t			len;
}					t_word;

typedef struct s_redir
{
	char			*fpath;
	int fd; // 0 for < and 1 for >
	int				mode;
}					t_redir;

typedef struct s_token
{
	t_type			type;
	t_word			*word;
	struct s_token	*next;
}					t_token;

// t_tokens **tokens;

// data container
// Note: this is what will be passsed to execute function
typedef struct s_data
{
	char			*curr_dir;
	char **paths; // double pointer array of paths
	char **envp;
	t_ast			*ast;
  int fd[2]; // in deault: fd = [STDIN, STDOUT]
}					t_data;

#endif
