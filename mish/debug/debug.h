#ifndef T_DEBUG_H
# define T_DEBUG_H

# include "../includes/container.h"
# include <stdio.h>
void	print_token_type(t_token *token);
void	print_tokens(t_token *tk);
void	print_ast(t_ast *node, int level);
void arr_print_str_list(char **list);

// compoenents
t_ast *ex_exec(char *cmd);
t_ast *ex_subshell(t_ast *argast);
t_ast *ex_redir(char *file_name, int fd, int flags, t_ast *next_ast);
t_ast *ex_bi(t_type type, t_ast *left, t_ast *right);

// lists
t_ast *example_list_1();
t_ast *example_list_2();
t_ast *example_list_3();
t_ast *example_list_4();

#endif
