#include "conatainer.h"

//================================== is match ===========
static void	_skip_till(char *ptr, int *i, char stop);
static void	_skip_while(char *ptr, int *i, char *match);


int _is_match(t_arr *wild, char *name)
{
	int i;
	int j;
	char **parts;

	parts = (char **)wild->content;
	i = 0;
	j = 0;
	if (wild->index == 1 && parts[j][0] == '\0')
		return 0;
	while (name[i])
	{
		if (parts[j][0] == '\0' && j < wild->index)
			_skip_till(name, &i, parts[(j++) + 1][0]);
		if (name[i] == '\0' || name[i] != parts[j][0])
			return (1); // there is no match 
		_skip_while(name, &i, parts[j++]);
	}
	return (0);
}

static void	_skip_till(char *ptr, int *i, char stop)
{
	if (!ptr)
		return ;
	while (ptr[*i] && ptr[*i] != stop)
		(*i)++;
}

static void	_skip_while(char *ptr, int *i, char *match)
{
	if (!ptr)
		return ;
	while (ptr[*i] && ptr[*i] == *match++)
		(*i)++;
	
}
//=======================================================

