
#include "../includes/container.h"

void arr_print_str(t_arr *arr)
{
	if (!arr || !arr->content)
		return;

	for (int i = 0; i < arr->index; i++)
	{
		char *str = (char *)arr->content[i];
		if (str)
			printf("[%d]: %s\n", i, str);
		else
			printf("[%d]: (null)\n", i);
	}
}
