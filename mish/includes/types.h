/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 04:59:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/05/31 11:36:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
// ==================================
// macors
// ==================================

# include <linux/limits.h>
# define FT_NAME "mish"
# define FT_DELIMS "<>()|&"

// ==================================
// includes
// ==================================

# include "libft.h"
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

// fd: 0 for < and 1 for >
typedef struct s_redir
{
	char			*fpath;
	int				fd;
	int				flags;
	int				mode;
	int				is_hd;
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

typedef struct s_ast
{
	t_type			type;
	union
	{
		char		**argv;
		t_redir		*redir;
	};
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

typedef struct s_data
{
	t_ast			*ast;
	int				fd[2];
	int				pipein;
	t_arr			*wpids;
}					t_data;

typedef enum s_mode
{
	M_INTRACTIVE,
	M_EXECUTION
}					t_mode;
typedef struct s_mish
{
	t_arr			*envp;
	int				exit_status;
	char			cwd[PATH_MAX];
	t_mode			mode;
}					t_mish;

// this struct for buildin check and run used only on executor
typedef enum s_buildin
{
	B_UNKNOWN,
	B_CD,
	B_ECHO,
	B_ENV,
	B_EXIT,
	B_EXPORT,
	B_PWD,
	B_UNSET
}					t_buildin;

typedef struct s_iofd
{
	int				in;
	int				out;
}					t_iofd;

#endif
