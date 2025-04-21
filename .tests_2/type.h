

#ifndef	TYPE_H
#define	TYPE_H

typedef enum	e_token{
	ROOT,
	WORD,
	AND,
	OR,
	PIPE,
	BACK,
	LESS,
	LESSL,
	GREAT,
	GREATG,
	LPARENT,
	RPARENT,
	SINGLE_Q,
	DOUBLE_Q,
	EOL
}	t_token;

typedef	struct	s_token{
	t_token	type;
	char	*value;
}	t_super_token;

typedef struct	s_cmd{
	t_token	token;
	char	*value;
	char	*ptr;
	t_super_token	curr_token;
	struct	s_cmd *left;
	struct	s_cmd *right;
}	cmd;

#endif
