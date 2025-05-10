#include "../includes/container.h"

const char	*get_token_type_name(t_type type)
{
	switch (type)
	{
	case T_ROOT:
		return ("T_ROOT");
	case T_LPAR:
		return ("T_LPAR");
	case T_RPAR:
		return ("T_RPAR");
	case T_AND:
		return ("T_AND");
	case T_OR:
		return ("T_OR");
	case T_PIPE:
		return ("T_PIPE");
	case T_LESS:
		return ("T_LESS");
	case T_LLESS:
		return ("T_LLESS");
	case T_GREAT:
		return ("T_GREAT");
	case T_GGREAT:
		return ("T_GGREAT");
	case T_WORD:
		return ("T_WORD");
	case T_EOL:
		return ("T_EOL");
	default:
		return ("UNKNOWN");
	}
}

void	print_token_type(t_token *token)
{
	printf("Token Type: %s", get_token_type_name(token->type));
	if (token->type == T_WORD && token->word != NULL)
	{
		printf(" (str: %.*s)", (int)token->word->len, token->word->ptr);
	}
	printf("\n");
}

void	print_tokens(t_token *tk)
{
	while (tk)
	{
		print_token_type(tk);
		tk = tk->next;
	}
}
