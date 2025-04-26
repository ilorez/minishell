
#include <stdio.h>

int main(int ac, char **av, char **envp)
{
  int i = -1;
  (void)av, (void)ac;

  while (envp[++i])
    printf("[%d]=>%s\n", i, envp[i]);
  return (0);
}
