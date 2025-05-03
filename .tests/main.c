#include "./includes/libft.h"
#include <stdio.h>

int main(void)
{
	// Create an empty dynamic string
	t_str *my_str = str_new_empty(5);
	if (!my_str)
	{
		printf("Failed to create empty string.\n");
		return (1);
	}

	// Append individual characters
	str_append(my_str, 'H');
	str_append(my_str, 'e');
	str_append(my_str, 'l');
	str_append(my_str, 'l');
	str_append(my_str, 'o');

	// Append a list of characters (string)
	str_append_list(my_str, ", world!");
	
	// Print the current value
	printf("String value: %s\n", my_str->value);

	// Extract value and destroy structure
	char *final = str_extract(&my_str);
	printf("Extracted value: %s\n", final);

	// Manually free extracted string
	free(final);

	// Test str_new
	t_str *from_content = str_new("Ignored because of bug");
	if (!from_content)
	{
		printf("Failed to create str_new.\n");
		return (1);
	}

	// Append a list and print
	str_append_list(from_content, ", Hello again!");
	printf("From str_new (after append): %s\n", from_content->value);

	// Clean and destroy
	str_clean(&from_content);
	if (!from_content)
		printf("Successfully cleaned up.\n");

	return 0;
}
