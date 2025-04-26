

#ifndef	HEADER_H
#define HEADER_H

#include <readline/readline.h>
#include <readline/history.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <aio.h>

#include "type.h"
#include "string.h"

void	ft_parse_line(char	*buffer);
void	ft_next_token(void);
t_token	ft_get_token(char *ptr);
cmd		*ft_parse_list(void);
cmd		*ft_parse_cmd(void);
cmd		*ft_new_node(t_token op,char *value, cmd *l, cmd *r);

// Helpers
void	ft_print_ast(cmd *node, int depth);
int	ft_strcmp(char *a, char *b);
int	ft_isspace(char c);

// Colors
#define RED "\e[31m"
#define GREEN "\e[32m"
#define BLUE "\e[36m"
#define RESET "\e[00m"
#define RED_BOLD "\e[31;01m"
#define GREEN_BOLD "\e[32;01m"
#define BLUE_BOLD "\e[36;01m"

#endif
