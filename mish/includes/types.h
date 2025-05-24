/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 04:59:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/17 18:50:13 by znajdaou         ###   ########.fr       */
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

# include "../libft/includes/libft.h"
# include <stdlib.h>

// ==================================
// types
// ==================================

typedef enum s_type
{
	T_ROOT, 
	T_LPAR, 
	T_RPAR, 
	T_AND,
	T_OR,
	T_PIPE,
	T_LESS,   
	T_LLESS,  
	T_GREAT,  
	T_GGREAT, 
	T_WORD,   
	T_REDIR,  
	T_EXEC,   
	T_SUBSH,  
	T_EOL,
	T_UNKNOWN
}					t_type;

typedef struct s_redir
{
	char			*fpath;
	int fd; // 0 for < and 1 for >
	int				flags;
	int				mode;
}					t_redir;

typedef struct s_word
{
	char			*ptr;
	size_t			len;
}					t_word;

typedef struct s_token
{
	t_type			type;
	t_word			*word;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

// data container for the exucution part
typedef struct s_ast
{
	t_type			type;
	union
	{
		char		**argv;
		t_redir		*redir;
	};
	struct s_ast	*left;
	// possible types: 1- exec (char *) 2- redir (t_redir *) 3-others (t_cmd *)
	struct s_ast *right; // -t_ast *
}					t_ast;

// data container
// Note: this is what will be passsed to execute function
typedef struct s_data
{
	char **paths; // double pointer array of paths
	t_ast			*ast;
	int fd[2];    // used by executor: in deault: fd = [STDIN, STDOUT]
	t_arr *wpids; // used by executor: arr_new();
}					t_data;

typedef struct s_mish
{
	char			**envp;
  int exit_status;
} t_mish;

#endif
