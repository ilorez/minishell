/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:18:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/04/15 12:53:41 by znajdaou         ###   ########.fr       */
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

// this struct should change to handle this all this cases
// >file
// &>file
// >>file
// &>>file
// <file
// <<file
// [number]>file --> example: 2>file
// ...
typedef struct s_fd {
  enum {
    IN,
    OUT,
    HEREDOC
  } type;
  char *path;
} t_fd; // no not like that

// simple command
typedef struct s_simple_cmd {
	char *cmd;
	char **args;
  t_fd out; // default NULL
  char *in; // default NULL
} t_simple_cmd;

// complex command
typedef struct s_complex_cmd {
	t_type type;
	void *data; // t_simple_cmd | t_complex_cmd 
	t_relation relation;
	void *next;
} t_complex_cmd ;



// data container 
// Note: this is what will be passsed to execute function
typedef struct s_data {
	t_history *his;
	t_complex_cmd *cmds;
  t_env **vars;
  t_bool 
} t_data;
