
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
  char *line;

  int i =0;
  while (i++ < 2)
  {
    line = readline("minish> ");
    printf("str:%s\n", line);
  }
  return (0);
}



