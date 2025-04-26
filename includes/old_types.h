/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:18:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/15 18:53:53 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// boolean 
typedef enum s_bool {
  false,
  true
} t_bool;

// commands type
typedef enum s_type {
	SIMPLE,
	COMPLEX
} t_type;

// relations between commands
typedef enum s_relation {
  END,
  PIPE,
  OR,
  AND
} t_relation;

// history
typedef struct s_history {
	char **list; // last element is NULL
	int current_index;
	int size;
} t_history;

// env
typedef struct s_env {
  char *key;
  char *value;
} t_env;

// fd type
typedef struct s_fd {
  enum {
    IN,
    OUT,
    HEREDOC,
    OUTAPPEND
  } type;
  char *text; // path | EOF
} t_fd; //WARN: are we required to handel redirections like 
        // 2>file or &>file ... ?

// simple command
typedef struct s_simple_cmd {
	char *cmd;
	char **args;
  t_fd **fd_list; // those at begining and end of command with it's order
} t_simple_cmd;

// complex command
typedef struct s_complex_cmd {
	t_type type;
	void *data; // t_simple_cmd | t_complex_cmd 
	t_relation relation;
	void *next;
} t_complex_cmd ;

typedef struct s_prompt {
  char *prompt;
  char *path;
} t_prompt;

// data container 
// Note: this is what will be passsed to execute function
typedef struct s_data {
  t_prompt prompt;
	t_history *his;
	t_complex_cmd *cmds;
  t_env **vars;
  t_fd **fd_list; // those at begining and end of command with it's order
} t_data;
