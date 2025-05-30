
#include "header.h"



void	ft_print_ast(cmd *node, int depth)
{
	char *arr[]={
	"ROOT",
	"WORD",
	"AND",
	"OR",
	"PIPE",
	"BACK",
	"LESS",
	"LESSL",
	"GREAT",
	"GREATG",
	"LPARENT",
	"RPARENT",
	"SINGLE_Q",
	"DOUBLE_Q",
	"EOL"};

	if (!node)
		return ;
	// Indent to show depth
	for (int i = 0; i < depth; i++)
		printf("  ");
	// Print basic node info
	printf("Node->["GREEN"%s"RESET"]", arr[node->token]);
	if (node->value)
		printf(", value='%s'", node->value);
	printf("\n");
	// Traverse children
	ft_print_ast(node->left, depth + 1);
	ft_print_ast(node->right, depth + 1);
}

int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

