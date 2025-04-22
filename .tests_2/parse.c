
#include "header.h"

#include <stdio.h>

void ft_print_ast(cmd *node, int depth) {
	if (!node)
		return;

	// Indent to show depth
	for (int i = 0; i < depth; i++)
		printf("  ");

	// Print basic node info
	printf("Node: token=%d", node->token);

	if (node->value)
		printf(", value='%s'", node->value);

	printf("\n");

	// Traverse children
	ft_print_ast(node->left, depth + 1);
	ft_print_ast(node->right, depth + 1);
}

static int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

int		ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(void)
{
	char	*buffer;

	while (1)
	{
		buffer = readline("=> ");
		ft_parse_line(buffer);
		ft_print_ast(root->left, 0);
		//TODO: free all the root and buffer
	}
	return	(0);	
}

void	ft_parse_line(char *buffer)
{
	root = ft_new_node(ROOT, NULL, NULL, NULL);
	root->ptr = buffer;
	ft_next_token();
	root->left = ft_parse_list();	
}

cmd		*ft_parse_list(void)
{
	cmd	*left;
	cmd	*right;
	t_token	token;

	left = ft_parse_cmd();
	while(root->curr_token.type == AND || root->curr_token.type == OR
		|| root->curr_token.type == PIPE)
	{
		token = root->curr_token.type;
		ft_next_token();
		right = ft_parse_cmd();
		left = ft_new_node(token, NULL, left, right);
	}
	return (left);
}

cmd		*ft_parse_cmd(void)
{
	cmd		*leaf;

	//if (root->curr_token.type == LPARENT) TODO:todo
	leaf = ft_new_node(WORD, root->curr_token.value, NULL, NULL);
	ft_next_token();
	return (leaf);
}

cmd		*ft_new_node(t_token op, char *value, cmd *l, cmd *r)
{
	cmd	*node;

	node = (cmd *)malloc(sizeof(cmd));
	if (!node)
		return (NULL);//TODO: free all 
	node->token = op;
	node->value = value;
	node->left = l;
	node->right = r;
	return (node);
}

void	ft_next_token(void)
{
	char	*ptr;
	t_string	*str;

	ptr = root->ptr;
	str = ft_create_empty_str(10);
	while (ft_isspace(*ptr)) ptr++;
	if (ft_strcmp(ptr, "exit") == 0)	exit(0);
	if (*ptr == '\0')
	{
		root->curr_token.type = EOL;
		return ;
	}
	if (ptr[0] == '|' && ptr[1] == '|')
	{
		root->curr_token.type = OR;
		ptr += 2;
	}
	else if (ptr[0] == '&' && ptr[1] == '&')
	{
		root->curr_token.type = AND;
		ptr += 2;
	}
	else if (ptr[0] == '|')
	{
		root->curr_token.type = PIPE;
		ptr++;
	}
	else if (ptr[0] == '(')
	{
		root->curr_token.type = LPARENT;
		ptr++;
	}
	else if (ptr[0] == ')')
	{
		root->curr_token.type = RPARENT;
		ptr++;
	}
	else
	{
		while (*ptr && *ptr != '&' && *ptr != '|')
			ft_string_append(str, *(ptr++));
		root->curr_token.type = WORD;
		root->curr_token.value = str->value;
	}
	root->ptr = ptr;
}
