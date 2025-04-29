
#include "header.h"

cmd		*root;

int	main(void)
{
	char	*buffer;

	while (1)
	{
		buffer = readline("=> ");
		if (!buffer) break;
		if (*buffer)
			add_history(buffer);
		ft_parse_line(buffer);
		ft_print_ast(root->left, 0);
		// TODO: free all the root and buffer
	}
	return (0);
}

void	ft_parse_line(char *buffer)
{
	root = ft_new_node(ROOT, NULL, NULL, NULL);
	root->ptr = buffer;
	ft_next_token();
	root->left = ft_parse_list();
}

cmd	*ft_parse_list(void)
{
	cmd		*left;
	cmd		*right;
	t_token	token;

	left = ft_parse_cmd();
	while (root->curr_token.type == AND || root->curr_token.type == OR
			|| root->curr_token.type == PIPE)
	{
		token = root->curr_token.type;
		ft_next_token();
		right = ft_parse_cmd();
		left = ft_new_node(token, NULL, left, right);
	}
	return (left);
}

cmd	*ft_parse_cmd(void)
{
	cmd	*leaf;

	if (root->curr_token.type == LPARENT)
	{
		ft_next_token();
		leaf = ft_parse_list();
		if (root->curr_token.type != RPARENT)
		{
			printf("-Syntax err: unclosed \")\"\n");
			return (NULL);
		}
		ft_next_token();
		return (ft_new_node(LPARENT, NULL, leaf, NULL));
	}
	leaf = ft_new_node(WORD, root->curr_token.value, NULL, NULL);
	ft_next_token();
	return (leaf);
}

cmd	*ft_new_node(t_token op, char *value, cmd *l, cmd *r)
{
	cmd	*node;

	node = (cmd *)malloc(sizeof(cmd));
	if (!node)
		return (NULL); // TODO: free all
	node->token = op;
	node->value = value;
	node->left = l;
	node->right = r;
	return (node);
}

void	ft_next_token(void)
{
	char		*ptr;
	t_token		tt;
	t_string	*str;

	ptr = root->ptr;
	while (ft_isspace(*ptr))
		ptr++;
	tt = ft_get_token(ptr);
	root->curr_token.type = tt;
	if (tt == EOL)
		return ;
	if (tt == OR || tt == AND || tt == LESSL || tt == GREATG)
		ptr += 2;
	else if (tt != WORD)
		ptr++;
	else
	{
		str = ft_create_empty_str(10);
		while (*ptr && *ptr != '&' && *ptr != '|' && *ptr != ')')
			ft_string_append(str, *(ptr++));
		root->curr_token.value = str->value;
	}
	root->ptr = ptr;
}

t_token ft_get_token(char *ptr)
{
	if (!ptr || !*ptr)
		return EOL;
	if (ptr[0] == '&')
		return (AND * (ptr[1] == '&')) + (BACK * (ptr[1] != '&'));
	if (ptr[0] == '|')
		return (OR * (ptr[1] == '|')) + (PIPE * (ptr[1] != '|'));
	if (ptr[0] == '<')
		return (LESSL * (ptr[1] == '<')) + (LESS * (ptr[1] != '<'));
	if (ptr[0] == '>')
		return (GREATG * (ptr[1] == '>')) + (GREAT * (ptr[1] != '>'));
	if (ptr[0] == '(')
		return LPARENT;
	if (ptr[0] == ')')
		return RPARENT;
	if (ptr[0] == '\'')
		return SINGLE_Q;
	if (ptr[0] == '"')
		return DOUBLE_Q;
	return WORD;
}

